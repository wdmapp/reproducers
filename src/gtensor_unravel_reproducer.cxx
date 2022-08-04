#include "gtensor/gtensor.h"

int main(int argc, char *argv[]) {
  auto rhs = gt::empty_device<double>({256, 16, 24, 24, 24, 24});
  auto k_rhs = rhs.to_kernel();
  gt::launch<6>(
      rhs.shape(), GT_LAMBDA(int i, int j, int k, int l, int m, int n) {
        k_rhs(i, j, k, l, m, n) = 5.;
      });
  gt::synchronize();
  return 0;
}
