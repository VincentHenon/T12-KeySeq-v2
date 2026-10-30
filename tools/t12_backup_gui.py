#!/usr/bin/env python3
import struct, tkinter as tk, glob, time
from tkinter import ttk, filedialog, messagebox
try:
    import serial, serial.tools.list_ports
except ImportError:
    serial = None

MAGIC=b'T12K'; VERSION=1; HEADER=struct.Struct('<IHI')
class App(tk.Tk):
    def __init__(self):
        super().__init__(); self.title('Doboz T12 Backup'); self.geometry('560x360'); self.minsize(560,360)
        self.withdraw()
        self.port=tk.StringVar(); self.status=tk.StringVar(value='Déconnecté')
        f=tk.Frame(self,padx=12,pady=12); f.pack(fill='both',expand=True)
        tk.Label(f,text='État USB',font=('Helvetica',16,'bold')).pack(anchor='w')
        self.port_status=tk.Label(f,text='● Recherche du T12…',anchor='w',font=('Helvetica',14,'bold')); self.port_status.pack(fill='x',pady=(4,12))
        tk.Label(f,text='Port USB série').pack(anchor='w')
        self.combo=ttk.Combobox(f,textvariable=self.port,width=35, state='normal'); self.combo.pack(fill='x',pady=4)
        tk.Label(f,text='Tu peux aussi saisir un port, par exemple /dev/cu.usbmodem2101.').pack(anchor='w')
        tk.Button(f,text='Rafraîchir / vérifier',command=self.refresh,width=24).pack(anchor='w')
        self.progress=ttk.Progressbar(f,maximum=100,mode='determinate'); self.progress.pack(fill='x',pady=5)
        self.dump_button=tk.Button(f,text='DUMP TO COMPUTER',command=self.dump,width=26); self.dump_button.pack(anchor='center',pady=12)
        self.restore_button=tk.Button(f,text='DUMP FROM COMPUTER',command=self.restore,width=26); self.restore_button.pack(anchor='center')
        tk.Label(f,textvariable=self.status).pack(pady=12)
        self.refresh()
        self.deiconify(); self.lift(); self.focus_force()
    def refresh(self):
        if serial is None: self.status.set('Installe pyserial : python3 -m pip install pyserial'); return
        ports=[p.device for p in serial.tools.list_ports.comports()]
        ports.extend(glob.glob('/dev/cu.usbmodem*'))
        ports=list(dict.fromkeys(ports))
        self.combo['values']=ports
        usb=[p for p in ports if 'usbmodem' in p.lower() or 'usbserial' in p.lower()]
        if usb: self.port.set(usb[0])
        elif ports: self.port.set(ports[0])
        found=self.port.get()
        self.port_status.config(text=('✓ Port actif : '+found) if found else '✗ Aucun port USB détecté')
        if not found:
            self.status.set('Branche le T12 puis clique Rafraîchir'); return
        try:
            with serial.Serial(found,115200,timeout=0.2): pass
            self.status.set('USB connecté au T12')
            self.port_status.config(text='● CONNECTÉ : '+found,fg='#16803c')
        except Exception:
            self.status.set('Port détecté mais occupé ou indisponible')
            self.port_status.config(text='● NON DISPONIBLE : '+found,fg='#b52b27')
    def animate(self,label):
        self.status.set(label); self.progress['value']=0; self.dump_button.config(state='disabled'); self.restore_button.config(state='disabled')
        for i in range(31):
            self.progress['value']=i*3.33; self.update_idletasks(); time.sleep(.1)
    def done(self, text):
        self.progress['value']=100; self.dump_button.config(state='normal'); self.restore_button.config(state='normal'); self.status.set('✓ '+text)
    def open(self): return serial.Serial(self.port.get(),115200,timeout=2)
    def dump(self):
        if serial is None: return
        path=filedialog.asksaveasfilename(defaultextension='.t12',filetypes=[('T12 backup','*.t12')])
        if not path:return
        try:
            self.animate('Téléchargement du dump…')
            with self.open() as s:
                s.reset_input_buffer(); s.write(b'T12DUMP\n'); s.flush()
                header=s.read(HEADER.size)
                while len(header)==HEADER.size and header[:4] != MAGIC:
                    header=header[1:]+s.read(1)
                if len(header)!=HEADER.size or header[:4]!=MAGIC: raise RuntimeError('Réponse T12 invalide')
                _, version, size=HEADER.unpack(header)
                if version != VERSION or size > 4096: raise RuntimeError('Version ou taille invalide')
                body=s.read(size+4)
                if len(body)!=size+4: raise RuntimeError('Dump incomplet')
                data=header+body
            open(path,'wb').write(data); self.done('Dump réussi : '+path)
        except Exception as e: self.done('Dump échoué'); messagebox.showerror('Dump impossible',str(e))
    def restore(self):
        if serial is None:return
        path=filedialog.askopenfilename(filetypes=[('T12 backup','*.t12')])
        if not path:return
        try:
            self.animate('Envoi du dump vers le T12…')
            data=open(path,'rb').read()
            if not data.startswith(MAGIC): raise RuntimeError('Fichier .t12 invalide')
            with self.open() as s:
                s.reset_input_buffer(); s.write(b'T12RESTORE '+str(len(data)).encode()+b'\n'); s.flush()
                if s.read_until(b'READY\n') != b'READY\n': raise RuntimeError('T12 non prêt')
                s.write(data); s.flush()
                reply=s.read_until(b'OK\n')
            if b'OK\n' not in reply: raise RuntimeError('Le T12 a refusé le fichier')
            self.done('Restauration réussie')
        except Exception as e: self.done('Restauration échouée'); messagebox.showerror('Restauration impossible',str(e))
if __name__=='__main__': App().mainloop()
