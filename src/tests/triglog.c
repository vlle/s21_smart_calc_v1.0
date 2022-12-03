#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(triglog0) {
    char b[100] = "0.470527*sin(0.149496)/acos(0.906924)+asin(0.546877)*0.882708";
    double res = 0.671912;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog1) {
    char b[100] = "0.747626*sin(0.765872)/acos(0.440270)+asin(0.971987)*0.606682";
    double res = 1.273858;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog2) {
    char b[100] = "0.176636*sin(0.175896)/acos(0.038209)+asin(0.319670)*0.039391";
    double res = 0.032985;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog3) {
    char b[100] = "0.430757*sin(0.200469)/acos(0.983631)+asin(0.413356)*0.121779";
    double res = 0.525314;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog4) {
    char b[100] = "0.790794*sin(0.060768)/acos(0.312868)+asin(0.155197)*0.182898";
    double res = 0.066841;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog5) {
    char b[100] = "0.152092*sin(0.457681)/acos(0.624929)+asin(0.862463)*0.758724";
    double res = 0.864187;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog6) {
    char b[100] = "0.820993*sin(0.128649)/acos(0.033163)+asin(0.106633)*0.562156";
    double res = 0.128559;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog7) {
    char b[100] = "0.409950*sin(0.076451)/acos(0.522427)+asin(0.775692)*0.342337";
    double res = 0.334594;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog8) {
    char b[100] = "0.812781*sin(0.121163)/acos(0.562874)+asin(0.538982)*0.965121";
    double res = 0.650345;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog9) {
    char b[100] = "0.806430*sin(0.034347)/acos(0.518827)+asin(0.299041)*0.296782";
    double res = 0.117138;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog10) {
    char b[100] = "0.630455*sin(0.658500)/acos(0.424092)+asin(0.229994)*0.777501";
    double res = 0.520992;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog11) {
    char b[100] = "0.170160*sin(0.152592)/acos(0.643980)+asin(0.425862)*0.287751";
    double res = 0.156277;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog12) {
    char b[100] = "0.136538*sin(0.826426)/acos(0.842351)+asin(0.992809)*0.984892";
    double res = 1.605324;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog13) {
    char b[100] = "0.433651*sin(0.325661)/acos(0.939195)+asin(0.295931)*0.709003";
    double res = 0.608821;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog14) {
    char b[100] = "0.304001*sin(0.142730)/acos(0.972509)+asin(0.592340)*0.791322";
    double res = 0.685661;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog15) {
    char b[100] = "0.502583*sin(0.359718)/acos(0.344344)+asin(0.905041)*0.885703";
    double res = 1.147252;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog16) {
    char b[100] = "0.879063*sin(0.410139)/acos(0.254893)+asin(0.833755)*0.552503";
    double res = 0.811643;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog17) {
    char b[100] = "0.896041*sin(0.167218)/acos(0.991697)+asin(0.251836)*0.498994";
    double res = 1.283548;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog18) {
    char b[100] = "0.949117*sin(0.871603)/acos(0.137099)+asin(0.820737)*0.789032";
    double res = 1.266429;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog19) {
    char b[100] = "0.847254*sin(0.969241)/acos(0.315034)+asin(0.068950)*0.119266";
    double res = 0.566913;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog20) {
    char b[100] = "0.914631*sin(0.350808)/acos(0.040321)+asin(0.627986)*0.513316";
    double res = 0.553897;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog21) {
    char b[100] = "0.662861*sin(0.778990)/acos(0.193133)+asin(0.530691)*0.900139";
    double res = 0.841888;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog22) {
    char b[100] = "0.720753*sin(0.007786)/acos(0.937094)+asin(0.877664)*0.525138";
    double res = 0.578142;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog23) {
    char b[100] = "0.313859*sin(0.042104)/acos(0.961436)+asin(0.308500)*0.025203";
    double res = 0.055319;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog24) {
    char b[100] = "0.318331*sin(0.715697)/acos(0.318228)+asin(0.455154)*0.497622";
    double res = 0.402656;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog25) {
    char b[100] = "0.465184*sin(0.535007)/acos(0.423437)+asin(0.003056)*0.291243";
    double res = 0.210118;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog26) {
    char b[100] = "0.290079*sin(0.448264)/acos(0.617857)+asin(0.377352)*0.322980";
    double res = 0.263924;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog27) {
    char b[100] = "0.968441*sin(0.005261)/acos(0.083374)+asin(0.178774)*0.533792";
    double res = 0.099369;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog28) {
    char b[100] = "0.543081*sin(0.749587)/acos(0.286107)+asin(0.078264)*0.563034";
    double res = 0.333046;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog29) {
    char b[100] = "0.017384*sin(0.791000)/acos(0.838005)+asin(0.433233)*0.156227";
    double res = 0.091418;
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
 
