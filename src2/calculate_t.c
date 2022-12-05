#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests/calc_test.h"

int main() {
  Suite* triglog = triglog_suite();
  SRunner *runner = srunner_create(triglog);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
