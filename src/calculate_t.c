#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests/calc_test.h"

int main() {
  int no_failed = 0;
  Suite *add = add_min();
  Suite *mul = mult();
  SRunner *runner = srunner_create(add);
  srunner_add_suite(runner, mul);
  srunner_set_log(runner, "tests/test.log");
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
// #include <stdio.h>
// #include <stdlib.h>
//
// #include "s21_matrix.h"
// #include "tests/s21_matrix_tests.h"
//
// int main() {
//   int no_failed = 0;
//   Suite *eq = eq_suite();
//   Suite *multnum = multnum_suite();
//   Suite *multmat = multmat_suite();
//   Suite *transpose = transpose_suite();
//   Suite *determinant = determinant_suite();
//   Suite *create = create_suite();
//   Suite *sumsub = sumsub_suite();
//   Suite *compl = complement_suite();
//   Suite *inverse = inverse_suite();
//   SRunner *runner = srunner_create(eq);
//   srunner_add_suite(runner, multnum);
//   srunner_add_suite(runner, multmat);
//   srunner_add_suite(runner, transpose);
//   srunner_add_suite(runner, determinant);
//   srunner_add_suite(runner, create);
//   srunner_add_suite(runner, sumsub);
//   srunner_add_suite(runner, compl );
//   srunner_add_suite(runner, inverse);
//   srunner_set_log(runner, "tests/test.log");
//   srunner_set_fork_status(runner, CK_NOFORK);
//   srunner_run_all(runner, CK_NORMAL);
//   no_failed = srunner_ntests_failed(runner);
//   srunner_free(runner);
//   return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
// }
