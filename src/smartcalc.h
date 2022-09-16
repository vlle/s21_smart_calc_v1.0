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
} math_oper;

struct Node {
  int storage;        // integer data
  struct Node *next;  // pointer to the next node
};

// Stack functions

int peek(struct Node *a);
int pop(int *nodesCount, struct Node **a);
int push_back(int *nodesCount, struct Node **a, int oper);
int IsEmpty(struct Node *top);

#endif
