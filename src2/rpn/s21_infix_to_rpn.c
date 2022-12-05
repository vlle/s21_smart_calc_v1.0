#include "../smartcalc.h" 
#include <math.h>
#include <tgmath.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define P3 "~^"
#define P2 "~/*^sctSCTlLV"
#define P1 "~+-/*^sctSCTlLV"

#define ALL_L_OP "+-/*^"
#define ALL_TRIG "sincostan"
#define ALL_T "SCTsct"

int calculate(const char* input, long double* val) {
  list_t* root = createList(0, 0, 0, 0);
  infToRpn(input, &root);
  long double ans = calculateRpn(root);
  *val = ans;
  printf("\n");
  printList(root);
  printf("\n");
  freeList(&root);
  return ans;
}

// +-/* sct SCT v lN LOG mod
//

int infToRpn(const char* input, list_t** root) {
  list_t* stack = createStack(0, 0, 0, 0);
  // const char* trig_word[3] = {"sin", "cos", "tan"};
  const char* priority_string[3] = {"~+-/*^sctSCTlLV", "~/*^sctSCTlLV", "~^"};

  char oper = 0;
  int nodes_count = 1;
  long double num = 0.0;
  int priority_pointer = 0;

  for (char* pEnd = NULL; *input != '\0'; input++) {
    printf("%c", *input);
    if (*input == 'a') {
      input++; 
      if (input) {
        if (strchr(ALL_TRIG, *input)) {
          if (strncmp(input, "sin", 3) == 0) pushOperStack(&stack, 'S', &nodes_count);
          if (strncmp(input, "cos", 3) == 0) pushOperStack(&stack, 'C', &nodes_count);
          if (strncmp(input, "tan", 3) == 0) pushOperStack(&stack, 'T', &nodes_count);
        }
      }
    } else if (*input == '(') {
      pushOperStack(&stack, '(', &nodes_count);
    } else if (*input == ')') {
      while (nodes_count > 0 && peekOperStack(stack) != '(') pushOper(root, popOperStack(&stack, &nodes_count));
      if (peekOperStack(stack)=='(') popOperStack(&stack, &nodes_count);
    } else if (isdigit(*input)) {
      num = strtold(input, &pEnd);
      input = pEnd-1;
      printf(" %Lf ", num);
      pushValue(root, num);
    } else if (strchr(ALL_L_OP, *input)) {
      if (strchr(P3, *input)) {
        priority_pointer = 3;
      } else if (strchr(P2, *input)) {
        priority_pointer = 2;
      } else if (strchr(P1, *input)) {
        priority_pointer = 1;
      }
      pushAndPrint(&stack, root, &nodes_count, (char*) priority_string[priority_pointer-1]);
      oper = *input;
      if (oper != ')') pushOperStack(&stack, oper, &nodes_count);
    } else if (strchr(ALL_TRIG, *input)) {
      if ((strncmp(input, "cos", 3)== 0) || (strncmp(input, "sin", 3)== 0) || (strncmp(input, "tan", 3)== 0)) pushAndPrint(&stack, root, &nodes_count, P3);
      if (strncmp(input, "sin", 3)== 0) pushOperStack(&stack, 's', &nodes_count);
      if (strncmp(input, "cos", 3)== 0) pushOperStack(&stack, 'c', &nodes_count);
      if (strncmp(input, "tan", 3)== 0) pushOperStack(&stack, 't', &nodes_count);
    }
  }
  printf("= input val\n");
  while (nodes_count > 0) {
    pushOper(root, popOperStack(&stack, &nodes_count));
  }
  printList(*root);
  return 0;
}

long double calculateRpn(list_t* root) {
  long double ans = 0.0;
  list_t * stack = createStack(0, 0, 0, kValue);
  int nodes_count = 0;
  elem_t val = {0};
  while (root) {
    if (root->type == kValue) {
      ans = root->value;
      pushValueStack(&stack, ans, &nodes_count);
    } else if (root->type == kOper) {
      char o = root->oper;
      if (o == '+') {
        if (nodes_count > 1) {
          val = pop2Value(&stack, &nodes_count);
          ans = val.a + val.b;
        } else {
          ans = popValueStack(&stack, &nodes_count);
        }
      } else if (o == '-') {
        if (nodes_count > 1) {
          val = pop2Value(&stack, &nodes_count);
          ans = val.b - val.a;
        } else {
          ans = -popValueStack(&stack, &nodes_count);
        }
      } else if (o == '/') {
        val = pop2Value(&stack, &nodes_count);
        ans = val.b / val.a;
      } else if (o == '*') {
        val = pop2Value(&stack, &nodes_count);
        ans = val.b * val.a;
      } else if (strchr(ALL_T, o)) {
        long double trig_val = popValueStack(&stack, &nodes_count);
        if (o == 's') ans = sinl(trig_val);  
        else if (o == 'c') ans = cosl(trig_val); 
        else if (o == 't') ans = tanl(trig_val); 
        else if (o == 'S') ans = asinl(trig_val); 
        else if (o == 'C') ans = acosl(trig_val); 
        else if (o == 'T') ans = atanl(trig_val); 
      } else if (o == 'v') {
        ans = sqrt(popValueStack(&stack, &nodes_count));
      } else if (o == 'l') {
        ans = log(popValueStack(&stack, &nodes_count));
      } else if (o == 'L') {
        ans = log10(popValueStack(&stack, &nodes_count));
      } else if (o == '%') {
        val = pop2Value(&stack, &nodes_count);
        ans = fmodl(val.b,val.a);
      }
      pushValueStack(&stack, ans, &nodes_count);
    }
    root = root->next;
  }
  while (nodes_count >= 0) {
    popValueStack(&stack, &nodes_count);
  }
  return ans;
}

elem_t pop2Value(list_t ** stack, int*nodes_count) {
  elem_t ans = {0};
  if (*nodes_count > 1) {
    ans.a = popValueStack(stack, nodes_count);
    ans.b = popValueStack(stack, nodes_count);
  } else {
    fprintf(stderr, "Pop error: not enough nodes");
  }
  return ans;
}

int pushAndPrint(list_t** stack, list_t** root, int*nodes_count, char* priority) {
  while (*nodes_count > 0 && strchr(priority, peekOperStack(*stack))) {
    if (peekOperStack(*stack) == '(') {
      popOperStack(stack, nodes_count);
    } else {
      pushOper(root, popOperStack(stack, nodes_count));
    }
  }
  return 0;
}
