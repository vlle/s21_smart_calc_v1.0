#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../smartcalc.h"
#define MAX_INP_SZ 256

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
    if (*inpstr >= '0' && *inpstr <= '9') {
      char tmp[90];
      char *pEnd;
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
    if (*inpstr == '+') {
      push_backC(&nodesCount1, &opr, '+');
    } else if (*inpstr == '-') {
      push_backC(&nodesCount1, &opr, '-');
    } else if (*inpstr == '/') {
      push_backC(&nodesCount1, &opr, '/');
    } else if (*inpstr == '*') {
      push_backC(&nodesCount1, &opr, '*');
    } else if (*inpstr == 's') {
      char *null_prot = inpstr;
      // store check in func
      if ((*(null_prot + 1) != '\0') && (*(null_prot + 2) != '\0')) {
        if ((*(null_prot + 1) == 'i') && (*(null_prot + 2) == 'n')) {
          push_backC(&nodesCount1, &opr, 'S');
        }
      }
    }
  }
  int tmp = nodesCount1;
  funcstr_i = strlen(funcstr);
  while (tmp > 0) {
    funcstr[funcstr_i] = popC(&tmp, &opr); // peek for preceding op
    funcstr_i++;
    funcstr[funcstr_i] = ' ';
    funcstr_i++;
  }
  funcstr[funcstr_i] = '\0';
  free(start);
  return funcstr;
}

struct Vars popper(struct Node**nums, int *nodesCount) {
  struct Vars res;
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
  struct Node* operators;
  int nodesCount = 0;
  int a = 0, b = 0;
  long double a1 = 0, a2 = 0;
  int nodesCount1 = 0;
  struct Vars var;
  for (; *funcstr != '\0'; funcstr++) {
    if (*funcstr >= '0' && *funcstr <= '9') {
      char *pEnd;
      long double calc_num = strtol(funcstr, &pEnd, 10);
      push_backN(&nodesCount, &nums, calc_num);
      funcstr = pEnd;
    } else if (*funcstr == '+') {
      var = popper(&nums, &nodesCount);
      result = var.a2 + var.a1;
    } else if (*funcstr == '-') {
      var = popper(&nums, &nodesCount);
      result = var.a2 - var.a1;
    } else if (*funcstr == '*') {
      var = popper(&nums, &nodesCount);
      result = var.a2 * var.a1;
    } else if (*funcstr == '/') {
      var = popper(&nums, &nodesCount);
      result = var.a2 / var.a1;
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
