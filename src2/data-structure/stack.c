#include "../calc.h"
#include <stdlib.h>
#include <stdio.h>

list_t * createStack(long double value, long double x, char oper, int type) {
  list_t *root = malloc(sizeof(*root));
  if (root) {
    root->value = value;
    root->x = x;
    root->oper = oper;
    root->type = type;
    root->next = NULL;
    return root;
  } else {
    fprintf(stderr, "stack overflow");
    return NULL;
  }
}

int pushStack(list_t** root, long double value, long double x, char oper, int type, int *nodesCount) {
  list_t *newNode = createStack(value, x, oper, type);
  if (root && newNode) {
    newNode->next = *root;
    *root = newNode;
  } else {
    return -1;
  }
  return 0;
}

long double peekStack(list_t* root, int type) {
  long double retval = 0;
  if (root) {
    if (type == kValue) {
      retval = root->value;
    } else if (type == kX) {
      retval = root->x;
    } else if (type == kOper) {
      retval = root->oper;
    }
  }
  return retval;
}

long double peekXStack(list_t *root) {
  return peekStack(root, kX);
}
long double peekValueStack(list_t *root) {
  return peekStack(root, kValue);
}
char peekOperStack(list_t *root) {
  return peekStack(root, kOper);
}

long double popStack(list_t** root, int type) {
  long double retval = 0;
  if (root) {
    if (type == kValue) {
      retval = peekValueStack(*root);
    } else if (type == kX) {
      retval = peekXStack(*root);
    } else if (type == kOper) {
      retval = peekOperStack(*root);
    }
    list_t *to_free = *root;
    *root = (*root)->next;
    free(to_free);
  }
  return retval;
}

long double popValueStack(list_t **root) {
  return popStack(root, kValue);
}

long double popXStack(list_t **root) {
  return popStack(root, kX);
}

char popOperStack(list_t **root) {
  return (char) popStack(root, kOper);
}
