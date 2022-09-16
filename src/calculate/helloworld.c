#include <stdio.h>
#include <string.h>

#include "../smartcalc.h"


void parse_oper() {
  struct Node* num;
  struct Node* opr;
  int nodesCount = 0;
  int nodesCount1 = 0;
  char what[100];
  char res[400];
  int res_i = 0;
  scanf("%s", what);
  for (int i = 0; i < strlen(what); i++) {
    if (what[i] >= '0' && what[i] <= '9') {
      res[res_i] = what[i];
      res_i++;
      res[res_i] = ' ';
      res_i++;
    } else if (what[i] == '+') {
      push_backC(&nodesCount1, &opr, '+');
    }
  }
  int tmp = nodesCount1;
  while (tmp > 0) {
    res[res_i] = popC(&tmp, &opr);
    res_i++;
    res[res_i] = ' ';
    res_i++;
  }
  printf("%s", res);
}

int main() {
  parse_oper();
  return 0;
}
