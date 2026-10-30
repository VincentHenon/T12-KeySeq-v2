const {app,BrowserWindow,ipcMain,dialog}=require('electron'); const {SerialPort}=require('serialport'); const fs=require('fs'); const path=require('path');
function win(){const w=new BrowserWindow({width:720,height:560,webPreferences:{preload:path.join(__dirname,'preload.js')}});w.loadFile('index.html')}
app.whenReady().then(win);
ipcMain.handle('ports',async()=>await SerialPort.list());
ipcMain.handle('dump',async(_,port)=>{const file=await dialog.showSaveDialog({defaultPath:'T12-backup.t12'});if(file.canceled)return;return await transfer(port,Buffer.from('T12DUMP\n'),null,file.filePath)});
ipcMain.handle('restore',async(_,port)=>{const file=await dialog.showOpenDialog({properties:['openFile'],filters:[{name:'T12 backup',extensions:['t12']}]});if(file.canceled)return;const data=fs.readFileSync(file.filePaths[0]);return await transfer(port,Buffer.from(`T12RESTORE ${data.length}\n`),data)});
function transfer(name,command,payload,out){return new Promise((resolve,reject)=>{let data=Buffer.alloc(0), sent=false, settled=false;
const p=new SerialPort({path:name,baudRate:115200},e=>{if(e&&!settled){settled=true;reject(e)}});
const finish=(err,result)=>{if(settled)return;settled=true;clearTimeout(timer);p.removeAllListeners('data');p.removeAllListeners('open');p.removeAllListeners('error');if(p.isOpen)p.close(()=>err?reject(err):resolve(result));else err?reject(err):resolve(result)};
const timer=setTimeout(()=>finish(new Error('Transfer timeout')),15000);
p.on('error',e=>finish(e));
p.on('data',d=>{if(settled)return;data=Buffer.concat([data,d]);if(payload&&!sent&&data.includes(Buffer.from('READY\n'))){sent=true;p.write(payload,e=>{if(e)finish(e)})}if(!payload&&data.length>=10){let n=data.readUInt32LE(6);if(data.length>=10+n+4){try{fs.writeFileSync(out,data.subarray(0,10+n+4));finish(null,'Backup saved')}catch(e){finish(e)}}}if(payload&&data.includes(Buffer.from('OK\n')))finish(null,'Restore complete')});
p.on('open',()=>p.write(command,e=>{if(e)finish(e)}));})}
