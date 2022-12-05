#include "calc.h"
#include <stdio.h>

int main() {
  printf("\n");
  printf("\n%Lf = res\n", calculate("2 + 2 "));
  printf("\n");
  printf("\n");
  printf("\n%Lf = res\n", calculate("2 - 2 "));
  printf("\n");
  printf("\n");
  printf("\n%Lf = res\n", calculate("2 / 2 "));
  printf("\n");
  printf("\n");
  printf("\n%Lf = res\n", calculate("3*sin(1) - (4) - 1 "));
  printf("\n");
  printf("\n");
  printf("\n%Lf = res\n", calculate("sin(1)"));
  printf("\n");
  return 0;
}
