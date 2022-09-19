#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../smartcalc.h"
#define MAX_INP_SZ 256

void strcat_c (char *str, char c) {
  for (;*str;str++); // note the terminating semicolon here. 
  *str++ = c; 
  *str++ = 0;
}

char* parse_oper(char* funcstr) {
  struct Node* opr;
  char *inpstr = (char*) malloc(MAX_INP_SZ);
  if (!inpstr) {
    fprintf(stderr, "No memory alloc. \n");
    perror("");
  }
  int nodesCount = 0;
  int nodesCount1 = 0;
  int funcstr_i = 0;
  fgets(inpstr, MAX_INP_SZ, stdin);
  char* start = inpstr;
  int numcount = 0;
  for (; *inpstr != '\0'; inpstr++) {
      printf("%c iS curr\n", *inpstr);
    if (*inpstr >= '0' && *inpstr <= '9') {
      char tmp[90];
      char *pEnd;
      long double calc_num = strtol(inpstr, &pEnd, 10);
      sprintf(tmp, "%.0Lf", calc_num);
      printf("%c iS curr\n", *inpstr);
      inpstr = pEnd;
      printf("%c iS curr\n", *inpstr);
      // strncat(funcstr, tmp, strlen(tmp));
      strcat(funcstr, tmp);
      strcat(funcstr, " ");
      numcount++;
      // store in funciton?
      // while num parse
      // TODO(artemii): error handling
    } 
    if (*inpstr == '+') {
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
  funcstr_i = strlen(funcstr);
  while (tmp > 0) {
    printf("%d is tmp\n", tmp);
    funcstr[funcstr_i] = popC(&tmp, &opr); // peek for preceding op
    funcstr_i++;
    funcstr[funcstr_i] = ' ';
    funcstr_i++;
  }
  funcstr[funcstr_i] = '\0';
  free(start);
  return funcstr;
}

long double cal_oper(char* funcstr) {
  long double result = 0.0;
  struct Node* nums;
  struct Node* operators;
  int nodesCount = 0;
  int nodesCount1 = 0;
  for (; *funcstr != '\0'; funcstr++) {
    if (*funcstr >= '0' && *funcstr <= '9') {
      char *pEnd;
      long double calc_num = strtol(funcstr, &pEnd, 10);
      push_backN(&nodesCount, &nums, calc_num);
      funcstr = pEnd;
    } else if (*funcstr == '+') {
      if (nodesCount > 1) {
      int a = popN(&nodesCount, &nums);
      int b = popN(&nodesCount, &nums);
      result = a + b;
      } else {
        result = -1;
        while (nodesCount) {
          popN(&nodesCount, &nums);
        }
        fprintf(stderr, "Wrong calculation. Returning -1\n");
      }
    }
  }
  return result;
}

int main() {
  char funcstr[400] = {0};
  char *go;
  go = parse_oper(funcstr);
  printf("%s", go);
  long double res = 0;
  res = cal_oper(go);
  printf("\n%Lf", res);
  return 0;
}
