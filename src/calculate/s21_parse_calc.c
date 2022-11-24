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

/* This function parses INFIX string and create RPN string
   Algo: Parse nums, parse OPs (and check priority), parse Trigonometry func */

char* parse_oper(char* funcstr, const char* inpo) {
  char *nospace= malloc(sizeof(inpo));
  int f = 0;
  for (unsigned int i = 0; i < strlen(inpo); i++) {
    if (inpo[i] != ' ') {
      nospace[f] = inpo[i];
      f++;
    }
  }
  printf("%s = spce\n",nospace);
  struct Node* opr = {0};
  int nodesCount = 0;
  int funcstr_i = 0;
  char* inpstr = nospace;
  int len = strlen(inpo);
  int i = 0;
  for (; ((*inpstr != '\0') & (len >= i)); inpstr++) {
    if (*inpstr >= '0' && *inpstr <= '9') {
      char num_str[MAX_ENTRY_SIZE] = {0};
      char* pEnd;
      long double calc_num = strtold(inpstr, &pEnd);
      sprintf(num_str, "%Lf", calc_num);
      inpstr = pEnd;
      strcat(num_str, " ");
      strcat(funcstr, num_str);
      i += (pEnd-inpstr+1);
      if (nodesCount >= 1) {
        if (peekC(opr) == '-') {
          strcat(funcstr, " ");
          strcat(funcstr, "-");
          strcat(funcstr, " ");
          popC(&nodesCount, &opr); /* peek for preceding op */
        }
      }
      if (nodesCount >= 1) {
        push_and_print(&funcstr, &opr, &nodesCount, SUPREME);
      }
    }

    if (*inpstr == '(') {
      push_backC(&nodesCount, &opr, '(');
    } else if (*inpstr == '+') {
      if (nodesCount > 0) {
        push_and_print(&funcstr, &opr, &nodesCount, LOWPRIOR);
      }
      push_backC(&nodesCount, &opr, '+');
    } else if (*inpstr == '-') {
      char* tp = inpstr-1;
      char tmp = *tp;
      if ((i == 0) || ((i>1) && (tmp != ')') && (strchr(ALL, tmp) != NULL))) {
        if (nodesCount > 0) {
          push_and_print(&funcstr, &opr, &nodesCount, VERYHIGH);
        }
        printf("I AM UNARY%c\n%i\n", tmp, i);
        push_backC(&nodesCount, &opr, '~');
      } else {
        if (nodesCount > 0) {
          push_and_print(&funcstr, &opr, &nodesCount, LOWPRIOR);
        }
        push_backC(&nodesCount, &opr, '-');
      }
    } else if (*inpstr == '/') {
      if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
        push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
      }
      push_backC(&nodesCount, &opr, '/');
    } else if (*inpstr == '*') {
      if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
        push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
      }
      push_backC(&nodesCount, &opr, '*');
    } else if (*inpstr == '^') {
      if (checkNodesPrior(nodesCount, opr, VERYHIGH)) {
        push_and_print(&funcstr, &opr, &nodesCount, VERYHIGH);
      }
      push_backC(&nodesCount, &opr, '^');
    } else if ((*inpstr == 's') & (strncmp(inpstr, "sin", 3) == 0)) {
      if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
        push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
      }
      push_backC(&nodesCount, &opr, 's');
    } else if (*inpstr == 't') {
      if (strncmp(inpstr, "tan", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, 't');
      }
    } else if ((*inpstr == 's') && (strncmp(inpstr, "sqrt", 4) == 0)) {
      if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
        push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
      }
      push_backC(&nodesCount, &opr, 'v');
    } else if (*inpstr == 'c') {
      if (strncmp(inpstr, "cos", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, 'c');
      }
    } else if (*inpstr == 'a') {
      inpstr += 1;
      if (*inpstr == 's') {
        if (strncmp(inpstr, "sin", 3) == 0) {
          if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
            push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
          }
          push_backC(&nodesCount, &opr, 'S');
        }
      } else if (*inpstr == 't') {
        if (strncmp(inpstr, "tan", 3) == 0) {
          if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
            push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
          }
          push_backC(&nodesCount, &opr, 'T');
        }
      } else if (*inpstr == 'c') {
        if (strncmp(inpstr, "cos", 3) == 0) {
          if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
            push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
          }
          push_backC(&nodesCount, &opr, 'C');
        }
      }
    } else if (*inpstr == 'l') {
      if (strncmp(inpstr, "ln", 2) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, 'l');
      } else if (strncmp(inpstr, "log", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, 'L');
      }
    } else if (*inpstr == 'm') {
      if (strncmp(inpstr, "mod", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, '%');
      }
    } else if (*inpstr == ')') {
      funcstr_i = strlen(funcstr);
      while (peekC(opr) != '(') {
        funcstr[funcstr_i++] =
          popC(&nodesCount, &opr); /* peek for preceding op */
        funcstr[funcstr_i++] = ' ';
        if (nodesCount == 0) {
          perror("Wtf man");
          return NULL;
        }
      }
      popC(&nodesCount, &opr); /* removing '(' after we popped everything out */
    }
    i++;
  }
  funcstr_i = strlen(funcstr);
  /* poppint everything on output string after finishing parsing*/
  while (nodesCount > 0) {
    funcstr[funcstr_i++] = popC(&nodesCount, &opr); /* peek for preceding op */
    funcstr[funcstr_i++] = ' ';
  }
  funcstr[funcstr_i] = '\0';
  printf("%s\n", funcstr);
  free(nospace);
  return funcstr;
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

long double cal_oper(char* funcstr) {
  long double result = 0.0;
  struct Node* nums;
  int nodesCount = 0;
  struct Vars var;
  if (!funcstr) {
    return NAN;
  }
  for (; *funcstr != '\0'; funcstr++) {
    if (*funcstr >= '0' && *funcstr <= '9') {
      char* pEnd;
      long double calc_num =
        strtold(funcstr, &pEnd); /*strtold parses float num from str*/
      push_backN(&nodesCount, &nums, calc_num);
      funcstr = pEnd;
      result = calc_num;
    } else if (*funcstr == '+') {
      if (nodesCount > 1) {
        var = popper(&nums, &nodesCount);
        result = var.a2 + var.a1;
      } else if (nodesCount == 1) {
        result = +(popN(&nodesCount, &nums)); /* Check for Unary plus*/
      }
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == '~') {
      result = 0-(popN(&nodesCount, &nums)); /* Check for Unary minus*/
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
    } else if (*funcstr == '^') {
      var = popper(&nums, &nodesCount);
      result = powl(var.a2, var.a1);
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'v') {
      result = sqrt(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 's') {
      result = sin(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 't') {
      result = tan(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'c') {
      result = cos(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'S') {
      result = asin(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'T') {
      result = atan(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'C') {
      result = acos(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'l') {
      result = log(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == 'L') {
      result = log10(popN(&nodesCount, &nums));
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == '%') {
      var = popper(&nums, &nodesCount);
      result = fmod(var.a2, var.a1);
      push_backN(&nodesCount, &nums, result);
    }
  }
  while (nodesCount > 0) {
    popN(&nodesCount,
         &nums); /* Removing our stack after we finished calculations*/
  }
  return result;
}

long double calculate(const char* b) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char* prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  return my_res;
}
