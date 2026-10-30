#include "storage.hpp"
#include "hardware/flash.h"
#include "hardware/sync.h"
#include "pico/flash.h"
#include "pico/stdlib.h"
#include <algorithm>
#include <cstring>
namespace t12::storage {
namespace {
// Conservative 2 MiB flash boundary. Never write past a chip's reported size.
constexpr uint32_t FlashBytes = 2 * 1024 * 1024, Sector = 4096,
                   Base = FlashBytes - (Slots + 1) * 2 * Sector;
constexpr uint32_t Magic = 0x54313253, Version = 10;
struct Header {
  uint32_t magic, version, generation, size, crc;
};
static_assert(sizeof(Project) + sizeof(Header) < Sector);
static_assert(sizeof(Settings) + sizeof(Header) < Sector);
extern "C" char __flash_binary_end;
bool ready = false;
alignas(4) uint8_t staging[Sector];
uint32_t crc(const uint8_t *data, size_t n) {
  uint32_t c = ~0u;
  while (n--) {
    c ^= *data++;
    for (int i = 0; i < 8; ++i)
      c = (c >> 1) ^ (0xEDB88320u & uint32_t(-int(c & 1)));
  }
  return ~c;
}
uint32_t checksum(Header h, const uint8_t *payload) {
  // Cover generation/length as well as payload, so a damaged header cannot
  // supersede the previous good copy after a power loss.
  h.crc = 0;
  uint8_t all[sizeof(Header) + sizeof(Project) + sizeof(Settings)]{};
  std::memcpy(all, &h, sizeof h);
  std::memcpy(all + sizeof h, payload, h.size);
  return crc(all, sizeof h + h.size);
}
const uint8_t *ptr(unsigned index, unsigned bank) {
  return reinterpret_cast<const uint8_t *>(XIP_BASE + Base +
                                           (index * 2 + bank) * Sector);
}
bool inspect(unsigned index, unsigned bank, size_t size, Header &h) {
  std::memcpy(&h, ptr(index, bank), sizeof h);
  return h.magic == Magic && h.version == Version && h.size == size &&
         h.crc == checksum(h, ptr(index, bank) + sizeof h);
}
int newest(unsigned index, size_t size, Header &h) {
  Header a{}, b{};
  bool va = inspect(index, 0, size, a), vb = inspect(index, 1, size, b);
  if (!va && !vb)
    return -1;
  int bank = vb && (!va || int32_t(b.generation - a.generation) > 0) ? 1 : 0;
  h = bank ? b : a;
  return bank;
}
struct Write {
  uint32_t offset;
};
void program(void *context) {
  auto offset = static_cast<Write *>(context)->offset;
  flash_range_erase(offset, Sector);
  flash_range_program(offset, staging, Sector);
}
bool store(unsigned index, const void *payload, size_t size) {
  if (!ready)
    return false;
  Header old{};
  int bank = newest(index, size, old);
  unsigned target = bank == 0 ? 1 : 0;
  Header h{Magic, Version, bank < 0 ? 1u : old.generation + 1, uint32_t(size),
           0};
  std::memset(staging, 0xFF, sizeof staging);
  std::memcpy(staging + sizeof h, payload, size);
  h.crc = checksum(h, staging + sizeof h);
  std::memcpy(staging, &h, sizeof h);
  Write w{Base + (index * 2 + target) * Sector};
  if (flash_safe_execute(program, &w, 1000) != PICO_OK)
    return false;
  return std::memcmp(ptr(index, target), staging, Sector) == 0;
}
template <class T> bool load(unsigned index, T &output) {
  if (!ready)
    return false;
  Header h{};
  int bank = newest(index, sizeof(T), h);
  if (bank < 0)
    return false;
  T candidate{};
  std::memcpy(&candidate, ptr(index, bank) + sizeof h, sizeof candidate);
  if (!valid(candidate))
    return false;
  output = candidate;
  return true;
}
} // namespace
void init() {
  uint8_t tx[4] = {0x9F, 0, 0, 0}, rx[4]{};
  auto mask = save_and_disable_interrupts();
  flash_do_cmd(tx, rx, 4);
  restore_interrupts(mask);
  // JEDEC capacity exponent 21 means 2 MiB. Reject absent/unknown flash.
  ready = rx[1] != 0xFF && rx[1] != 0 && rx[3] >= 21 && rx[3] <= 30 &&
          reinterpret_cast<uintptr_t>(&__flash_binary_end) < XIP_BASE + Base;
}
bool available() { return ready; }
bool loadProject(unsigned slot, Project &p) {
  return slot < Slots && load(slot, p);
}
bool saveProject(unsigned slot, const Project &p) {
  return slot < Slots && valid(p) && store(slot, &p, sizeof p);
}
bool clearProject(unsigned slot) {
  Project empty{};
  return saveProject(slot, empty);
}
bool loadSettings(Settings &s) { return load(Slots, s); }
bool saveSettings(const Settings &s) {
  return valid(s) && store(Slots, &s, sizeof s);
}
} // namespace t12::storage
