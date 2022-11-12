
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
import math as m

def generate(n, name):
    #b = r.randrange(0, 100) + r.randrange(0, 100)
    inc1 = "#include <check.h>"
    inc2 = "#include <stdio.h>"
    inc3 = ""
    inc4 = "#include \"../smartcalc.h\""
    print(inc1)
    print(inc2)
    print(inc3)
    print(inc4)
    t1 = f"START_TEST({name}"#) {"
    templ = "    char funcstr[MAX_ENTRY_SIZE] = {\"\\0\"};"
    f1_tmpl = "    char *prs = parse_oper(funcstr, b);"
    f2_tmpl = "    double my_res = cal_oper(prs);"
    f3_tmpl = "    ck_assert_double_eq_tol(res, my_res, 0.0001);"

    f4_tmpl = f"Suite *{name}_suite(void) " +"{"
    f5_tmpl = "   Suite *s;"
    f6_tmpl = "   TCase *tc_core;"
    f7_tmpl = " "
    f8_tmpl = f"   s = suite_create(\"{name}\");"
    f9_tmpl = "   tc_core = tcase_create(\"Core\");"
    f10_tmpl = "   suite_add_tcase(s, tc_core);"
    f11_tmpl = ""
    f12_tmpl = "   return s;"
    f13_tmpl = "}"


    for i in range(n):
        print(" ")
        num1 = (r.randrange(0, 1) + r.random())
        ns = m.sin(num1)
        num2 = (r.randrange(0, 100) + r.random())
        num23 = (r.randrange(0, 100) + r.random())
        num3 = (r.randrange(0, 100) + r.random())
        num4 = (r.randrange(0, 100) + r.random())
        num5 = (r.randrange(0, 100) + r.random())
        res = (ns+num2*num23-(num3-num4) / num5)
        op1 = "{:f}".format(num1)
        op2 = "{:f}".format(num2)
        op23 = "{:f}".format(num23)
        op3 = "{:f}".format(num3)
        op4 = "{:f}".format(num4)
        op5 = "{:f}".format(num5)
        rs_s = "{:f}".format(res)
        char_template = f"    char b[100] = \"sin({op1}) + {op2}*{op23} - ({op3} - {op4})/{op5}\";"
        res_template = "    double res = " + rs_s + ";"
        print(t1+str(i)+") {")
        print(templ)
        print(char_template)
        print(res_template)
        print(f1_tmpl)
        print(f2_tmpl)
        print(f3_tmpl)
        print("}")
        print("END_TEST")

    print(" ")
    print(f4_tmpl)
    print(f5_tmpl)
    print(f6_tmpl)
    print(f7_tmpl)
    print(f8_tmpl)
    print(f9_tmpl)
    for i in range(n):
        print(f"   tcase_add_test(tc_core, {name}" + str(i) + ");")

    print(f10_tmpl)
    print(f11_tmpl)
    print(f12_tmpl)
    print(f13_tmpl)
    print(" ")


generate(300, "sinus")



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
