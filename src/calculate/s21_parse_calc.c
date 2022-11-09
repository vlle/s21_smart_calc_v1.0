#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"
#define MAX_INP_SZ 256

char* parse_oper(char* funcstr, char* inpo) {
  struct Node* opr;
  // char* inpstr = (char*)malloc(MAX_INP_SZ);
  // if (!inpstr) {
  //   fprintf(stderr, "No memory alloc. \n");
  //   perror("");
  // }
  int nodesCount1 = 0;
  int funcstr_i = 0;
  // fgets(inpstr, MAX_INP_SZ, stdin);
  char* inpstr = inpo;
  int numcount = 0;
  for (; *inpstr != '\0'; inpstr++) {
    // printf("curr=%s\n",funcstr);
    //   number *= 10;
    //   number += (*inpstr - '0');
    if (*inpstr >= '0' && *inpstr <= '9') {
      char tmp[90];
      char* pEnd;
      long double calc_num = strtol(inpstr, &pEnd, 10);
      sprintf(tmp, "%.0Lf", calc_num);
      inpstr = pEnd;
      // strncat(funcstr, tmp, strlen(tmp));
      strcat(funcstr, tmp);
      strcat(funcstr, " ");
      numcount++;
      // store in funciton?
      // while num parse
      // TODO(Artemii): minus num support
      // TODO(artemii): error handling
      // TODO(artemii): float num spo=port
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
        char cmpr = peekC(opr);
        funcstr_i = strlen(funcstr);
        while ((cmpr == '*' || cmpr == '-' || cmpr == '+' || cmpr == '/') & (nodesCount1 > 0)) {
            cmpr = popC(&nodesCount1, &opr);
            if (cmpr == '(' || cmpr == ')') {
              continue;
            }
            funcstr[funcstr_i++] = cmpr;  // peek for preceding op
            funcstr[funcstr_i++] = ' ';
            printf("%s\n", funcstr);
          }
      }
      push_backC(&nodesCount1, &opr, '+');
    } else if (*inpstr == '-') {
      if (nodesCount1 > 0) {
        char cmpr = peekC(opr);
        funcstr_i = strlen(funcstr);
        while ((cmpr == '*' || cmpr == '-' || cmpr == '+' || cmpr == '/') & (nodesCount1 > 0)) {
            cmpr = popC(&nodesCount1, &opr);
            if (cmpr == '(' || cmpr == ')') {
              continue;
            }
            funcstr[funcstr_i++] = cmpr;  // peek for preceding op
            funcstr[funcstr_i++] = ' ';
            printf("%s\n", funcstr);
          }
      }
      push_backC(&nodesCount1, &opr, '-');
    } else if (*inpstr == '/') {
      push_backC(&nodesCount1, &opr, '/');
    } else if (*inpstr == '*') {
      if (nodesCount1 > 0) {
        char cmpr = peekC(opr);
        if (cmpr == '+' || cmpr == '-') {
          push_backC(&nodesCount1, &opr, '*');
        } else {
          funcstr_i = strlen(funcstr);
          while ((cmpr != '+' && cmpr != '-') && (nodesCount1 > 0)) {
            cmpr = popC(&nodesCount1, &opr);
            if (cmpr == '(' || cmpr == ')') {
              continue;
            }
            funcstr[funcstr_i++] = cmpr;  // peek for preceding op
            funcstr[funcstr_i++] = ' ';
            printf("%s\n", funcstr);
          }
          push_backC(&nodesCount1, &opr, '*');
        }
      } else {
        push_backC(&nodesCount1, &opr, '*');
      }
    } else if (*inpstr == 's') {
      char* null_prot = inpstr;
      // store check in func
      if ((*(null_prot + 1) != '\0') && (*(null_prot + 2) != '\0')) {
        if ((*(null_prot + 1) == 'i') && (*(null_prot + 2) == 'n')) {
          push_backC(&nodesCount1, &opr, 'S');
        }
      }
    } else if (*inpstr == ')') {
      char* tmp = (char*)malloc(nodesCount1 + 2);
      char k = '1';
      while (k != '(') {
        k = popC(&nodesCount1, &opr);
        if (k == '(') break;
        tmp[0] = k;
        tmp[1] = ' ';
        strcat(funcstr, tmp);
      }
      free(tmp);
    }
  }
  funcstr_i = strlen(funcstr);
  while (nodesCount1 > 0) {
    funcstr[funcstr_i++] = popC(&nodesCount1, &opr);  // peek for preceding op
    funcstr[funcstr_i++] = ' ';
  }
  funcstr[funcstr_i] = '\0';
  // free(start);
  printf("%s is functsr\n", funcstr);
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
      long double calc_num = strtol(funcstr, &pEnd, 10);
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
  // for (; *funcstr != '\0'; funcstr++) {
  //   if (*funcstr >= '0' && *funcstr <= '9') {
  //     char* pEnd;
  //     long double calc_num = strtol(funcstr, &pEnd, 10);
  //     push_backN(&nodesCount, &nums, calc_num);
  //     funcstr = pEnd;
  //   // } else if (*funcstr == '+') {
  //   //   // var = popper(&nums, &nodesCount);
  //   //   // result = var.a2 + var.a1;
  //   // } else if (*funcstr == '-') {
  //   //   // var = popper(&nums, &nodesCount);
  //   //   // result = var.a2 - var.a1;
  //   // } else if (*funcstr == '*') {
  //   //   // var = popper(&nums, &nodesCount);
  //   //   // result = var.a2 * var.a1;
  //   } else if (*funcstr == '/') {
  //     a = popN(&nodesCount, &nums);
  //     b = popN(&nodesCount, &nums);
  //     result = b / a;
  //     push_backN(&nodesCount, &nums, result);
  //   //   // var = popper(&nums, &nodesCount);
  //   //   // result = var.a2 / var.a1;
  //   }
  // }
  // return result;
}

// int main() {
//   char funcstr[40] = {0};
//   char b[100] = "2 + (11 - 1)";
//   double res = 12;
//   char *prs = parse_oper(funcstr, b);
//   printf("%s", prs);
//   double my_res = cal_oper(prs);
//   printf("\n%d", res == my_res);
//   // ck_assert_double_eq(res, my_res);
//   return 0;
// }

