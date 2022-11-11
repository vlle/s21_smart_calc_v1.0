#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(minusminus0) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "17.819610 + 48.863934 - 70.027590 - 7.931815";
    double res = -11.275861;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus1) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "36.144026 + 60.455943 - 22.564395 - 59.866714";
    double res = 14.168860;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus2) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "50.263301 + 97.171943 - 37.401503 - 98.435455";
    double res = 11.598286;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus3) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "63.035228 + 2.032984 - 1.271522 - 89.720626";
    double res = -25.923937;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus4) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "17.665739 + 25.903685 - 98.610121 - 42.418581";
    double res = -97.459279;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus5) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "92.190617 + 69.478089 - 70.466597 - 77.780548";
    double res = 13.421561;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus6) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "86.421369 + 76.343652 - 51.416270 - 2.372124";
    double res = 108.976627;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus7) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "99.408204 + 92.959939 - 23.504277 - 47.404900";
    double res = 121.458965;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus8) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "28.140894 + 13.467648 - 6.468939 - 2.017474";
    double res = 33.122130;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus9) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "2.520749 + 94.837529 - 53.803863 - 65.883053";
    double res = -22.328639;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus10) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "13.876560 + 86.636427 - 86.361123 - 31.888962";
    double res = -17.737097;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus11) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "62.716872 + 12.037802 - 71.789279 - 91.977416";
    double res = -89.012020;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus12) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "26.321208 + 57.078988 - 34.801180 - 28.063225";
    double res = 20.535791;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus13) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "53.771453 + 78.814658 - 8.232050 - 99.009194";
    double res = 25.344867;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus14) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "60.902575 + 80.761924 - 79.011303 - 80.049448";
    double res = -17.396252;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus15) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "20.156646 + 26.050067 - 58.523925 - 26.259104";
    double res = -38.576315;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus16) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "37.622500 + 55.555132 - 42.261444 - 6.092551";
    double res = 44.823638;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus17) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "90.981622 + 57.293313 - 83.280297 - 95.333455";
    double res = -30.338817;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus18) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "28.932821 + 22.914466 - 78.817806 - 39.714671";
    double res = -66.685189;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus19) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "57.996845 + 26.048917 - 35.681302 - 89.142191";
    double res = -40.777732;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus20) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "38.451193 + 90.434431 - 53.275237 - 32.321511";
    double res = 43.288876;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus21) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "74.073369 + 14.624711 - 97.815846 - 72.296976";
    double res = -81.414742;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus22) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "79.963078 + 9.010302 - 49.327908 - 37.652998";
    double res = 1.992473;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus23) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "2.785168 + 2.451017 - 91.091306 - 90.698809";
    double res = -176.553930;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus24) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "8.947939 + 33.970348 - 59.806636 - 48.573903";
    double res = -65.462253;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus25) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "6.502914 + 47.169962 - 90.044853 - 82.213594";
    double res = -118.585570;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus26) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "17.748790 + 82.226198 - 28.930840 - 36.744848";
    double res = 34.299301;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus27) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "24.571173 + 83.048966 - 74.965233 - 83.086195";
    double res = -50.431289;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus28) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "59.538725 + 30.943482 - 91.319247 - 94.261885";
    double res = -95.098925;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(minusminus29) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "81.815500 + 18.127398 - 75.015604 - 48.277390";
    double res = -23.350095;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
Suite *minusminus_suite(void) {
   Suite *s;
   TCase *tc_core;
 
   s = suite_create("minusminus");
   tc_core = tcase_create("Core");
   tcase_add_test(tc_core, minusminus0);
   tcase_add_test(tc_core, minusminus1);
   tcase_add_test(tc_core, minusminus2);
   tcase_add_test(tc_core, minusminus3);
   tcase_add_test(tc_core, minusminus4);
   tcase_add_test(tc_core, minusminus5);
   tcase_add_test(tc_core, minusminus6);
   tcase_add_test(tc_core, minusminus7);
   tcase_add_test(tc_core, minusminus8);
   tcase_add_test(tc_core, minusminus9);
   tcase_add_test(tc_core, minusminus10);
   tcase_add_test(tc_core, minusminus11);
   tcase_add_test(tc_core, minusminus12);
   tcase_add_test(tc_core, minusminus13);
   tcase_add_test(tc_core, minusminus14);
   tcase_add_test(tc_core, minusminus15);
   tcase_add_test(tc_core, minusminus16);
   tcase_add_test(tc_core, minusminus17);
   tcase_add_test(tc_core, minusminus18);
   tcase_add_test(tc_core, minusminus19);
   tcase_add_test(tc_core, minusminus20);
   tcase_add_test(tc_core, minusminus21);
   tcase_add_test(tc_core, minusminus22);
   tcase_add_test(tc_core, minusminus23);
   tcase_add_test(tc_core, minusminus24);
   tcase_add_test(tc_core, minusminus25);
   tcase_add_test(tc_core, minusminus26);
   tcase_add_test(tc_core, minusminus27);
   tcase_add_test(tc_core, minusminus28);
   tcase_add_test(tc_core, minusminus29);
   suite_add_tcase(s, tc_core);

   return s;
}
 
