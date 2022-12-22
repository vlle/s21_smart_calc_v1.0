#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(trigclass0) {
  char b[100] = "sin(0.574233)+cos(0.089750)/asin(0.560331)+atan(0.916194)";
  double res = 2.959393;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass1) {
  char b[100] = "sin(0.865409)+cos(0.188842)/asin(0.513626)+atan(0.887547)";
  double res = 3.308188;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass2) {
  char b[100] = "sin(0.040662)+cos(0.486998)/asin(0.733916)+atan(0.167944)";
  double res = 1.279454;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass3) {
  char b[100] = "sin(0.186038)+cos(0.303237)/asin(0.201172)+atan(0.007699)";
  double res = 4.904366;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass4) {
  char b[100] = "sin(0.564604)+cos(0.772797)/asin(0.448283)+atan(0.013116)";
  double res = 2.088415;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass5) {
  char b[100] = "sin(0.454463)+cos(0.505980)/asin(0.923384)+atan(0.031530)";
  double res = 1.213783;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass6) {
  char b[100] = "sin(0.666609)+cos(0.449348)/asin(0.531416)+atan(0.759877)";
  double res = 2.875786;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass7) {
  char b[100] = "sin(0.437292)+cos(0.481120)/asin(0.922140)+atan(0.277184)";
  double res = 1.449247;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass8) {
  char b[100] = "sin(0.376269)+cos(0.860251)/asin(0.466757)+atan(0.952811)";
  double res = 2.471813;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass9) {
  char b[100] = "sin(0.383469)+cos(0.751654)/asin(0.983120)+atan(0.296994)";
  double res = 1.189633;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass10) {
  char b[100] = "sin(0.263629)+cos(0.706971)/asin(0.427598)+atan(0.154490)";
  double res = 2.134721;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass11) {
  char b[100] = "sin(0.864415)+cos(0.159679)/asin(0.326971)+atan(0.492494)";
  double res = 4.182280;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass12) {
  char b[100] = "sin(0.651384)+cos(0.634687)/asin(0.051047)+atan(0.731919)";
  double res = 17.006082;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass13) {
  char b[100] = "sin(0.603873)+cos(0.535709)/asin(0.391437)+atan(0.649109)";
  double res = 3.281631;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass14) {
  char b[100] = "sin(0.122310)+cos(0.945188)/asin(0.563751)+atan(0.313623)";
  double res = 1.403657;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass15) {
  char b[100] = "sin(0.270822)+cos(0.629311)/asin(0.403707)+atan(0.771414)";
  double res = 2.869972;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass16) {
  char b[100] = "sin(0.667909)+cos(0.564538)/asin(0.699676)+atan(0.559428)";
  double res = 2.219588;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass17) {
  char b[100] = "sin(0.109620)+cos(0.943352)/asin(0.033562)+atan(0.268177)";
  double res = 17.860464;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass18) {
  char b[100] = "sin(0.184972)+cos(0.912803)/asin(0.388408)+atan(0.667500)";
  double res = 2.305527;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass19) {
  char b[100] = "sin(0.473640)+cos(0.146920)/asin(0.771812)+atan(0.067855)";
  double res = 1.645851;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass20) {
  char b[100] = "sin(0.525863)+cos(0.409514)/asin(0.697057)+atan(0.084742)";
  double res = 1.775833;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass21) {
  char b[100] = "sin(0.667007)+cos(0.162047)/asin(0.211589)+atan(0.045959)";
  double res = 5.293536;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass22) {
  char b[100] = "sin(0.731046)+cos(0.169650)/asin(0.031854)+atan(0.539011)";
  double res = 32.099330;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass23) {
  char b[100] = "sin(0.224763)+cos(0.145442)/asin(0.803960)+atan(0.695481)";
  double res = 1.890007;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass24) {
  char b[100] = "sin(0.659110)+cos(0.942399)/asin(0.163721)+atan(0.986564)";
  double res = 4.965438;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass25) {
  char b[100] = "sin(0.006164)+cos(0.133363)/asin(0.452993)+atan(0.236038)";
  double res = 2.346189;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass26) {
  char b[100] = "sin(0.010500)+cos(0.916083)/asin(0.849756)+atan(0.553031)";
  double res = 1.115291;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass27) {
  char b[100] = "sin(0.046712)+cos(0.704084)/asin(0.560490)+atan(0.539418)";
  double res = 1.822443;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass28) {
  char b[100] = "sin(0.736172)+cos(0.156403)/asin(0.928477)+atan(0.804425)";
  double res = 2.178766;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigclass29) {
  char b[100] = "sin(0.258103)+cos(0.355019)/asin(0.368678)+atan(0.086010)";
  double res = 2.824291;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *trigclass_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("trigclass");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, trigclass0);
  tcase_add_test(tc_core, trigclass1);
  tcase_add_test(tc_core, trigclass2);
  tcase_add_test(tc_core, trigclass3);
  tcase_add_test(tc_core, trigclass4);
  tcase_add_test(tc_core, trigclass5);
  tcase_add_test(tc_core, trigclass6);
  tcase_add_test(tc_core, trigclass7);
  tcase_add_test(tc_core, trigclass8);
  tcase_add_test(tc_core, trigclass9);
  tcase_add_test(tc_core, trigclass10);
  tcase_add_test(tc_core, trigclass11);
  tcase_add_test(tc_core, trigclass12);
  tcase_add_test(tc_core, trigclass13);
  tcase_add_test(tc_core, trigclass14);
  tcase_add_test(tc_core, trigclass15);
  tcase_add_test(tc_core, trigclass16);
  tcase_add_test(tc_core, trigclass17);
  tcase_add_test(tc_core, trigclass18);
  tcase_add_test(tc_core, trigclass19);
  tcase_add_test(tc_core, trigclass20);
  tcase_add_test(tc_core, trigclass21);
  tcase_add_test(tc_core, trigclass22);
  tcase_add_test(tc_core, trigclass23);
  tcase_add_test(tc_core, trigclass24);
  tcase_add_test(tc_core, trigclass25);
  tcase_add_test(tc_core, trigclass26);
  tcase_add_test(tc_core, trigclass27);
  tcase_add_test(tc_core, trigclass28);
  tcase_add_test(tc_core, trigclass29);
  suite_add_tcase(s, tc_core);

  return s;
}
