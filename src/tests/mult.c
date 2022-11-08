#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(mul) {
  char funcstr[40] = {0};
  char b[100] = "211 * 2";
  double res = 422;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(multmult) {
  char funcstr[40] = {0};
  char b[100] = "2 * 2 * 2";
  double res = 8;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(tricky_multdiv) {
  char funcstr[40] = {0};
  char b[100] = "120 / 2 * 2";
  double res = 120;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(tricky_mult) {
  char funcstr[40] = {0};
  char b[100] = "2 + 2 * 2";
  double res = 6;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

Suite *mult(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("mult");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, tricky_mult);
  tcase_add_test(tc_core, tricky_multdiv);
  tcase_add_test(tc_core, multmult);
  tcase_add_test(tc_core, mul);
  suite_add_tcase(s, tc_core);

  return s;
}
