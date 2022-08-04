# gtensor examples

## cmake

See [CMakeLists.txt](CMakeLists.txt) and [cmake/CPM.cmake](cmake/CPM.cmake) as examples
of setting up a simple project that uses gtensor.

## gtensor_unravel_reproducer

Reproduce bug seen with ROCm 5.2.0, -O2, and per dim kernels off (default).
On machine with ROCm installed and supported gpu, run like this:
```bash
export ROCM_PATH=/opt/rocm
export HIP_GPU_ARCHITECTURES=gfx803,gfx906,gfx908,gfx90a:xnack+,gfx1030
./run-unravel-reproducer.sh
```
Tested and reproduced with gfx1030 and gfx90a:xnack+.

For related gtensor code, see:
- [kernel_launch_N](https://github.com/wdmapp/gtensor/blob/main/include/gtensor/gtensor.h#L305)
- [unravel](https://github.com/wdmapp/gtensor/blob/main/include/gtensor/strides.h#L29)
- [index_expression](https://github.com/wdmapp/gtensor/blob/main/include/gtensor/expression.h#L110)
