#ifndef SRC_CALC_H_
#define SRC_CALC_H_

typedef struct list_t {
  long double value;
  long double x;
  char oper;
  struct list_t* next;
  int type;
} list_t;

typedef enum {
  kValue=1,
  kX,
  kOper
} kType ;


/* list_t logic */

list_t * createList(long double value, long double x, char oper, int type);
int pushList(list_t**root, long double value, long double x, char oper, int type);
int pushValue(list_t** root, long double value);
int pushX(list_t** root, long double x);
int pushOper(list_t** root, char oper);
int freeList(list_t**root);

/* list_t stack implementation */


list_t * createStack(long double value, long double x, char oper, int type);
int pushStack(list_t** root, long double value, long double x, char oper, int type, int *nodesCount);
long double peekStack(list_t* root, int type);
long double peekXStack(list_t *root);
long double peekValueStack(list_t *root);
char peekOperStack(list_t *root);
long double popStack(list_t** root, int type);
long double popValueStack(list_t **root);
long double popXStack(list_t **root);
char popOperStack(list_t **root);

#endif // SRC_CALC_H_