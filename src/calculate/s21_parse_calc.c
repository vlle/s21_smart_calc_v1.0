#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"
#define MAX_INP_SZ 256


void push_and_print(char** funcstr, struct Node** opr, int* nodesCount1, int prior) {
  char symb = {0};
  int funcstr_i = strlen(*funcstr);
  if (prior == 2) {
    while ((peekC(*opr) == '*' || peekC(*opr) == '-' || peekC(*opr) == '+' || peekC(*opr) == '/') \
      & (*(nodesCount1) > 0)) {
        symb = popC(&(*nodesCount1), &(*opr));
        if (symb == '(' || symb == ')') {
          continue;
        }
        (*funcstr)[funcstr_i++] = symb;  // peek for preceding op
        (*funcstr)[funcstr_i++] = ' ';
      }
  } else if (prior == 3) {
    while ((peekC(*opr) == '*' || peekC(*opr) == '/') \
      & (*(nodesCount1) > 0)) {
        symb = popC(&(*nodesCount1), &(*opr));
        if (symb == '(' || symb == ')') {
          continue;
        }
        (*funcstr)[funcstr_i++] = symb;  // peek for preceding op
        (*funcstr)[funcstr_i++] = ' ';
      }
  }
}

char* parse_oper(char* funcstr, char* inpo) {
  struct Node* opr;
  int nodesCount1 = 0;
  int funcstr_i = 0;
  char* inpstr = inpo;
  for (; *inpstr != '\0'; inpstr++) {
    if (*inpstr >= '0' && *inpstr <= '9') {
      char num_str[90];
      char* pEnd;
      long double calc_num = strtold(inpstr, &pEnd);
      sprintf(num_str, "%.2Lf", calc_num);
      inpstr = pEnd;
      strcat(funcstr, num_str);
      strcat(funcstr, " ");
    }
    // While there is an token-operator O2 at the top of the stack, that has
    // greater precedence than O1 or they have the same precedence and O1 is
    // left-associative: Pop O2 from the stack into the output queue Push O1
    // onto the stack

    /* Экспонента	^	4	Справа налево
         Умножение	*	3	Слева направо
         Разделение	/	3	Слева направо
         Добавление	+	2	Слева направо
         вычитание	—	2	Слева направо */
    if (*inpstr == '(') {
      push_backC(&nodesCount1, &opr, '(');
    } else if (*inpstr == '+') {
      if (nodesCount1 > 0) {
        push_and_print(&funcstr, &opr, &nodesCount1, 2);
      }
      push_backC(&nodesCount1, &opr, '+');
    } else if (*inpstr == '-') {
      if (nodesCount1 > 0) {
        push_and_print(&funcstr, &opr, &nodesCount1, 2);
      }
      push_backC(&nodesCount1, &opr, '-');
    } else if (*inpstr == '/') {
      if (nodesCount1 > 0) {
        push_and_print(&funcstr, &opr, &nodesCount1, 3);
      }
      push_backC(&nodesCount1, &opr, '/');
    } else if (*inpstr == '*') {
      if (nodesCount1 > 0) {
        char cmpr = peekC(opr);
        if (cmpr == '+' || cmpr == '-') {
          push_backC(&nodesCount1, &opr, '*');
        } else {
          push_and_print(&funcstr, &opr, &nodesCount1, 3);
          push_backC(&nodesCount1, &opr, '*');
        }
      } else {
        push_backC(&nodesCount1, &opr, '*');
      }
    } else if (*inpstr == 's') {
      char* null_prot = inpstr;
      if ((*(null_prot + 1) != '\0') && (*(null_prot + 2) != '\0')) {
        if ((*(null_prot + 1) == 'i') && (*(null_prot + 2) == 'n')) {
          push_backC(&nodesCount1, &opr, 'S');
        }
      }
    } else if (*inpstr == ')') {
      char* brc = (char*)malloc(nodesCount1 + 2);
      char k = peekC(opr);
      while (peekC(opr) != '(') {
        k = popC(&nodesCount1, &opr);
        brc[0] = k;
        brc[1] = ' ';
        strcat(funcstr, brc);
      }
      free(brc);
    }
  }
  funcstr_i = strlen(funcstr);
  while (nodesCount1 > 0) {
    funcstr[funcstr_i++] = popC(&nodesCount1, &opr);  // peek for preceding op
    funcstr[funcstr_i++] = ' ';
  }
  funcstr[funcstr_i] = '\0';
  // printf("%s is functsr\n", funcstr);
  return funcstr;
}

struct Vars popper(struct Node** nums, int* nodesCount) {
  struct Vars res = {0};
  if (*nodesCount > 1) {
    res.a1 = popN(nodesCount, nums);
    res.a2 = popN(nodesCount, nums);
  } else {
    while (nodesCount) {
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
    }
  }
  while (nodesCount > 0) {
    popN(&nodesCount, &nums);
  }
  return result;
}

