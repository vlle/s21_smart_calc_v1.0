#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(add0) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "21.899732 + 33.140722";
  double res = 55.040454;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add1) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "41.553652 + 86.295732";
  double res = 127.849384;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add2) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "32.528525 + 41.979968";
  double res = 74.508493;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add3) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "19.190221 + 89.823325";
  double res = 109.013546;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add4) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "53.158392 + 81.326880";
  double res = 134.485273;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add5) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "30.109992 + 81.617592";
  double res = 111.727583;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add6) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "92.833790 + 93.726496";
  double res = 186.560285;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add7) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "48.319205 + 50.931410";
  double res = 99.250615;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add8) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "27.798662 + 52.024411";
  double res = 79.823073;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add9) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "62.668881 + 92.904682";
  double res = 155.573563;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add10) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "2.295031 + 1.881240";
  double res = 4.176271;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add11) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "19.173123 + 54.009030";
  double res = 73.182153;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add12) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "19.034899 + 98.897405";
  double res = 117.932304;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add13) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "82.600377 + 30.816607";
  double res = 113.416984;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add14) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "30.739962 + 17.774563";
  double res = 48.514525;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add15) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "22.936220 + 59.937424";
  double res = 82.873644;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add16) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "49.315602 + 4.180361";
  double res = 53.495963;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add17) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "24.479432 + 23.650911";
  double res = 48.130344;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add18) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "57.970347 + 0.446916";
  double res = 58.417264;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add19) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "92.729187 + 86.611557";
  double res = 179.340744;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add20) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "96.168345 + 18.562940";
  double res = 114.731285;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add21) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "46.561337 + 18.885299";
  double res = 65.446636;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add22) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "37.302248 + 15.997348";
  double res = 53.299596;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add23) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "68.712205 + 22.022475";
  double res = 90.734680;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add24) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "50.884132 + 71.729910";
  double res = 122.614042;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add25) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "71.201672 + 32.598202";
  double res = 103.799875;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add26) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "97.889587 + 9.110569";
  double res = 107.000157;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add27) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "75.409709 + 60.364187";
  double res = 135.773895;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add28) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "56.533019 + 1.206207";
  double res = 57.739226;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(add29) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "57.258049 + 35.427299";
  double res = 92.685348;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *add(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("add");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, add0);
  tcase_add_test(tc_core, add1);
  tcase_add_test(tc_core, add2);
  tcase_add_test(tc_core, add3);
  tcase_add_test(tc_core, add4);
  tcase_add_test(tc_core, add5);
  tcase_add_test(tc_core, add6);
  tcase_add_test(tc_core, add7);
  tcase_add_test(tc_core, add8);
  tcase_add_test(tc_core, add9);
  tcase_add_test(tc_core, add10);
  tcase_add_test(tc_core, add11);
  tcase_add_test(tc_core, add12);
  tcase_add_test(tc_core, add13);
  tcase_add_test(tc_core, add14);
  tcase_add_test(tc_core, add15);
  tcase_add_test(tc_core, add16);
  tcase_add_test(tc_core, add17);
  tcase_add_test(tc_core, add18);
  tcase_add_test(tc_core, add19);
  tcase_add_test(tc_core, add20);
  tcase_add_test(tc_core, add21);
  tcase_add_test(tc_core, add22);
  tcase_add_test(tc_core, add23);
  tcase_add_test(tc_core, add24);
  tcase_add_test(tc_core, add25);
  tcase_add_test(tc_core, add26);
  tcase_add_test(tc_core, add27);
  tcase_add_test(tc_core, add28);
  tcase_add_test(tc_core, add29);
  suite_add_tcase(s, tc_core);

  return s;
}
