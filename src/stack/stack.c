#include <stdlib.h>
#include <stdio.h>

#include "../smartcalc.h"


struct stack* init_stack(int value) {
  math_stack *a = (math_stack*) malloc(sizeof(math_stack));
  a->storage = value;
  a->next = NULL;
  return a;
}

int push_back(math_stack *top, int oper) {
  struct stack *newNode = (math_stack*) malloc(sizeof(math_stack));
  newNode->storage = 10;
  if (top == NULL) {
    newNode->next = NULL;
    printf("%d = aaa\n", 0);
  } else {
    newNode->next = top;
  }
  top = newNode;
  printf("%d = aaa\n", top->storage);
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
  struct stack *top;
  top = init_stack(5);
  int a = 10, b = 20, c = 30;
  push_back(top, a);
  // top->storage++;
  printf("%d is top ", top->storage);
  printf("%d", pop(top));
  return 0;
}
