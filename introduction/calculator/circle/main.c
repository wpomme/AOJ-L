#include <stdio.h>
#include <math.h>

int main() {
  double n;
  scanf("%lf", &n);

  printf("%lf %lf\n", n * n * M_PI, 2 * n * M_PI);
}
