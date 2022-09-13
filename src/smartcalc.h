#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

typedef enum {
    minus,
    plus,
    multiply,
    divide,
    sinus,
    cosinus,
    tangengs,
    etc
} math_oper ;

typedef struct stack
{
    int storage;
    struct stack *next;
} math_stack;

// Stack functions

int init_stack(math_stack *a);
int peek(math_stack *a);
int pop(math_stack *a);
int push_back(math_stack *a, int oper);










#endif
