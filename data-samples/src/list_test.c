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
  long double f;
  calculate("2", &f);
  printf("%Lf = val\n", f);
  calculate("0.270949*sin(0.718059)-cos(0.027278)+acos(0.675124)+asin(0.399085)", &f);
  printf("%Lf = sval\n", f);
  calculate("2/1", &f);
  printf("%Lf 2= val\n", f);
  calculate("2/0", &f);
  printf("%Lf ?= val\n", f);
}