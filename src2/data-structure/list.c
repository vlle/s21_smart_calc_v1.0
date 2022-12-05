#include "../calc.h"
#include <stdio.h>
#include <stdlib.h>

list_t * createList(long double value, long double x, char oper, int type) {
  list_t *root = malloc(sizeof(*root));
  if (root) {
    root->value = value;
    root->x = x;
    root->oper = oper;
    root->type = type;
    root->next = NULL;
    return root;
  } else {
    fprintf(stderr, "stack overflow");
    return NULL;
  }
}

int pushList(list_t**root, long double value, long double x, char oper, int type) {
  list_t *newNode = createList(value, x, oper, type);
  list_t *traversal = *root;
  while (traversal->next) {
    traversal = traversal->next;
  }
  traversal->next=newNode;
  return 0;
}

int freeList(list_t**root) {
  list_t *t = *root;
  list_t *n = t;
  while (n->next) {
    t = n->next;
    free(n);
    n = t;
  }
  free(n);
  return 0;
}

int pushValue(list_t** root, long double value) {
  return pushList(root, value, 0, 0, kValue);
}
int pushX(list_t** root, long double x) {
  return pushList(root, 0, x, 0, kX);
}
int pushOper(list_t** root, char oper) {
  return pushList(root, 0, 0, oper, kOper);
}
