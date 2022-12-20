#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(odd_sin) {
  char b[100] = "-sin(1)";
  double res = -0.841471;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(odd_m) {
  char b[100] = "2 + -3";
  double res = -1;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(just_x) {
  char b[100] = "2 + x";
  double res = 3;
  long double my_res = 0.0;
  long double x = 1;
  int ret = calculate_x(b, x, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *odd_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("odd");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, odd_sin);
  tcase_add_test(tc_core, odd_m);
  tcase_add_test(tc_core, just_x);
  suite_add_tcase(s, tc_core);
  return s;
}
