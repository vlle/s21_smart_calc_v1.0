#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_
#define MAX_ENTRY_SIZE 256

typedef enum {
  minus,
  plus,
  multiply,
  divide,
  sinus,
  cosinus,
  tangengs,
  etc
} math_oper;

struct Node {
  long double storage;  // integer data
  char res;
  struct Node *next;  // pointer to the next node
};

struct Vars {
  long double a1;
  long double a2;
};

// Stack functions

long double popN(int *nodesCount, struct Node **top);
char popC(int *nodesCount, struct Node **top);
int push_backC(int *nodesCount, struct Node **top, char oper);
int push_backN(int *nodesCount, struct Node **top, long double oper);
long double peekN(struct Node *a);
char peekC(struct Node *a);
int IsEmpty(struct Node *top);

long double cal_oper(char *funcstr);
char *parse_oper(char *funcstr, char *inpo);

#endif
