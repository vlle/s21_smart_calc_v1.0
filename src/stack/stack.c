#include <stdlib.h>
#include <stdio.h>

#include "../smartcalc.h"


struct stack* init_stack(int value) {
  math_stack *a = (math_stack*) malloc(sizeof(math_stack));
  a->storage = value;
  a->next = NULL;
  return a;
}

int push_back(int *nodesCount, struct Node **top, int oper) {
  struct Node* newNode = NULL;
  newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->storage = 10;
  if (top == NULL) {
    newNode->next = NULL;
    printf("%d = aaa\n", 0);
  } else {
    newNode->next = *top;
  }
  *top = newNode;
  *nodesCount += 1;
  printf("Node is Inserted\n\n");
  return 0;
}


int peek(struct Node *a) {
  return a->storage;
}

int pop(int *nodesCount, struct Node**top) {
  struct Node* node;
  if (IsEmpty(*top)) {
    printf("Top stack is empty");
  } else {
    int x = peek(nodesCount, *top)
    math_stack *tmp = top;
    oper = top->storage;
    top = tmp->next;
    free(tmp);
  }
  return 0;
}

int IsEmpty(struct Node *top) {
  return top == NULL;
}
// IsFull



int main() {
  struct Node *top;
  int nodesCount = 0;
  // top = init_stack(5);
  int a = 10, b = 20, c = 30;
  push_back(&nodesCount, &top, a);
  // top->storage++;
  printf("%d is top ", top->storage);
  // printf("%d", pop(top));
  return 0;
}
