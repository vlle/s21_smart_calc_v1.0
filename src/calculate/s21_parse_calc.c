#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

#define SUPREME "~"
#define VERYHIGH "~^"
#define HIGHPRIOR "^*/STCstc%Llv~"  // ^
#define LOWPRIOR "^*/+-stcSTC%Ll~v"
#define ALL "()^*/+-stcSTC%Llv~"

/* These functions are for support.

  CheckNodesPrior checks top of the stack to see, if there's any operator with
  same or greater precedence than given.

  push_and_print pushes all operators than greater or same predence than given.
*/

int checkNodesPrior(int nodesCount, struct Node* opr, char* prior_str) {
  if (nodesCount > 0) {
    if (strchr(prior_str, peekC(opr)) != NULL) {
      return 1;
    }
  }
  return 0;
}

void push_and_print(list_t* funcstr, struct Node** opr, int* nodesCount,
                    char* prior_str) {
  while ((strchr(prior_str, peekC(*opr)) != NULL) & (*(nodesCount) > 0)) {
    char symb = popC(nodesCount, opr);
    if (symb == '(' || symb == ')') {
      continue;
    }
    push_backOperator(funcstr, symb);
    if (*nodesCount == 0) break;
  }
}

/* This function parses INFIX string and create RPN string
   Algo: Parse nums, parse OPs (and check priority), parse Trigonometry func */

int parse_oper(list_t *funcstr, const char* inpo) {
  struct Node* opr = {0};
  int nodesCount = 0;
  char* inpstr = (char*) inpo;
  int len = strlen(inpo);
  int i = 0;
  for (; ((*inpstr != '\0') & (len >= i)); inpstr++) {
    if (*inpstr >= '0' && *inpstr <= '9') {
      char* pEnd;
      long double calc_num = strtold(inpstr, &pEnd);
      inpstr = pEnd;
      push_backValue(funcstr, calc_num);
      printf("%Lf\n", calc_num);
      if (nodesCount >= 1) {
        if (peekC(opr) == '-') {
          char u = '-';
          push_backOperator(funcstr, u);
          popC(&nodesCount, &opr); /* peek for preceding op */
        }
      }
      if (nodesCount >= 1) {
        push_and_print(funcstr, &opr, &nodesCount, SUPREME);
      }
    }

    if (*inpstr == '(') {
      push_backC(&nodesCount, &opr, '(');
    } else if (*inpstr == '+') {
      if (nodesCount > 0) {
        push_and_print(funcstr, &opr, &nodesCount, LOWPRIOR);
      }
      push_backC(&nodesCount, &opr, '+');
    } else if (*inpstr == '-') {
      char* tp = inpstr-1;
      char tmp = *tp;
      if ((i == 0) || ((i>1) && (tmp != ')') && (strchr(ALL, tmp) != NULL))) {
        if (nodesCount > 0) {
          push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
        }
        push_backC(&nodesCount, &opr, '~');
      } else {
        if (nodesCount > 0) {
          push_and_print(funcstr, &opr, &nodesCount, LOWPRIOR);
        }
        push_backC(&nodesCount, &opr, '-');
      }
    } else if (*inpstr == '/') {
      if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
        push_and_print(funcstr, &opr, &nodesCount, HIGHPRIOR);
      }
      push_backC(&nodesCount, &opr, '/');
    } else if (*inpstr == '*') {
      if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
        push_and_print(funcstr, &opr, &nodesCount, HIGHPRIOR);
      }
      push_backC(&nodesCount, &opr, '*');
    } else if (*inpstr == '^') {
      if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
        push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
      }
      push_backC(&nodesCount, &opr, '^');
    } else if ((*inpstr == 's') & (strncmp(inpstr, "sin", 3) == 0)) {
      if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
        push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
      }
      push_backC(&nodesCount, &opr, 's');
    } else if (*inpstr == 't') {
      if (strncmp(inpstr, "tan", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
          push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
        }
        push_backC(&nodesCount, &opr, 't');
      }
    } else if ((*inpstr == 's') && (strncmp(inpstr, "sqrt", 4) == 0)) {
      if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
        push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
      }
      push_backC(&nodesCount, &opr, 'v');
    } else if (*inpstr == 'c') {
      if (strncmp(inpstr, "cos", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
          push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
        }
        push_backC(&nodesCount, &opr, 'c');
      }
    } else if (*inpstr == 'a') {
      inpstr += 1;
      if (*inpstr == 's') {
        if (strncmp(inpstr, "sin", 3) == 0) {
          if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
            push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
          }
          push_backC(&nodesCount, &opr, 'S');
        }
      } else if (*inpstr == 't') {
        if (strncmp(inpstr, "tan", 3) == 0) {
          if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
            push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
          }
          push_backC(&nodesCount, &opr, 'T');
        }
      } else if (*inpstr == 'c') {
        if (strncmp(inpstr, "cos", 3) == 0) {
          if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
            push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
          }
          push_backC(&nodesCount, &opr, 'C');
        }
      }
    } else if (*inpstr == 'l') {
      if (strncmp(inpstr, "ln", 2) == 0) {
        if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
          push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
        }
        push_backC(&nodesCount, &opr, 'l');
      } else if (strncmp(inpstr, "log", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
          push_and_print(funcstr, &opr, &nodesCount, VERYHIGH);
        }
        push_backC(&nodesCount, &opr, 'L');
      }
    } else if (*inpstr == 'm') {
      if (strncmp(inpstr, "mod", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, '%');
      }
    } else if (*inpstr == ')') {
      while (peekC(opr) != '(') {
        char symb = popC(&nodesCount, &opr);
        push_backOperator(funcstr, symb); /* peek for preceding op */
        if (nodesCount == 0) {
          perror("Wtf man");
          return 1;
        }
      }
      popC(&nodesCount, &opr); /* removing '(' after we popped everything out */
    }
    i++;
  }
  /* poppint everything on output string after finishing parsing*/
  while (nodesCount > 0) {
    char f = popC(&nodesCount, &opr);
    push_backOperator(funcstr, f);
  }
  // free(nospace);
  return 0;
}

