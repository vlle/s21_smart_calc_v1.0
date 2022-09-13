#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

typedef struct stack
{
    int top;
    int *next;
} math_stack;

// Stack functions

int init_stack(math_stack *a);
int peek(math_stack *a);
int pop(math_stack *a);
int push_back(math_stack *a, int oper);










#endif
