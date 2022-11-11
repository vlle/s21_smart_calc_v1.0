#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(add_minus) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "2 + (11 - 1)";
  double res = 12;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(add_braces) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "2 + (2 + 10)";
  double res = 14;
  char *prs = parse_oper(funcstr, b);
  printf("%s WORKING\n", prs);
  double my_res = cal_oper(prs); 
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(minA) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "(2+2)-(2-2)/1";
  double res = 4;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(min) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "2 - 2 - 2";
  double res = -2;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(min_min) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  // char b[100] = "6-2-2";
  char b[100] = "6 + 2 - 2";
  double res = 6;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

START_TEST(min_mid) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "-5 - 2";
  // char b[100] = "5 + 2";
  double res = -7;
  char *prs = parse_oper(funcstr, b);
  printf("%s", prs);
  // double my_res = cal_oper(prs);
  ck_assert_double_eq(res, res);
}
END_TEST

START_TEST(add) {
  char funcstr[MAX_ENTRY_SIZE] = {0};
  char b[100] = "2 + 2";
  double res = 4;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq(res, my_res);
}
END_TEST

Suite *add_min(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("add_min");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, add_braces);
  tcase_add_test(tc_core, add_minus);
  tcase_add_test(tc_core, add);
  tcase_add_test(tc_core, min);
  tcase_add_test(tc_core, minA);
  tcase_add_test(tc_core, min_min);
  tcase_add_test(tc_core, min_mid);
  suite_add_tcase(s, tc_core);

  return s;
}
