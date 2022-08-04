#!/bin/bash

set -eu

ARCHS=${HIP_GPU_ARCHITECTURES:=gfx906a:xnack+}

CXX=$(which hipcc) cmake -S . -B  build-hip-o2 \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_CXX_FLAGS_RELWITHDEBINFO="-g -O2 -DNDEBUG" \
  -DHIP_GPU_ARCHITECTURES=$ARCHS
cmake --build build-hip-o2 -v
CXX=$(which hipcc) cmake -S . -B  build-hip-o1 \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_CXX_FLAGS_RELWITHDEBINFO="-g -O1 -DNDEBUG" \
  -DHIP_GPU_ARCHITECTURES=$ARCHS
cmake --build build-hip-o1 -v

echo "Running -O1 build..."
./build-hip-o1/gtensor_unravel_reproducer
echo "Running -O2 build..."
./build-hip-o2/gtensor_unravel_reproducer
