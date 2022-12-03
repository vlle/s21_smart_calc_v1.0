#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"
 
START_TEST(triglog0) {
    char b[100] = "3+sin(0.230669)";
    double res = 3.228629;
    long double my_res = 0.0;
    int ret = calculate(b, &my_res);
    ck_assert_double_eq_tol(res, my_res, 0.00001);
}
END_TEST

Suite *triglog_suite(void) {
   Suite *s;
   TCase *tc_core;
 
   s = suite_create("triglog");
   tc_core = tcase_create("Core");
   tcase_add_test(tc_core, triglog0);
   suite_add_tcase(s, tc_core);

   return s;
}
 
