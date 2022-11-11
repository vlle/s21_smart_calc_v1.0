
# START_TEST(si) {
#   char funcstr[MAX_ENTRY_SIZE] = {"\0"};
#   char b[100] = "sin(1+4)";  //+2";
#   double res = -0.9589;
#   char *prs = parse_oper(funcstr, b);
#   double my_res = cal_oper(prs);
#   ck_assert_double_eq_tol(res, my_res, 0.0001);
# }
# END_TEST

import random as r

def generate(n):
    #b = r.randrange(0, 100) + r.randrange(0, 100)
    t1 = "START_TEST(add"#) {"
    templ = "char funcstr[MAX_ENTRY_SIZE] = {\"\\0\"};"
    f1_tmpl = "char *prs = parse_oper(funcstr, b);"
    f2_tmpl = "double my_res = cal_oper(prs);"
    f3_tmpl = "ck_assert_double_eq_tol(res, my_res, 0.0001);"
    for i in range(n):
        print(" ")
        num1 = (r.randrange(0, 100) + r.random())
        num2 = (r.randrange(0, 100) + r.random())
        res = (num1+num2)
        op1 = "{:f}".format(num1)
        op2 = "{:f}".format(num2)
        rs_s = "{:f}".format(res)
        char_template = "char b[100] = " + '"' + op1 + ' + ' + op2 + '";' 
        res_template = "double res = " + rs_s + ";"
        print(t1+str(i)+") {")
        print(templ)
        print(char_template)
        print(res_template)
        print(f1_tmpl)
        print(f2_tmpl)
        print(f3_tmpl)
        print("}")
        print("END_TEST")

    for i in range(n):
        print("tcase_add_test(tc_core, si" + str(i) + ");")

generate(30)



# Suite *add_min(void) {
#   Suite *s;
#   TCase *tc_core;
# 
#   s = suite_create("add_min");
#   tc_core = tcase_create("Core");
#   tcase_add_test(tc_core, add_braces);
#   tcase_add_test(tc_core, add_minus);
#   tcase_add_test(tc_core, add);
#   tcase_add_test(tc_core, min);
#   tcase_add_test(tc_core, minA);
#   tcase_add_test(tc_core, min_min);
#   tcase_add_test(tc_core, min_mid);
#   suite_add_tcase(s, tc_core);
# 
#   return s;
# }
