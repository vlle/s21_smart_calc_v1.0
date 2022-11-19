#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_
#define MAX_ENTRY_SIZE 256

#define ZOOM_X 100.0
#define ZOOM_Y 100.0

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

enum {

  TOTAL_CREDIT = 0,
  MONTHLY_PAYMENT,
  OVERPAYMENT,
  N_COLUMNS
};

struct Node {
  long double storage;  // integer data
  char res;
  struct Node *next;  // pointer to the next node
};

struct Vars {
  long double a1;
  long double a2;
};

typedef struct {
  long double total_payment;
  long double monthly_payment;
  long double overpayment;
} finance_info;

// Stack functions

long double popN(int *nodesCount, struct Node **top);
char popC(int *nodesCount, struct Node **top);
int push_backC(int *nodesCount, struct Node **top, char oper);
int push_backN(int *nodesCount, struct Node **top, long double oper);
long double peekN(struct Node *a);
char peekC(struct Node *a);
int IsEmpty(const struct Node *top);

// Calculate function

long double cal_oper(char *funcstr);
char *parse_oper(char *funcstr, const char *inpo);
long double calculate(char* b);
finance_info credit_calculate(long double total_credit_amount, long double term,
                              long double interest_rate, char type);
// int deposit_calculate(long double total_credit_amount, long double term,
//                      long double interest_rate);

#endif
