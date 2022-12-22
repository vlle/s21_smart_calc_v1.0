#ifndef SRC_CALC_H_
#define SRC_CALC_H_

typedef struct list_t {
  long double value;
  long double x;
  char oper;
  struct list_t* next;
  int type;
} list_t;

typedef struct elem {
  long double a;
  long double b;
} elem_t;

typedef struct {
  long double total_payment;
  long double monthly_payment;
  long double overpayment;
  long double days_with_cred;
  long double annuity_coeff;
  long double total_credit_amount;
  long double term;
  long double interest_rate;
  long double diff_payment_part;
  long double percent_sum;
  long double remainder_credit;
  long double pay_percent;
  char type_credit;
} finance_t;

enum {

  TOTAL_CREDIT = 0,
  MONTHLY_PAYMENT,
  OVERPAYMENT,
  N_COLUMNS
};

typedef enum { kValue = 1, kX, kOper } kType;

/* list_t logic */

list_t* createList(long double value, long double x, char oper, int type);
int pushList(list_t** root, long double value, long double x, char oper,
             int type);
int pushValue(list_t** root, long double value);
int pushX(list_t** root, long double x);
int pushOper(list_t** root, char oper);
int freeList(list_t** root);
int printList(list_t* root);

/* list_t stack implementation */

list_t* createStack(long double value, long double x, char oper, int type);
int pushStack(list_t** root, long double value, long double x, char oper,
              int type, int* nodesCount);
long double peekStack(list_t* root, int type);
long double peekXStack(list_t* root);
long double peekValueStack(list_t* root);
char peekOperStack(list_t* root);
long double popStack(list_t** root, int type, int* nodesCount);
long double popValueStack(list_t** root, int* nodesCount);
long double popXStack(list_t** root, int* nodesCount);
char popOperStack(list_t** root, int* nodesCount);
int pushOperStack(list_t** root, char oper, int* nodesCount);
int pushXStack(list_t** root, long double x, int* nodesCount);
int pushValueStack(list_t** root, long double value, int* nodesCount);

/* calculation */

int calculate(const char* input, long double* val);
int calculate_x(const char* input, long double x, long double* val);
int infToRpn(const char* input, list_t** root, long double* x);
int pushAndPrint(list_t** stack, list_t** root, int* nodes_count,
                 char* priority);

void debug(list_t* root);
elem_t pop2Value(list_t** stack, int* nodes_count);

long double calculateRpn(list_t* root);
finance_t put_data(long double total_credit_amount, long double term,
                   long double interest_rate, char type,
                   long double days_with_cred);
finance_t credit_calculate(finance_t credit);

#endif  // SRC_CALC_H_
