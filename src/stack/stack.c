#include <stdlib.h>

#include "../smartcalc.h"


int init_stack(math_stack *a) {
  if (a) {
    a->top = 0;
    a->next = NULL;
  }
  return 0;
}

int peek(math_stack *a) {
  int oper = 0;
  return oper;
}

// IsEmpty
// IsFull

int pop(math_stack *a) {
  int oper = 0;
  return oper;
}

int push_back(math_stack *a, int oper) {
  oper = 1;
  return 0;
}

int main() {
  return 0;
}
