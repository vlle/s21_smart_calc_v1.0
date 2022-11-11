#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

#define HIGHPRIOR "*/"
#define LOWPRIOR "*/+-STC"

void push_and_print(char** funcstr, struct Node** opr, int* nodesCount,
                    char* prior_str) {
  int funcstr_i = strlen(*funcstr);
  while ((strchr(prior_str, peekC(*opr)) != NULL) & (*(nodesCount) > 0)) {
    char symb = popC(nodesCount, opr);
    if (symb == '(' || symb == ')') {
      continue;
    }
    (*funcstr)[funcstr_i++] = symb;  // peek for preceding op
    (*funcstr)[funcstr_i++] = ' ';
    if (*nodesCount == 0) break;
  }
}

char* parse_oper(char* funcstr, char* inpo) {
  struct Node* opr = {0};
  int nodesCount = 0;
  int funcstr_i = 0;
  char* inpstr = inpo;
  for (; *inpstr != '\0'; inpstr++) {
    if (*inpstr >= '0' && *inpstr <= '9') {
      char num_str[MAX_ENTRY_SIZE] = {0};
      char* pEnd;
      long double calc_num = strtold(inpstr, &pEnd);
      sprintf(num_str, "%Lf", calc_num);
      inpstr = pEnd;
      strcat(num_str, " ");
      strcat(funcstr, num_str);
    }
    /* Экспонента	^	4	Справа налево */

    if (*inpstr == '(') {
      push_backC(&nodesCount, &opr, '(');
    } else if (*inpstr == '+') {
      if (nodesCount > 0) {
        push_and_print(&funcstr, &opr, &nodesCount, LOWPRIOR);
      }
      push_backC(&nodesCount, &opr, '+');
    } else if (*inpstr == '-') {
      if (nodesCount > 0) {
        push_and_print(&funcstr, &opr, &nodesCount, LOWPRIOR);
      }
      push_backC(&nodesCount, &opr, '-');
    } else if (*inpstr == '/') {
      if (nodesCount > 0) {
        if (peekC(opr) != '+' && peekC(opr) != '-') {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
      }
      push_backC(&nodesCount, &opr, '/');
    } else if (*inpstr == '*') {
      if (nodesCount > 0) {
        if (peekC(opr) != '+' && peekC(opr) != '-') {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
      }
      push_backC(&nodesCount, &opr, '*');
    } else if (*inpstr == 's') {
      if (strncmp(inpstr, "sin", 3) == 0) {
        if (nodesCount > 0) {
          if (peekC(opr) != '+' && peekC(opr) != '-') {
            push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
          }
        }
        push_backC(&nodesCount, &opr, 'S');
      }
    } else if (*inpstr == 't') {
      if (strncmp(inpstr, "tan", 3) == 0) {
        if (nodesCount > 0) {
          if (peekC(opr) != '+' && peekC(opr) != '-') {
            push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
          }
        }
        push_backC(&nodesCount, &opr, 'T');
      }
    } else if (*inpstr == 'c') {
      if (strncmp(inpstr, "cos", 3) == 0) {
        if (nodesCount > 0) {
          if (peekC(opr) != '+' && peekC(opr) != '-') {
            push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
          }
        }
        push_backC(&nodesCount, &opr, 'C');
      }
    } else if (*inpstr == ')') {
      funcstr_i = strlen(funcstr);
      while (peekC(opr) != '(') {
        funcstr[funcstr_i++] =
          popC(&nodesCount, &opr);  // peek for preceding op
        funcstr[funcstr_i++] = ' ';
        if (nodesCount == 0) {
          perror("Wtf man");
        }
      }
      popC(&nodesCount, &opr);
    }
  }
  funcstr_i = strlen(funcstr);
  while (nodesCount > 0) {
    funcstr[funcstr_i++] = popC(&nodesCount, &opr);  // peek for preceding op
    funcstr[funcstr_i++] = ' ';
  }
  funcstr[funcstr_i] = '\0';
  return funcstr;
}

struct Vars popper(struct Node** nums, int* nodesCount) {
  struct Vars res = {0};
  if (*nodesCount > 1) {
    res.a1 = popN(nodesCount, nums);
    res.a2 = popN(nodesCount, nums);
  } else {
    while (*nodesCount > 0) {
      popN(nodesCount, nums);
    }
    fprintf(stderr, "Wrong calculation. Returning -1\n");
  }
  return res;
}

long double cal_oper(char* funcstr) {
  long double result = 0.0;
  struct Node* nums;
  int nodesCount = 0;
  struct Vars var;
  for (; *funcstr != '\0'; funcstr++) {
    if (*funcstr >= '0' && *funcstr <= '9') {
      char* pEnd;
      long double calc_num = strtold(funcstr, &pEnd);
      push_backN(&nodesCount, &nums, calc_num);
      funcstr = pEnd;
    } else if (*funcstr == '+') {
      var = popper(&nums, &nodesCount);
      result = var.a2 + var.a1;
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == '-') {
      var = popper(&nums, &nodesCount);
      result = var.a2 - var.a1;
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == '*') {
      var = popper(&nums, &nodesCount);
      result = var.a2 * var.a1;
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == '/') {
      var = popper(&nums, &nodesCount);
      result = var.a2 / var.a1;
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'S') {
      result = sin(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'T') {
      result = tan(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'C') {
      result = cos(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    }
  }
  while (nodesCount > 0) {
    popN(&nodesCount, &nums);
  }
  return result;
}
