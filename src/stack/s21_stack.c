#include <stdio.h>
#include <stdlib.h>

#include "../smartcalc.h"

int push_backN(int *nodesCount, struct Node **top, long double oper) {
  if (top == NULL) {
    fprintf(stderr, "null err\n");
    return 1;
  }
  struct Node *newNode = NULL;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->storage = oper;
  newNode->next = *top;
  *top = newNode;
  *nodesCount += 1;
  return 0;
}

int push_backC(int *nodesCount, struct Node **top, char oper) {
  if (top == NULL) {
    fprintf(stderr, "null err\n");
    return 1;
  }
  struct Node *newNode = NULL;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->res = oper;
  newNode->next = *top;
  *top = newNode;
  *nodesCount += 1;
  return 0;
}

long double peekN(struct Node *a) { return a->storage; }

char peekC(struct Node *a) { 
  char res;
  if (!a) {
    res = '?';
  } else {
    res = a->res;
  }
  return res; 
}

long double popN(int *nodesCount, struct Node **top) {
  long double x = 0;
  if (IsEmpty(*top)) {
    printf("Top stack is empty");
  } else {
    struct Node *node;
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
  if (IsEmpty(*top)) {
    printf("Top stack is empty");
  } else {
    struct Node *node;
    x = peekC(*top);
    node = *top;
    *top = (*top)->next;
    *nodesCount -= 1;
    free(node);
  }
  return x;
}

int IsEmpty(const struct Node *top) { return top == NULL; }

/* List functions below */

int create_list(list_t **root) {
  list_t *newNode = NULL;
  newNode = (list_t*) malloc(sizeof(list_t));
  int err_code = 0;
  if (newNode) {
    newNode->next = NULL;
    *root = newNode;
  } else {
    err_code = 1;
  }
  return err_code;
}

int push_backValue(list_t **root, long double value) {
  int err_code = 0;
  list_t *newNode = NULL;
  newNode = (list_t*) malloc(sizeof(list_t));
  if (newNode) {
    newNode->value = value;
    newNode->operator = 0;
    newNode->x = 0;
    newNode->next = NULL;
    while ((*root)->next != NULL) {
      *root = (*root)->next;
    }
    (*root)->next = newNode;
  } else{
    err_code = 1;
  }
  return err_code;
}











