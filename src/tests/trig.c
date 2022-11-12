#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(si) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "sin(1+4)";  //+2";
  double res = -0.9589;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(si2) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "sin(1+4)-2";  //+2";
  double res = -2.9589;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(t) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "tan(1)";  //+2";
  double res = 1.55741;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(c) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "cos(1)";  //+2";
  double res = 0.540302;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(arcc) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "acos(1)";  //+2";
  double res = 0.0;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(arct) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "atan(1)";  //+2";
  double res = 0.78539;
  char *prs = parse_oper(funcstr, b);
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
  tcase_add_test(tc_core, t);
  tcase_add_test(tc_core, c);
  tcase_add_test(tc_core, arcc);
  tcase_add_test(tc_core, arct);
  suite_add_tcase(s, tc_core);

  return s;
}
