#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests/calc_test.h"

// add more float test check
// add minus sign
int main() {
  int no_failed = 0;
  Suite *add_m = add_min();
  Suite *mul = mult();
  Suite *trig = trigo();
  Suite *ad = add();
  Suite *mi = minusminus_suite();
  Suite *si = sinus_suite();
  SRunner *runner = srunner_create(add_m);
  srunner_add_suite(runner, mul);
  srunner_add_suite(runner, ad);
  srunner_add_suite(runner, trig);
  srunner_add_suite(runner, mi);
  srunner_add_suite(runner, si);
  srunner_set_log(runner, "tests/test.log");
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
