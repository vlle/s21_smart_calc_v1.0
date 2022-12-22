#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(atg0) {
  char b[100] = "-atan(0.224077)+acos(0.814334)/0.030024/0.541714*0.691751";
  double res = 26.115760;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg1) {
  char b[100] = "-atan(0.589126)+acos(0.660172)/0.160504/0.508176*0.203869";
  double res = 1.591551;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg2) {
  char b[100] = "-atan(0.537352)+acos(0.528832)/0.363109/0.368759*0.945608";
  double res = 6.664831;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg3) {
  char b[100] = "-atan(0.096131)+acos(0.136014)/0.271140/0.057748*0.537244";
  double res = 49.119338;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg4) {
  char b[100] = "-atan(0.019703)+acos(0.384038)/0.839482/0.771579*0.221023";
  double res = 0.381800;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg5) {
  char b[100] = "-atan(0.534118)+acos(0.262569)/0.001994/0.021246*0.215991";
  double res = 6653.486955;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg6) {
  char b[100] = "-atan(0.744537)+acos(0.434865)/0.591390/0.830509*0.802032";
  double res = 1.190393;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg7) {
  char b[100] = "-atan(0.251417)+acos(0.190418)/0.614091/0.688646*0.296844";
  double res = 0.721809;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg8) {
  char b[100] = "-atan(0.252254)+acos(0.975906)/0.573951/0.292028*0.367619";
  double res = 0.235342;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg9) {
  char b[100] = "-atan(0.787751)+acos(0.991097)/0.743701/0.072576*0.693086";
  double res = 1.047526;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg10) {
  char b[100] = "-atan(0.619626)+acos(0.502007)/0.405390/0.906482*0.671439";
  double res = 1.354425;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg11) {
  char b[100] = "-atan(0.938073)+acos(0.391443)/0.595993/0.340521*0.528952";
  double res = 2.292306;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg12) {
  char b[100] = "-atan(0.470984)+acos(0.769600)/0.105997/0.340771*0.073362";
  double res = 0.966484;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg13) {
  char b[100] = "-atan(0.042683)+acos(0.471883)/0.162236/0.993876*0.696023";
  double res = 4.616581;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg14) {
  char b[100] = "-atan(0.961626)+acos(0.667370)/0.096054/0.982924*0.878741";
  double res = 7.053486;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg15) {
  char b[100] = "-atan(0.065787)+acos(0.231981)/0.411624/0.605738*0.674009";
  double res = 3.547645;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg16) {
  char b[100] = "-atan(0.529525)+acos(0.054707)/0.313202/0.915636*0.569818";
  double res = 2.525364;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg17) {
  char b[100] = "-atan(0.811447)+acos(0.058552)/0.283911/0.715845*0.300712";
  double res = 1.555812;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg18) {
  char b[100] = "-atan(0.523382)+acos(0.015260)/0.437978/0.572968*0.129114";
  double res = 0.318155;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg19) {
  char b[100] = "-atan(0.544778)+acos(0.969093)/0.688766/0.049581*0.427347";
  double res = 2.620510;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg20) {
  char b[100] = "-atan(0.618518)+acos(0.712033)/0.640197/0.809624*0.870803";
  double res = 0.753840;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg21) {
  char b[100] = "-atan(0.596842)+acos(0.822944)/0.950676/0.402862*0.036582";
  double res = -0.480381;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg22) {
  char b[100] = "-atan(0.407985)+acos(0.691186)/0.224228/0.280019*0.476401";
  double res = 5.740758;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg23) {
  char b[100] = "-atan(0.763325)+acos(0.442453)/0.115101/0.396570*0.140628";
  double res = 2.775379;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg24) {
  char b[100] = "-atan(0.161824)+acos(0.266721)/0.245989/0.401823*0.071373";
  double res = 0.778850;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg25) {
  char b[100] = "-atan(0.860483)+acos(0.117472)/0.654878/0.741250*0.087785";
  double res = -0.447778;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg26) {
  char b[100] = "-atan(0.991228)+acos(0.488687)/0.683394/0.980032*0.486386";
  double res = -0.011043;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg27) {
  char b[100] = "-atan(0.521493)+acos(0.685273)/0.999962/0.666614*0.706214";
  double res = 0.383620;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg28) {
  char b[100] = "-atan(0.189875)+acos(0.106592)/0.495971/0.267621*0.619357";
  double res = 6.643702;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

START_TEST(atg29) {
  char b[100] = "-atan(0.715849)+acos(0.032213)/0.982283/0.208390*0.299049";
  double res = 1.626468;
  long double my_res = 0.0;
  calculate(b, &my_res);
  ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

Suite *atg_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("atg");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, atg0);
  tcase_add_test(tc_core, atg1);
  tcase_add_test(tc_core, atg2);
  tcase_add_test(tc_core, atg3);
  tcase_add_test(tc_core, atg4);
  tcase_add_test(tc_core, atg5);
  tcase_add_test(tc_core, atg6);
  tcase_add_test(tc_core, atg7);
  tcase_add_test(tc_core, atg8);
  tcase_add_test(tc_core, atg9);
  tcase_add_test(tc_core, atg10);
  tcase_add_test(tc_core, atg11);
  tcase_add_test(tc_core, atg12);
  tcase_add_test(tc_core, atg13);
  tcase_add_test(tc_core, atg14);
  tcase_add_test(tc_core, atg15);
  tcase_add_test(tc_core, atg16);
  tcase_add_test(tc_core, atg17);
  tcase_add_test(tc_core, atg18);
  tcase_add_test(tc_core, atg19);
  tcase_add_test(tc_core, atg20);
  tcase_add_test(tc_core, atg21);
  tcase_add_test(tc_core, atg22);
  tcase_add_test(tc_core, atg23);
  tcase_add_test(tc_core, atg24);
  tcase_add_test(tc_core, atg25);
  tcase_add_test(tc_core, atg26);
  tcase_add_test(tc_core, atg27);
  tcase_add_test(tc_core, atg28);
  tcase_add_test(tc_core, atg29);
  suite_add_tcase(s, tc_core);

  return s;
}
