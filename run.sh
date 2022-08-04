#!/bin/bash

set -eu

CXX=$(which hipcc) cmake -S . -B  build-hip \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCXX_FLAGS_RELWITHDEBINFO="-g -O2 -NDEBUG -DGT_BOUNDSCHECK" \
  -DHIP_GPU_ARCHITECTURES=gfx1030
cmake --build build-hip -v
./build-hip/gtensor_unravel_reproducer
