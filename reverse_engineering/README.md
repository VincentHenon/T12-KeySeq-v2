# Doboz T12 v20 UF2 reverse engineering

This folder contains analysis artifacts for the official Doboz T12 DIY v20 firmware UF2.

## Files

- `t12_doboz_v20.uf2`: original UF2 image used for analysis.
- `t12_doboz_v20_disassembly.txt`: ARM Thumb disassembly of the extracted XIP image.
- `t12_doboz_v20_decompiled.c`: Ghidra reconstructed pseudo-C for 731 discovered functions, including the PWM interrupt handler installed through a function pointer.
- `t12_doboz_v20_for_ghidra_exec.elf`: ELF wrapper with XIP base address `0x10000000` and reset vector entry for Ghidra.
- `ExportDecompiled.java`: Ghidra headless script used to export pseudo-C.
- `gpio_map_v20.md`: evidence-based GPIO map for the v20 firmware.

## Interpretation

The UF2 has no debug symbols or source paths. Function names, types, globals, class methods, and some control flow in the C export are inferred by Ghidra. It is reconstructed pseudo-C, not the original Arduino/C++ source. A few functions contain decompiler warnings where indirect control flow or C++ object construction could not be recovered. The PWM interrupt handler at `0x10003228` is a concrete example where the pseudo-C omits one of two writes to the PWM compare register; the disassembly at `0x1000324c` and `0x1000325e` shows both writes. Use the disassembly and hardware evidence alongside the pseudo-C when assigning GPIO roles.
