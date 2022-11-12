#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(logmult0) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.805975)-0.139754*0.144249/0.309381+0.289350";
    double res = 0.008487;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult1) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.335134)-0.318961*0.115961/0.598988+0.090296";
    double res = -1.064678;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult2) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.155069)-0.023242*0.819911/0.516939+0.023041";
    double res = -1.877708;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult3) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.609818)-0.433903*0.078244/0.695537+0.357147";
    double res = -0.186259;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult4) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.025804)-0.373321*0.524278/0.125319+0.764571";
    double res = -4.454461;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult5) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.874475)-0.192465*0.710097/0.290224+0.578728";
    double res = -0.026312;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult6) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.274902)-0.774133*0.104552/0.719224+0.236281";
    double res = -1.167594;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult7) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.885335)-0.846480*0.016177/0.020267+0.378159";
    double res = -0.419286;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult8) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.517567)-0.675657*0.714893/0.656752+0.042328";
    double res = -1.351760;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult9) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.224705)-0.797456*0.567140/0.193719+0.201173";
    double res = -3.626460;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult10) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.039418)-0.108588*0.259300/0.011768+0.047448";
    double res = -5.578749;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult11) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.999907)-0.323028*0.605610/0.611499+0.807615";
    double res = 0.487605;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult12) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.784767)-0.650183*0.358083/0.115630+0.561122";
    double res = -1.694733;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult13) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.061380)-0.457227*0.850168/0.012349+0.584079";
    double res = -33.684426;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult14) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.833233)-0.751992*0.980861/0.873747+0.229406";
    double res = -0.797216;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult15) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.486871)-0.039318*0.200401/0.536659+0.698449";
    double res = -0.035989;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult16) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.838495)-0.768590*0.531529/0.387857+0.261185";
    double res = -0.968257;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult17) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.277545)-0.211132*0.137471/0.140869+0.517222";
    double res = -0.970589;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult18) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.370724)-0.867405*0.092458/0.757485+0.090391";
    double res = -1.007781;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult19) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.545999)-0.419896*0.336409/0.708930+0.611079";
    double res = -0.193313;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult20) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.791994)-0.553004*0.939851/0.480104+0.570394";
    double res = -0.745367;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult21) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.352392)-0.910487*0.638359/0.858166+0.688069";
    double res = -1.032221;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult22) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.930272)-0.993711*0.766234/0.867827+0.390261";
    double res = -0.559399;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult23) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.630092)-0.201814*0.450143/0.564760+0.594072";
    double res = -0.028674;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult24) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.824831)-0.227954*0.703720/0.706686+0.086428";
    double res = -0.333146;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult25) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.530754)-0.458921*0.952466/0.267355+0.279060";
    double res = -1.989326;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult26) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.604926)-0.254660*0.310007/0.569382+0.718274";
    double res = 0.076972;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult27) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.533412)-0.712335*0.990647/0.055349+0.424656";
    double res = -12.953313;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult28) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.339395)-0.045877*0.319126/0.368272+0.032335";
    double res = -1.088010;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(logmult29) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "ln(0.648361)-0.690132*0.395019/0.776216+0.652791";
    double res = -0.131727;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
Suite *logmult_suite(void) {
   Suite *s;
   TCase *tc_core;
 
   s = suite_create("logmult");
   tc_core = tcase_create("Core");
   tcase_add_test(tc_core, logmult0);
   tcase_add_test(tc_core, logmult1);
   tcase_add_test(tc_core, logmult2);
   tcase_add_test(tc_core, logmult3);
   tcase_add_test(tc_core, logmult4);
   tcase_add_test(tc_core, logmult5);
   tcase_add_test(tc_core, logmult6);
   tcase_add_test(tc_core, logmult7);
   tcase_add_test(tc_core, logmult8);
   tcase_add_test(tc_core, logmult9);
   tcase_add_test(tc_core, logmult10);
   tcase_add_test(tc_core, logmult11);
   tcase_add_test(tc_core, logmult12);
   tcase_add_test(tc_core, logmult13);
   tcase_add_test(tc_core, logmult14);
   tcase_add_test(tc_core, logmult15);
   tcase_add_test(tc_core, logmult16);
   tcase_add_test(tc_core, logmult17);
   tcase_add_test(tc_core, logmult18);
   tcase_add_test(tc_core, logmult19);
   tcase_add_test(tc_core, logmult20);
   tcase_add_test(tc_core, logmult21);
   tcase_add_test(tc_core, logmult22);
   tcase_add_test(tc_core, logmult23);
   tcase_add_test(tc_core, logmult24);
   tcase_add_test(tc_core, logmult25);
   tcase_add_test(tc_core, logmult26);
   tcase_add_test(tc_core, logmult27);
   tcase_add_test(tc_core, logmult28);
   tcase_add_test(tc_core, logmult29);
   suite_add_tcase(s, tc_core);

   return s;
}
 
