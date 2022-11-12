#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(triglog0) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.771694) / 0.696028 * 0.878083 - 0.181058 + 0.190642";
    double res = -0.132411;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog1) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.070546) / 0.810522 * 0.512242 - 0.617303 + 0.342798";
    double res = -1.002259;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog2) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.426706) / 0.396146 * 0.206840 - 0.831477 + 0.465671";
    double res = -0.558927;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog3) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.575655) / 0.983663 * 0.969351 - 0.151297 + 0.071929";
    double res = -0.315716;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog4) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.553895) / 0.095517 * 0.273025 - 0.491933 + 0.596151";
    double res = -0.629167;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog5) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.490318) / 0.049691 * 0.457098 - 0.676305 + 0.870473";
    double res = -2.653067;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog6) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.288007) / 0.450675 * 0.897544 - 0.622710 + 0.321423";
    double res = -1.377916;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog7) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.411081) / 0.911329 * 0.280090 - 0.979007 + 0.551430";
    double res = -0.546233;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog8) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.994289) / 0.689053 * 0.484593 - 0.973277 + 0.663792";
    double res = -0.311234;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog9) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.945064) / 0.980514 * 0.121795 - 0.555070 + 0.462418";
    double res = -0.095700;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog10) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.452414) / 0.186626 * 0.775637 - 0.201671 + 0.974143";
    double res = -0.659156;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog11) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.416818) / 0.303577 * 0.305216 - 0.787848 + 0.719930";
    double res = -0.450023;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog12) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.813501) / 0.119080 * 0.721254 - 0.608999 + 0.374924";
    double res = -0.777026;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog13) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.394435) / 0.622786 * 0.788984 - 0.283576 + 0.352840";
    double res = -0.442579;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog14) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.872569) / 0.177448 * 0.215584 - 0.958347 + 0.003447";
    double res = -1.026823;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog15) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.317790) / 0.300761 * 0.257557 - 0.805776 + 0.486142";
    double res = -0.745977;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog16) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.472907) / 0.548470 * 0.135422 - 0.667888 + 0.329068";
    double res = -0.419121;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog17) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.641039) / 0.839698 * 0.210525 - 0.589478 + 0.769027";
    double res = 0.131132;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog18) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.497811) / 0.443228 * 0.826221 - 0.625505 + 0.738362";
    double res = -0.451845;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog19) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.184779) / 0.952958 * 0.764634 - 0.788301 + 0.305771";
    double res = -1.070953;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog20) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.660438) / 0.740976 * 0.252583 - 0.748884 + 0.938439";
    double res = 0.128140;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog21) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.362475) / 0.230465 * 0.341872 - 0.772893 + 0.748032";
    double res = -0.678628;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog22) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.477400) / 0.999063 * 0.797596 - 0.228299 + 0.564263";
    double res = 0.079602;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog23) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.691208) / 0.014383 * 0.673902 - 0.999040 + 0.890056";
    double res = -7.623966;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog24) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.425625) / 0.391457 * 0.150946 - 0.583222 + 0.409623";
    double res = -0.316646;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog25) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.734148) / 0.205722 * 0.582545 - 0.072176 + 0.575593";
    double res = 0.123355;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog26) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.645965) / 0.091394 * 0.040582 - 0.473428 + 0.180342";
    double res = -0.377360;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog27) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.102169) / 0.302799 * 0.007448 - 0.414551 + 0.504862";
    double res = 0.065943;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog28) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.375344) / 0.861581 * 0.098139 - 0.095061 + 0.327594";
    double res = 0.184058;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
    ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST
 
START_TEST(triglog29) {
    char funcstr[MAX_ENTRY_SIZE] = {"\0"};
    char b[100] = "log10(0.193594) / 0.060652 * 0.869863 - 0.508548 + 0.072555";
    double res = -10.663296;
    char *prs = parse_oper(funcstr, b);
    double my_res = cal_oper(prs);
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
 
