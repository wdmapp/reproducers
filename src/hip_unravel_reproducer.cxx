
#include <hip/hip_runtime.h>

#include <array>
#include <iostream>

__global__ void kernel(unsigned long ii, int* strides, int* p)
{
  if (threadIdx.x == 0) {
#if 1
    // broken (with -O2)
    int iii = ii;
    unsigned long i = iii;
#else
    // works
    unsigned long i = ii;
#endif
    int idx[6];
    for (int d = 6 - 1; d >= 0; d--) {
      idx[d] = strides[d] == 0 ? 0 : (i / strides[d]);
      i -= idx[d] * strides[d];
    }

    p[0] = idx[0];
    p[1] = idx[1];
    p[2] = idx[2];
    p[3] = idx[3];
    p[4] = idx[4];
    p[5] = idx[5];
  }
}

int main()
{
  std::array<int, 6> strides = {1, 70, 2240, 53760, 1290240, 41287680};
  std::array<int, 6> idx;
  hipLaunchKernelGGL(kernel, 1, 1, 0, 0, 29675519, strides.data(), idx.data());
  int rc = hipDeviceSynchronize();
  if (rc != 0)
    exit(1);
  std::cout << "idx " << idx[0] << " " << idx[1] << " " << idx[2] << " "
            << idx[3] << " " << idx[4] << " " << idx[5] << "\n";

  return 0;
}
