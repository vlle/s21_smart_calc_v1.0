#include <stdlib.h>
#include <stdio.h>

#include "../smartcalc.h"


int init_stack(math_stack *a) {
  if (a) {
    a->storage = 0;
    a->next = NULL;
  }
  return 0;
}

int push_back(math_stack *top, int oper) {
  struct stack *newNode = (math_stack*) malloc(sizeof(math_stack));
  newNode->storage = 10;
  if (!top) {
    newNode->next = NULL;
  } else {
    newNode->next = top;
  }
  top = newNode;
  printf("Node is Inserted\n\n");
  return 0;
}

int pop(math_stack *top) {
  int oper = 0;
  if (!top) {
    printf("Top stack is empty");
  } else {
    math_stack *tmp = top;
    oper = top->storage;
    top = tmp->next;
    free(tmp);
  }
  return oper;
}

int peek(math_stack *a) {
  int oper = 0;
  return oper;
}

// IsEmpty
// IsFull



int main() {
  math_stack *top = NULL;
  int a = 10, b = 20, c = 30;
  push_back(top, a);
  // top->storage++;
  // printf("%d is top ", top->storage);
  printf("%d", pop(top));
  return 0;
}
