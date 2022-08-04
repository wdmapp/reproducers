# gtensor examples

## cmake

See [CMakeLists.txt](CMakeLists.txt) and [cmake/CPM.cmake](cmake/CPM.cmake) as examples
of setting up a simple project that uses gtensor.

## gtensor_unravel_reproducer

Reproduce bug seen with ROCm 5.2.0 with -O2 and per dim kernels off (default).

See
- [kernel_launch_N](https://github.com/wdmapp/gtensor/blob/main/include/gtensor/gtensor.h#L305)
- [unravel](https://github.com/wdmapp/gtensor/blob/main/include/gtensor/strides.h#L29)
- [index_expression](https://github.com/wdmapp/gtensor/blob/main/include/gtensor/expression.h#L110)
