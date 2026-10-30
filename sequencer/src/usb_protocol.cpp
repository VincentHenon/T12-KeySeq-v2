#include "usb_protocol.hpp"
#include "pico/stdlib.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
namespace t12::usbproto {
namespace {
constexpr uint32_t Magic = 0x4B323154; // T12K, little endian
constexpr uint16_t Version = 1;
struct __attribute__((packed)) Header { uint32_t magic; uint16_t version; uint32_t size; };
struct Payload { Project project; Settings settings; };
// Payload used before v0.1.49 added gate/length/variant fields to Step.
struct LegacyStep { uint8_t key; int8_t time; uint8_t retrigger, glide, vibrato, ratchet; int8_t shift; };
struct LegacyProject {
  char name[17]; LegacyStep steps[Steps]; uint8_t notes[Keys];
  uint8_t length, scale, root, loopLength, loopOffset; int8_t transpose;
};
struct LegacyPayload { LegacyProject project; Settings settings; };
static_assert(sizeof(Payload) < 2048);
uint32_t crc32(const uint8_t *p, size_t n) { uint32_t c=~0u; while(n--) { c^=*p++; for(int i=0;i<8;++i) c=(c>>1)^(0xEDB88320u&uint32_t(-int(c&1))); } return ~c; }
char line[32]{}; unsigned lineLen=0; uint32_t remaining=0; uint8_t rx[sizeof(Header)+sizeof(Payload)+4]{}; unsigned rxLen=0;
void dump(const Project &p, const Settings &s) {
  Payload payload{p,s}; Header h{Magic,Version,uint32_t(sizeof payload)}; uint32_t crc=crc32(reinterpret_cast<const uint8_t*>(&payload),sizeof payload);
  std::fwrite(&h,1,sizeof h,stdout); std::fwrite(&payload,1,sizeof payload,stdout); std::fwrite(&crc,1,sizeof crc,stdout); std::fflush(stdout);
}
void finishRestore(Project &p, Settings &s) {
  if(rxLen != remaining) { std::printf("ERR SIZE\n"); return; }
  Header h{}; std::memcpy(&h,rx,sizeof h); uint32_t fileCrc{};
  std::memcpy(&fileCrc,rx+sizeof h+h.size,4);
  if(h.magic!=Magic || h.version!=Version || h.size > sizeof(Payload) ||
     h.size < sizeof(LegacyPayload) || crc32(rx+sizeof h,h.size)!=fileCrc) { std::printf("ERR VALID\n"); return; }
  Payload payload{};
  if (h.size == sizeof(Payload)) {
    std::memcpy(&payload, rx + sizeof h, sizeof payload);
  } else if (h.size == sizeof(LegacyPayload)) {
    LegacyPayload old{}; std::memcpy(&old, rx + sizeof h, sizeof old);
    std::memcpy(payload.project.name, old.project.name, sizeof payload.project.name);
    for (unsigned i=0; i<Steps; ++i) {
      payload.project.steps[i].key = old.project.steps[i].key;
      payload.project.steps[i].time = old.project.steps[i].time;
      payload.project.steps[i].retrigger = old.project.steps[i].retrigger;
      payload.project.steps[i].glide = old.project.steps[i].glide;
      payload.project.steps[i].vibrato = old.project.steps[i].vibrato;
      payload.project.steps[i].ratchet = old.project.steps[i].ratchet;
      payload.project.steps[i].shift = old.project.steps[i].shift;
    }
    std::memcpy(payload.project.notes, old.project.notes, sizeof payload.project.notes);
    payload.project.length=old.project.length; payload.project.scale=old.project.scale;
    payload.project.root=old.project.root; payload.project.loopLength=old.project.loopLength;
    payload.project.loopOffset=old.project.loopOffset; payload.project.transpose=old.project.transpose;
    payload.settings = old.settings;
  } else { std::printf("ERR SIZE\n"); return; }
  if(!valid(payload.project) || !valid(payload.settings)) { std::printf("ERR VALID\n"); return; }
  if(!storage::saveProject(0,payload.project) || !storage::saveSettings(payload.settings)) { std::printf("ERR FLASH\n"); return; }
  p=payload.project; s=payload.settings; std::printf("OK\n");
}
}
void service(Project &p, Settings &s) {
  int ch; while((ch=stdio_getchar_timeout_us(0))!=PICO_ERROR_TIMEOUT) {
    if(remaining) { if(rxLen < sizeof rx) rx[rxLen++]=uint8_t(ch); if(--remaining==0) { unsigned total=rxLen; remaining=total; finishRestore(p,s); remaining=0; rxLen=0; } continue; }
    if(ch=='\n') { line[lineLen]=0; if(!std::strcmp(line,"T12DUMP")) dump(p,s); else if(!std::strncmp(line,"T12RESTORE ",11)) { unsigned n=std::strtoul(line+11,nullptr,10); if(n==sizeof(Header)+sizeof(Payload)+4 || n==sizeof(Header)+sizeof(LegacyPayload)+4) { remaining=n; rxLen=0; std::printf("READY\n"); } else std::printf("ERR SIZE\n"); } lineLen=0; }
    else if(lineLen+1<sizeof line) line[lineLen++]=char(ch); else lineLen=0;
  }
}
}
