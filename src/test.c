#include <stdio.h>
#include <stdlib.h>

#include "smartcalc.h"

int main() {
  long double *values = calculate_x("sin(x)", -1, 1);
  for (int i = 0; i < sizeof(values); i++) {
    printf("%Lf ", values[i]);
  }
  printf("\n");
  free(values);
}
