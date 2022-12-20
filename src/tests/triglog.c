#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(triglog0) {
  char b[100] = "0.381253*(0.441375+0.509934)/0.318935-0.088031";
  double res = 1.049158;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog1) {
  char b[100] = "0.932112*(0.463878+0.078722)/0.394728-0.707266";
  double res = 0.574031;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog2) {
  char b[100] = "0.860466*(0.968524+0.402767)/0.073376-0.156163";
  double res = 15.924698;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog3) {
  char b[100] = "0.003623*(0.785121+0.801733)/0.619502-0.126321";
  double res = -0.117041;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog4) {
  char b[100] = "0.047941*(0.825324+0.215062)/0.565894-0.591367";
  double res = -0.503228;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog5) {
  char b[100] = "0.020520*(0.913145+0.422346)/0.061008-0.306620";
  double res = 0.142572;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog6) {
  char b[100] = "0.173759*(0.029492+0.810776)/0.524173-0.974363";
  double res = -0.695821;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog7) {
  char b[100] = "0.318506*(0.923124+0.065148)/0.042215-0.423108";
  double res = 7.033260;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog8) {
  char b[100] = "0.888075*(0.160145+0.743558)/0.601096-0.109522";
  double res = 1.225633;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog9) {
  char b[100] = "0.436595*(0.023968+0.458417)/0.993073-0.987134";
  double res = -0.775058;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog10) {
  char b[100] = "0.468675*(0.696430+0.684998)/0.724548-0.399697";
  double res = 0.493882;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog11) {
  char b[100] = "0.947130*(0.796780+0.680869)/0.215016-0.436571";
  double res = 6.072366;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog12) {
  char b[100] = "0.559984*(0.859811+0.400961)/0.104028-0.789874";
  double res = 5.996877;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog13) {
  char b[100] = "0.185295*(0.187042+0.946010)/0.253412-0.154359";
  double res = 0.674129;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog14) {
  char b[100] = "0.794052*(0.622318+0.565600)/0.863629-0.524409";
  double res = 0.567806;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog15) {
  char b[100] = "0.085110*(0.334431+0.668971)/0.700017-0.729180";
  double res = -0.607184;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog16) {
  char b[100] = "0.696323*(0.372679+0.610953)/0.390975-0.130571";
  double res = 1.621269;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog17) {
  char b[100] = "0.603423*(0.365668+0.486167)/0.292098-0.932221";
  double res = 0.827520;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog18) {
  char b[100] = "0.258225*(0.845878+0.929614)/0.553563-0.457050";
  double res = 0.371178;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog19) {
  char b[100] = "0.461199*(0.248057+0.171402)/0.852302-0.274262";
  double res = -0.047284;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog20) {
  char b[100] = "0.135284*(0.052412+0.203654)/0.521560-0.978867";
  double res = -0.912448;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog21) {
  char b[100] = "0.466887*(0.323714+0.141549)/0.021718-0.876189";
  double res = 9.125894;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog22) {
  char b[100] = "0.297121*(0.081441+0.410024)/0.804464-0.227935";
  double res = -0.046417;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog23) {
  char b[100] = "0.038225*(0.121391+0.366940)/0.211292-0.787275";
  double res = -0.698931;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog24) {
  char b[100] = "0.802192*(0.699541+0.390283)/0.984090-0.993606";
  double res = -0.105224;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog25) {
  char b[100] = "0.351316*(0.081475+0.486830)/0.813768-0.078834";
  double res = 0.166512;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog26) {
  char b[100] = "0.908586*(0.627228+0.238449)/0.304782-0.842999";
  double res = 1.737672;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog27) {
  char b[100] = "0.685998*(0.933081+0.499135)/0.943348-0.737075";
  double res = 0.304425;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog28) {
  char b[100] = "0.164690*(0.105316+0.491974)/0.449187-0.067368";
  double res = 0.151623;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(triglog29) {
  char b[100] = "0.079918*(0.007114+0.829027)/0.355109-0.032777";
  double res = 0.155398;
  long double my_res = 0.0;
  int ret = calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *triglog_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("triglog");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, triglog0);
  tcase_add_test(tc_core, triglog1);
  tcase_add_test(tc_core, triglog2);
  tcase_add_test(tc_core, triglog3);
  tcase_add_test(tc_core, triglog4);
  tcase_add_test(tc_core, triglog5);
  tcase_add_test(tc_core, triglog6);
  tcase_add_test(tc_core, triglog7);
  tcase_add_test(tc_core, triglog8);
  tcase_add_test(tc_core, triglog9);
  tcase_add_test(tc_core, triglog10);
  tcase_add_test(tc_core, triglog11);
  tcase_add_test(tc_core, triglog12);
  tcase_add_test(tc_core, triglog13);
  tcase_add_test(tc_core, triglog14);
  tcase_add_test(tc_core, triglog15);
  tcase_add_test(tc_core, triglog16);
  tcase_add_test(tc_core, triglog17);
  tcase_add_test(tc_core, triglog18);
  tcase_add_test(tc_core, triglog19);
  tcase_add_test(tc_core, triglog20);
  tcase_add_test(tc_core, triglog21);
  tcase_add_test(tc_core, triglog22);
  tcase_add_test(tc_core, triglog23);
  tcase_add_test(tc_core, triglog24);
  tcase_add_test(tc_core, triglog25);
  tcase_add_test(tc_core, triglog26);
  tcase_add_test(tc_core, triglog27);
  tcase_add_test(tc_core, triglog28);
  tcase_add_test(tc_core, triglog29);
  suite_add_tcase(s, tc_core);

  return s;
}
