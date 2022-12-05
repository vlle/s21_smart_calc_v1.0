#include "../smartcalc.h"
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

int pushValueStack(list_t ** root, long double value, int*nodesCount) {
  return pushStack(root, value, 0, 0, kValue, nodesCount);
}

int pushXStack(list_t ** root, long double x, int*nodesCount) {
  return pushStack(root, 0, x, 0, kX, nodesCount);
}

int pushOperStack(list_t ** root, char oper, int*nodesCount) {
  return pushStack(root, 0, 0, oper, kOper, nodesCount);
}

int pushStack(list_t** root, long double value, long double x, char oper, int type, int *nodesCount) {
  list_t *newNode = createStack(value, x, oper, type);
  if (root && newNode) {
    newNode->next = *root;
    *root = newNode;
    *nodesCount+=1;
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

long double popStack(list_t** root, int type, int*nodesCount) {
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
    *nodesCount -= 1;
  }
  return retval;
}

long double popValueStack(list_t **root, int*nodesCount) {
  return popStack(root, kValue, nodesCount);
}

long double popXStack(list_t **root, int*nodesCount) {
  return popStack(root, kX, nodesCount);
}

char popOperStack(list_t **root, int*nodesCount) {
  return (char) popStack(root, kOper, nodesCount);
}
