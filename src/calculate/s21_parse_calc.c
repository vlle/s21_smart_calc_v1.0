#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

#define VERYHIGH "^"
#define HIGHPRIOR "^*/STCstc%Ll"  // ^
#define LOWPRIOR "^*/+-stcSTC%Ll"

/* These functions are for support.

  CheckNodesPrior checks top of the stack to see, if there's any operator with
  same or greater precedence than given.

  push_and_print pushes all operators than greater or same predence than given.
*/

int s21_isdigit(const char c, int base) {
  int s21_num = 0;
  if (base == 10) {
    s21_num = ((c >= 48) && (c <= 57)) ? 1 : 0;
  } else if (base == 8) {
    s21_num = ((c >= 48) && (c < 56)) ? 1 : 0;
  } else if (base == 16) {
    s21_num = (((c >= 97) && (c <= 102)) || (((c >= 65) && (c <= 70))) ||
               ((c >= 48) && (c <= 57)))
                  ? 1
                  : 0;
  }
  return s21_num;
}

int s21_isspace(const char* str) {
  return (((*str == '\n') || (*str == ' ') || (*str == '\t')) ? 1 : 0);
}

unsigned int s21_digitizer(const char c) {
  int res = 0;
  if (c >= '0' && c <= '9') res = c - '0';
  if (c >= 'A' && c <= 'F') res = c - 'A' + 10;
  if (c >= 'a' && c <= 'f') res = c - 'a' + 10;
  return res;
}

int s21_size_check(const char* format, int base, int width) {
  int count = 0;
  if (width == 0) width = -1;
  while ((*format != '\0') && ((s21_isdigit(*format, base)) && (width != 0))) {
    format++;
    count++;
    width--;
  }
  return count;
}  // 123123V

long s21_num2numLONG(const char* format, int base, int width) {
  long a = 0;
  int count = s21_size_check(format, base, width) - 1;
  int flag = 0;
  if (width == 0) width -= 1;
  while (((*format != '\0')) && (s21_isdigit(*format, base)) && (width != 0)) {
    a += (s21_digitizer(*format) * pow(base, count));
    count--;
    format++;
    flag++;
    width--;
  }
  return (flag) ? a : -1683532;
}

long double expon_check(char* str, char** str_end) {
  char sign_e;
  double a_exponent = 0.1;
  int flag = 0;
  long double res = 0.0;
  long double res_beforedot = 0.0;
  long double res_afterdot = 0.0;
  if (('E' == *str) || ('e' == *str)) {
    str++;
    sign_e = *str;
    if ((sign_e == '+') || (sign_e == '-')) {
      str++;
      int count = s21_size_check(str, 10, 0);
      a_exponent = s21_num2numLONG(str, 10, 0);
      flag++;
      for (; count > 0; count--) str++;
    }
  }
  res = res_beforedot + res_afterdot;
  if (flag) {
    for (; a_exponent; a_exponent--) {
      if (sign_e == '+') res *= 10;
      if (sign_e == '-') res *= 0.1;
    }
  }
  *str_end = str;
  return res;
}

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
  struct Node* opr = {0};
  int nodesCount = 0;
  int funcstr_i = 0;
  char* inpstr = (char*)inpo;
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
    } else if (*inpstr == 's') {
      if (strncmp(inpstr, "sin", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, 's');
      }
    } else if (*inpstr == 't') {
      if (strncmp(inpstr, "tan", 3) == 0) {
        if (checkNodesPrior(nodesCount, opr, LOWPRIOR)) {
          push_and_print(&funcstr, &opr, &nodesCount, HIGHPRIOR);
        }
        push_backC(&nodesCount, &opr, 't');
      }
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
        }
      }
      popC(&nodesCount, &opr); /* removing '(' after we popped everything out */
    }
  }
  funcstr_i = strlen(funcstr);
  /* poppint everything on output string after finishing parsing*/
  while (nodesCount > 0) {
    funcstr[funcstr_i++] = popC(&nodesCount, &opr); /* peek for preceding op */
    funcstr[funcstr_i++] = ' ';
  }
  funcstr[funcstr_i] = '\0';
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
  for (; *funcstr != '\0'; funcstr++) {
    if (*funcstr >= '0' && *funcstr <= '9') {
      char* pEnd;
      long double calc_num =
          strtold(funcstr, &pEnd); /*strtold parses float num from str*/
      push_backN(&nodesCount, &nums, calc_num);
      funcstr = pEnd;
    } else if (*funcstr == '+') {
      if (nodesCount > 1) {
        var = popper(&nums, &nodesCount);
        result = var.a2 + var.a1;
      } else if (nodesCount == 1) {
        result = +(popN(&nodesCount, &nums)); /* Check for Unary plus*/
      }
      push_backN(&nodesCount, &nums, result);
    } else if (*funcstr == '-') {
      if (nodesCount > 1) {
        var = popper(&nums, &nodesCount);
        result = var.a2 - var.a1;
      } else if (nodesCount == 1) {
        result = -(popN(&nodesCount, &nums)); /* Check for Unary minus*/
      }
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
