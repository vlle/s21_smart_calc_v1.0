#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(si) {
  char funcstr[40] = {0};
  char b[100] = "sin(1+4)";  //+2";
  double res = -0.9589;
  char *prs = parse_oper(funcstr, b);
  printf("trig = %s\n", prs);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(si2) {
  char funcstr[40] = {0};
  char b[100] = "sin(1+4)-2";  //+2";
  double res = -2.9589;
  char *prs = parse_oper(funcstr, b);
  printf("trig = %s\n", prs);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *trigo(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("trig");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, si);
  tcase_add_test(tc_core, si2);
  suite_add_tcase(s, tc_core);

  return s;
}
