#include <stdio.h>
#include <stdlib.h>

#include "../smartcalc.h"

int push_back(int *nodesCount, struct Node **top, int oper) {
  struct Node *newNode = NULL;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->storage = oper;
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

int peek(struct Node *a) { return a->storage; }

int pop(int *nodesCount, struct Node **top) {
  int x = -1;
  struct Node *node;
  if (IsEmpty(*top)) {
    printf("Top stack is empty");
  } else {
    x = peek(*top);
    node = *top;
    *top = (*top)->next;
    *nodesCount -= 1;
    free(node);
  }
  return x;
}

int IsEmpty(struct Node *top) { return top == NULL; }
// IsFull

int main() {
  struct Node *top;
  int nodesCount = 0;
  push_back(&nodesCount, &top, 30);
  push_back(&nodesCount, &top, 32);
  push_back(&nodesCount, &top, 35);
  printf("%d\n", pop(&nodesCount, &top));
  printf("%d\n", pop(&nodesCount, &top));
  printf("%d\n", pop(&nodesCount, &top));
  return 0;
}
