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
    newNode->value_presence = 0;
    newNode->operator_presence = 0;
    newNode->x_presence = 0;
    *root = newNode;
  } else {
    err_code = 1;
  }
  return err_code;
}

int push_backList(list_t *roo, const long double *value, const char* operator, const long double *x) {
  int err_code = 0;
  list_t *newNode = NULL;
  newNode = (list_t*) malloc(sizeof(list_t));

  list_t *root = roo;
  if (newNode) {
    if (value) {
      newNode->value = *value;
      newNode->value_presence = 1;
    }
    if (operator) {
      newNode->operator = *operator;;
      newNode->operator_presence = 1;;
    }
    if (x) {
      newNode->x = *x;
      newNode->x_presence = 1;
    }
    newNode->next = NULL;

    while (root->next != NULL) {
      root = root->next;
    }
    root->next = newNode;
  } else{
    err_code = 1;
  }
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
  while (root->next != NULL) {
    remove_last(root);
  }
  free(root);
  return 0;
}

int push_backValue(list_t *root, const long double *value) {
  return push_backList(root, value, NULL, NULL);
}

int push_backOperator(list_t *root, const char*op) {
  return push_backList(root, NULL, op, NULL);
}

int push_backX(list_t *root, const long double *x) {
  return push_backList(root, NULL, NULL, x);
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

