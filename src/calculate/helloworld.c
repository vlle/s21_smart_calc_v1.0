#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../smartcalc.h"


char* parse_oper(char* inpstr, char* funcstr) {
  struct Node* opr;
  int nodesCount = 0;
  int nodesCount1 = 0;
  int funcstr_i = 0;
  scanf("%s", inpstr);
  // for (int i = 0; i < strlen(inpstr); i++) {
  for (; *inpstr != '\0'; inpstr++) {
    if (*inpstr >= '0' && *inpstr <= '9') {
      char tmp[90];
      //funcstr[funcstr_i] = inpstr[i];
      //funcstr_i++;
      //funcstr[funcstr_i] = ' ';
      //funcstr_i++;
      // while num parse
    } else if (*inpstr == '+') {
      push_backC(&nodesCount1, &opr, '+');
    } else if (*inpstr == '-') {
      push_backC(&nodesCount1, &opr, '-');
    } else if (*inpstr == '/') {
      push_backC(&nodesCount1, &opr, '/');
    } else if (*inpstr == '*') {
      push_backC(&nodesCount1, &opr, '*');
    }
  }
  int tmp = nodesCount1;
  while (tmp > 0) {
    funcstr[funcstr_i] = popC(&tmp, &opr);
    funcstr_i++;
    funcstr[funcstr_i] = ' ';
    funcstr_i++;
  }
  // printf("%s", funcstr);
  funcstr[funcstr_i] = '\0';
  return funcstr;
}

long double cal_oper(char* funcstr) {
  long double result = 0.0;
  struct Node* nums;
  struct Node* ops;
  int nodesCount = 0;
  int nodesCount1 = 0;
  for (int i = 0; i < strlen(funcstr); i++) {
    if (funcstr[i] >= '0' && funcstr[i] <= '9') {
      push_backN(&nodesCount, &nums, funcstr[i] - 48);
    } else if (funcstr[i] == '+') {
      int a = popN(&nodesCount, &nums);
      int b = popN(&nodesCount, &nums);
      result = a + b;
    }
  }
  return result;
}

int main() {
  char inpstr[100];
  char funcstr[400];
  char *go;
  go = parse_oper(inpstr, funcstr);
  printf("%s", go);
  long double res = cal_oper(go);
  printf("%Lf", res);
  return 0;
}
