#include <iostream>

#define GT_BOUNDSCHECK
#include "gtensor/gtensor.h"

int main(int argc, char *argv[]) {
  auto rhs = gt::empty_device<double>({32, 16, 24, 24, 24, 24});
  auto k_rhs = rhs.to_kernel();
  // NOTE: with the default option of GTENSOR_PER_DIM_KERNELS=OFF, this will do
  // a 1d kernel launch an "unravel" the 1d value into 6d to pass in to the
  // passed functor
  gt::launch<6>(
      rhs.shape(), GT_LAMBDA(int i, int j, int k, int l, int m, int n) {
        k_rhs(i, j, k, l, m, n) = 5.;
      });
  gt::synchronize();
  std::cout << "PASS" << std::endl;
  return 0;
}
