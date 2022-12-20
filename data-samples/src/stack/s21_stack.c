#include <stdio.h>
#include <stdlib.h>

#include "../smartcalc.h"

int push_backStack(int *nodesCount, struct Node **top, long double storage, char oper, int type) {
  if (top == NULL) {
    fprintf(stderr, "null err\n");
    return 1;
  }
  struct Node *newNode = NULL;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  if (type == 1) {
    newNode->storage = storage;
  } else {
    newNode->res = oper;

  }
  newNode->next = *top;
  *top = newNode;
  *nodesCount += 1;
  return 0;
}
int push_backN(int *nodesCount, struct Node **top, long double oper) {
  return push_backStack(nodesCount, top, oper, 0, 1);
}

int push_backC(int *nodesCount, struct Node **top, char oper) {
  return push_backStack(nodesCount, top, 0, oper, 2);
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

list_t* create_list(long double const value, char const operator, long double const x, int t) {
  list_t *newNode = malloc(sizeof(*newNode));
  if (newNode) {
    if (t == 1) {
      newNode->value = value;
      newNode->value_presence = 1;
    }
    if (t == 2) {
      newNode->operator = operator;;
      newNode->operator_presence = 1;;
    }
    if (t == 3) {
      newNode->x = x;
      newNode->x_presence = 1;
    }
    newNode->next = NULL;
  }
  return newNode;
}

void append(list_t **headRef, list_t *newNode) {
  list_t **tracer = headRef;
  while (*tracer) {
    tracer = &(*tracer)->next;
  }
  newNode->next = *tracer;
  *tracer = newNode;
}

int push_backList(list_t **roo, long double const value, char const  operator, long double const x, int t) {
  int err_code = 0;

  list_t* newNode = create_list(value, operator, x, t);
  append(roo, newNode);
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

int remove_all(list_t **root) {
  list_t * tmp;
  while ((tmp = *root)) {
    *root = tmp->next;
    free(tmp);
  }
  return 0;
}

int push_backValue(list_t **root, long double const value) {
  return push_backList(root, value, 0, 0, 1);
}

int push_backOperator(list_t **root, char const op) {
  return push_backList(root, 0, op, 0, 2);
}

int push_backX(list_t **root, long double const x) {
  return push_backList(root, 0, 0, x, 3);
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