/* Support function to pop 2 elemeents at once (if needed) */
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

/* This function parses RPN string and calculate it */

int cal_oper(list_t* root, long double *result) {
  struct Node* nums = {0};
  int nodesCount = 0;
  struct Vars var = {0};
  if (!root) {
    *result = NAN;
    return 1;
  }
  while(root != NULL)  {
    if (root->value_presence) {
      push_backN(&nodesCount, &nums, root->value);
      *result = root->value;
    } 
    if (root->operator_presence) {
      if (root->operator == '+') {
        if (nodesCount > 1) {
          var = popper(&nums, &nodesCount);
          *result = var.a2 + var.a1;
        } else if (nodesCount == 1) {
          *result = +(popN(&nodesCount, &nums)); /* Check for Unary plus*/
        }
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == '~') {
        *result = 0-(popN(&nodesCount, &nums)); /* Check for Unary minus*/
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == '-') {
        var = popper(&nums, &nodesCount);
        *result = var.a2 - var.a1;
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == '*') {
        var = popper(&nums, &nodesCount);
        *result = var.a2 * var.a1;
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == '/') {
        var = popper(&nums, &nodesCount);
        *result = var.a2 / var.a1;
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == '^') {
        var = popper(&nums, &nodesCount);
        *result = powl(var.a2, var.a1);
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'v') {
        *result = sqrt(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 's') {
        *result = sin(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 't') {
        *result = tan(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'c') {
        *result = cos(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'S') {
        *result = asin(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'T') {
        *result = atan(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'C') {
        *result = acos(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'l') {
        *result = log(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == 'L') {
        *result = log10(popN(&nodesCount, &nums));
        push_backN(&nodesCount, &nums, *result);
      } else if (root->operator == '%') {
        var = popper(&nums, &nodesCount);
        *result = fmod(var.a2, var.a1);
        push_backN(&nodesCount, &nums, *result);
      }
    }
    root = root->next;
  }
  while (nodesCount > 0) {
    popN(&nodesCount,
        &nums); /* Removing our stack after we finished calculations*/
  }
  return 0;
}

int calculate(const char* b, long double* val) {
  list_t *root = {0};
  create_list(&root);
  parse_oper(root, b);
  cal_oper(root, val);
  remove_all(root);
  return 0;
}
