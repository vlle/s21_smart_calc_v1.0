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

list_t* create_list() {
  list_t *newNode = (list_t*) malloc(sizeof(list_t));
  if (newNode) {
    newNode->next = NULL;
    newNode->value_presence = 0;
    newNode->operator_presence = 0;
    newNode->x_presence = 0;
  }
  return newNode;
}

int push_backList(list_t *roo, long double const value, int f, char const  operator, int f1, long double const x, int f2) {
  int err_code = 0;
  list_t *root = roo;

  while (root->next != NULL) {
    root = root->next;
  }
  root->next = (list_t*) malloc(sizeof(list_t));
  if (f) {
    root->next->value = value;
    root->next->value_presence = 1;
  }
  if (f1) {
    root->next->operator = operator;;
    root->next->operator_presence = 1;;
  }
  if (f2) {
    root->next->x = x;
    root->next->x_presence = 1;
  }
  root->next->next = NULL;
  return err_code;
}

int list_count(list_t *root) {
  int cnt = 1;
  list_t *v = root;
  while (v != NULL) {
    v = v->next;
    cnt++;
  }
  return cnt;
}

int remove_last(list_t *root) {
  int retval = 0;
  if (root->next == NULL) {
    free(root);
    return retval;
  } else {
    list_t * current = root;
    while (current->next->next != NULL) {
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
  }
  return retval;
}

int remove_all(list_t *root) {
  list_t *q;
  for (list_t *p = root; p != NULL; p = q) {
    q = p->next;
    free(p);
  }
  return 0;
}

int push_backValue(list_t *root, long double const value) {
  return push_backList(root, value, 1, 0, 0, 0, 0);
}

int push_backOperator(list_t *root, char const op) {
  return push_backList(root, 0,0, op, 1, 0,0);
}

int push_backX(list_t *root, long double const x) {
  return push_backList(root, 0,0, 0,0, x, 1);
}

int print_list(list_t *roo) {
  int cnt = 1;
  list_t *root = roo;
  while (root != NULL) {
    if (root->operator_presence == 1) {
      printf(" %c ", root->operator);
    }
    if (root->value_presence == 1) {
      printf(" %Lf ", root->value);
    }
    if (root->x_presence == 1){
      printf(" %Lf ", root->x);
    }
    root = root->next;
    cnt++;
  }
  return cnt;
}

