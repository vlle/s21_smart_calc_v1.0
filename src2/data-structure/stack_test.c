#include "../calc.h"
#include <stdio.h>

int main() {
  list_t * base = createStack(0,0,0,kValue);
  int a = 1;
  pushValueStack(&base, 0.4, &a);
  printf("%Lf\n", peekValueStack(base));
  pushValueStack(&base, 0.8, &a);
  printf("%Lf\n", peekValueStack(base));
  popValueStack(&base);
  printf("%Lf\n", peekValueStack(base));
  printf("%d")
}
