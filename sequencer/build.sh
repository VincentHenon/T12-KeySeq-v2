#!/bin/bash
set -euo pipefail
project_root="$(cd -- "$(dirname -- "$0")/.." && pwd)"
sdk_path="${PICO_SDK_PATH:-$HOME/pico/pico-sdk}"
toolchain_path="${PICO_TOOLCHAIN_PATH:-$HOME/.pico-sdk/toolchain/14_2_Rel1}"
args=(-S "$project_root/sequencer" -B "$project_root/build/sequencer-native" "-DPICO_SDK_PATH=$sdk_path" -DCMAKE_BUILD_TYPE=Release)
if [[ -d "$toolchain_path" ]]; then args+=("-DPICO_TOOLCHAIN_PATH=$toolchain_path"); fi
cmake "${args[@]}"
cmake --build "$project_root/build/sequencer-native" --parallel 6
cp "$project_root/build/sequencer-native/t12_sequencer.uf2" "$project_root/T12_Sequencer_MVP_v0.1.2.uf2"
