#include "../calc.h" 
#include <ctype.h>
#include <stdlib.h>

long double calculate(const char* input) {
  list_t* root = createList(0, 0, 0, 0);
  // init_list();
  inf_to_rpn(input, &root);
  // calculate_rpn();
  // free_list();
  return 0;
}

// +-/* sct SCT v lN LOG mod
int inf_to_rpn(const char* input, list_t** root) {
  list_t* stack = createStack(0, 0, 0, 0);
  int nodesCount = 1;
  long double num = 0.0;
  for (char* pEnd; *input != '\0'; input++) {
    if (isdigit(*input)) {
      num = strtold(input, &pEnd);
      pushValue(root, num);
    }
  }
  return 0;
}
