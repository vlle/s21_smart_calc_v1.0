#include "smartcalc.h"
#include <stdio.h>


int main() {
  // list_t *root = {0};
  // long double a = 2.0;
  // long double b = 4.0;
  // printf("\n%Lf = a", a);
  // create_list(&root);
  // push_backValue(&root, &a);
  // root = root->next;
  // printf("\n%Lf = val", root->value);
  // push_backValue(&root, &b);
  // root = root->next;
  // printf("\n%Lf = val", root->value);
  // char f = 's';
  // push_backOperator(&root, &f);
  // root = root->next;
  // printf("%c", root->operator);
  printf("%Lf = val\n", calculate("2-2"));
}
