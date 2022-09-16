#include <stdio.h>
#include <stdlib.h>

#include "../smartcalc.h"

int push_backN(int *nodesCount, struct Node **top, int oper) {
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

int push_backC(int *nodesCount, struct Node **top, char oper) {
  struct Node *newNode = NULL;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->res = oper;
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

int peekN(struct Node *a) { return a->storage; }

char peekC(struct Node *a) { return a->res; }

int popN(int *nodesCount, struct Node **top) {
  int x = -1;
  struct Node *node;
  if (IsEmpty(*top)) {
    printf("Top stack is empty");
  } else {
    x = peekN(*top);
    node = *top;
    *top = (*top)->next;
    *nodesCount -= 1;
    free(node);
  }
  return x;
}

char popC(int *nodesCount, struct Node **top) {
  char x = 0;
  struct Node *node;
  if (IsEmpty(*top)) {
    printf("Top stack is empty");
  } else {
    x = peekC(*top);
    node = *top;
    *top = (*top)->next;
    *nodesCount -= 1;
    free(node);
  }
  return x;
}

int IsEmpty(struct Node *top) { return top == NULL; }
// IsFull
