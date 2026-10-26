#!/bin/bash
set -euo pipefail
project_root="$(cd -- "$(dirname -- "$0")/.." && pwd)"
test_dir="$(mktemp -d "${TMPDIR:-/tmp}/t12-tests.XXXXXX")"
trap 'rm -rf "$test_dir"' EXIT
cd "$project_root"
compiler="${CXX:-c++}"
flags=(-std=c++20 -Wall -Wextra -Werror -fsanitize=address,undefined -g -Isequencer/src)
"$compiler" "${flags[@]}" sequencer/src/model.cpp sequencer/src/engine.cpp sequencer/tests/engine_tests.cpp -o "$test_dir/engine"
"$test_dir/engine"
"$compiler" "${flags[@]}" sequencer/src/model.cpp sequencer/src/engine.cpp sequencer/src/ui.cpp sequencer/src/graphics.cpp sequencer/tests/ui_tests.cpp -o "$test_dir/ui"
"$test_dir/ui"
