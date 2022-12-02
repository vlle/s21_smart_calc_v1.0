#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(triglog0) {
    char b[100] = "0.547325*sin(0.855054)/cos(0.514355)+0.496711";
    double res = 0.971108;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog1) {
    char b[100] = "0.915174*sin(0.160169)/cos(0.861883)+0.501880";
    double res = 0.726080;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog2) {
    char b[100] = "0.574914*sin(0.085933)/cos(0.141680)+0.356675";
    double res = 0.406518;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog3) {
    char b[100] = "0.841392*sin(0.153447)/cos(0.153381)+0.139076";
    double res = 0.269207;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog4) {
    char b[100] = "0.655429*sin(0.021954)/cos(0.068690)+0.151636";
    double res = 0.166058;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog5) {
    char b[100] = "0.382502*sin(0.071777)/cos(0.053962)+0.477378";
    double res = 0.504849;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog6) {
    char b[100] = "0.634127*sin(0.258539)/cos(0.328076)+0.696188";
    double res = 0.867449;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog7) {
    char b[100] = "0.471017*sin(0.796535)/cos(0.194209)+0.793035";
    double res = 1.136235;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog8) {
    char b[100] = "0.804908*sin(0.095553)/cos(0.728218)+0.180560";
    double res = 0.283452;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog9) {
    char b[100] = "0.530456*sin(0.812867)/cos(0.635045)+0.750437";
    double res = 1.228981;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog10) {
    char b[100] = "0.647925*sin(0.919674)/cos(0.953965)+0.119748";
    double res = 1.010679;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog11) {
    char b[100] = "0.782041*sin(0.092206)/cos(0.048836)+0.523042";
    double res = 0.595135;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog12) {
    char b[100] = "0.339483*sin(0.895064)/cos(0.299670)+0.169707";
    double res = 0.446944;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog13) {
    char b[100] = "0.978896*sin(0.255897)/cos(0.149025)+0.668838";
    double res = 0.919387;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog14) {
    char b[100] = "0.062958*sin(0.957498)/cos(0.201587)+0.369708";
    double res = 0.422256;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog15) {
    char b[100] = "0.703317*sin(0.118349)/cos(0.005608)+0.091462";
    double res = 0.174506;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog16) {
    char b[100] = "0.030762*sin(0.308998)/cos(0.089954)+0.024090";
    double res = 0.033483;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog17) {
    char b[100] = "0.406728*sin(0.692044)/cos(0.686509)+0.487887";
    double res = 0.823440;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog18) {
    char b[100] = "0.098580*sin(0.714782)/cos(0.005598)+0.252995";
    double res = 0.317611;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog19) {
    char b[100] = "0.082844*sin(0.064267)/cos(0.204429)+0.122957";
    double res = 0.128391;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog20) {
    char b[100] = "0.693592*sin(0.095878)/cos(0.756497)+0.765650";
    double res = 0.856951;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog21) {
    char b[100] = "0.811651*sin(0.407601)/cos(0.394129)+0.309671";
    double res = 0.658132;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog22) {
    char b[100] = "0.519679*sin(0.444974)/cos(0.958691)+0.950577";
    double res = 1.339875;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog23) {
    char b[100] = "0.381130*sin(0.870304)/cos(0.499676)+0.202933";
    double res = 0.534904;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog24) {
    char b[100] = "0.591890*sin(0.253085)/cos(0.521724)+0.033059";
    double res = 0.204006;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog25) {
    char b[100] = "0.008886*sin(0.658206)/cos(0.604064)+0.682489";
    double res = 0.689093;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog26) {
    char b[100] = "0.138568*sin(0.045019)/cos(0.281527)+0.356460";
    double res = 0.362952;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog27) {
    char b[100] = "0.131880*sin(0.010093)/cos(0.432994)+0.667893";
    double res = 0.669359;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog28) {
    char b[100] = "0.150860*sin(0.834207)/cos(0.876277)+0.720932";
    double res = 0.895540;
    double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog29) {
    char b[100] = "0.194983*sin(0.156306)/cos(0.368010)+0.409533";
    double res = 0.442064;
    double my_res = 0.0;
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
 
