#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(triglog0) {
    char b[100] = "0.744264*sin(0.950057)-cos(0.487901)+acos(0.152541)+asin(0.375187)";
    double res = 1.524358;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog1) {
    char b[100] = "0.963526*sin(0.957187)-cos(0.057596)+acos(0.170060)+asin(0.548908)";
    double res = 1.770376;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog2) {
    char b[100] = "0.735414*sin(0.501862)-cos(0.306122)+acos(0.696612)+asin(0.608275)";
    double res = 0.854285;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog3) {
    char b[100] = "0.597297*sin(0.949448)-cos(0.398919)+acos(0.799110)+asin(0.362892)";
    double res = 0.580530;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog4) {
    char b[100] = "0.706848*sin(0.837472)-cos(0.471327)+acos(0.129528)+asin(0.864352)";
    double res = 2.118952;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog5) {
    char b[100] = "0.503809*sin(0.799179)-cos(0.784070)+acos(0.978265)+asin(0.300177)";
    double res = 0.166829;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog6) {
    char b[100] = "0.378784*sin(0.342514)-cos(0.441960)+acos(0.972085)+asin(0.744251)";
    double res = 0.299551;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog7) {
    char b[100] = "0.295322*sin(0.056694)-cos(0.790032)+acos(0.565599)+asin(0.049746)";
    double res = 0.332315;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog8) {
    char b[100] = "0.965165*sin(0.338463)-cos(0.419171)+acos(0.159989)+asin(0.425063)";
    double res = 1.256193;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog9) {
    char b[100] = "0.442101*sin(0.917721)-cos(0.667973)+acos(0.125135)+asin(0.917447)";
    double res = 2.172994;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog10) {
    char b[100] = "0.503629*sin(0.870461)-cos(0.920660)+acos(0.239006)+asin(0.715344)";
    double res = 1.906364;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog11) {
    char b[100] = "0.317741*sin(0.544001)-cos(0.908778)+acos(0.177702)+asin(0.061101)";
    double res = 1.003026;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog12) {
    char b[100] = "0.993711*sin(0.803943)-cos(0.670990)+acos(0.056963)+asin(0.709209)";
    double res = 2.234540;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog13) {
    char b[100] = "0.785550*sin(0.623156)-cos(0.131555)+acos(0.382118)+asin(0.169433)";
    double res = 0.816052;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog14) {
    char b[100] = "0.155582*sin(0.868104)-cos(0.168427)+acos(0.787293)+asin(0.395212)";
    double res = 0.203564;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog15) {
    char b[100] = "0.603570*sin(0.778795)-cos(0.456287)+acos(0.062661)+asin(0.677166)";
    double res = 1.778265;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog16) {
    char b[100] = "0.820391*sin(0.156077)-cos(0.938763)+acos(0.680865)+asin(0.339484)";
    double res = 0.704960;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog17) {
    char b[100] = "0.043901*sin(0.124235)-cos(0.592669)+acos(0.015733)+asin(0.380008)";
    double res = 1.120855;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog18) {
    char b[100] = "0.644014*sin(0.984646)-cos(0.277828)+acos(0.418951)+asin(0.389435)";
    double res = 1.113384;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog19) {
    char b[100] = "0.271762*sin(0.607550)-cos(0.718394)+acos(0.391767)+asin(0.323915)";
    double res = 0.900383;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog20) {
    char b[100] = "0.185760*sin(0.790756)-cos(0.023317)+acos(0.067227)+asin(0.047220)";
    double res = 0.683082;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog21) {
    char b[100] = "0.192131*sin(0.067398)-cos(0.625373)+acos(0.546033)+asin(0.508406)";
    double res = 0.728702;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog22) {
    char b[100] = "0.254482*sin(0.099779)-cos(0.985929)+acos(0.947223)+asin(0.328657)";
    double res = 0.134479;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog23) {
    char b[100] = "0.397800*sin(0.024923)-cos(0.428569)+acos(0.615853)+asin(0.425217)";
    double res = 0.446882;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog24) {
    char b[100] = "0.922107*sin(0.254990)-cos(0.206442)+acos(0.405899)+asin(0.007521)";
    double res = 0.414177;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog25) {
    char b[100] = "0.948961*sin(0.310990)-cos(0.586783)+acos(0.473092)+asin(0.913224)";
    double res = 1.686784;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog26) {
    char b[100] = "0.046682*sin(0.164076)-cos(0.516048)+acos(0.476176)+asin(0.259244)";
    double res = 0.474584;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog27) {
    char b[100] = "0.497529*sin(0.788475)-cos(0.141842)+acos(0.093296)+asin(0.303262)";
    double res = 1.148408;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog28) {
    char b[100] = "0.941213*sin(0.023601)-cos(0.834046)+acos(0.900543)+asin(0.914610)";
    double res = 0.954649;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog29) {
    char b[100] = "0.270949*sin(0.718059)-cos(0.027278)+acos(0.675124)+asin(0.399085)";
    double res = 0.418818;
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
 
