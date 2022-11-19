#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(trigfinal0) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.937916)-tan(0.728347)-cos(0.618675)+0.417929/0.124192";
  double res = 2.464919;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal1) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.910108)-tan(0.344575)-cos(0.493508)+0.495932/0.432373";
  double res = 0.697001;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal2) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.569191)-tan(0.874786)-cos(0.414418)+0.221808/0.549269";
  double res = -1.169477;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal3) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.334753)-tan(0.102912)-cos(0.243374)+0.605066/0.665709";
  double res = 0.163633;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal4) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.799176)-tan(0.969706)-cos(0.945703)+0.527356/0.485268";
  double res = -0.239941;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal5) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.207616)-tan(0.416848)-cos(0.433332)+0.164121/0.639804";
  double res = -0.887724;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal6) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.128582)-tan(0.834323)-cos(0.917392)+0.680000/0.087872";
  double res = 6.155894;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal7) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.337003)-tan(0.182797)-cos(0.869755)+0.702865/0.840287";
  double res = 0.337244;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal8) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.543832)-tan(0.323817)-cos(0.250368)+0.071488/0.734519";
  double res = -0.689707;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal9) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.744226)-tan(0.028075)-cos(0.823374)+0.647588/0.125506";
  double res = 5.129387;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal10) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.782667)-tan(0.301327)-cos(0.201969)+0.351211/0.826920";
  double res = -0.160570;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal11) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.097048)-tan(0.730874)-cos(0.229277)+0.719193/0.204327";
  double res = 1.746386;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal12) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.480970)-tan(0.958532)-cos(0.955634)+0.555241/0.010810";
  double res = 49.825289;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal13) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.597205)-tan(0.078048)-cos(0.412633)+0.312458/0.969282";
  double res = -0.109581;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal14) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.268774)-tan(0.038868)-cos(0.297280)+0.637111/0.397336";
  double res = 0.873982;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal15) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.192047)-tan(0.644681)-cos(0.016723)+0.797315/0.352125";
  double res = 0.703459;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal16) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.776047)-tan(0.704726)-cos(0.336042)+0.530183/0.251934";
  double res = 1.010449;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal17) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.484398)-tan(0.459377)-cos(0.322693)+0.719547/0.678412";
  double res = 0.083252;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal18) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.632424)-tan(0.218944)-cos(0.489712)+0.938686/0.615677";
  double res = 1.010763;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal19) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.143895)-tan(0.473244)-cos(0.542719)+0.822348/0.052801";
  double res = 14.349515;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal20) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.836002)-tan(0.112058)-cos(0.969134)+0.151477/0.944329";
  double res = 0.223833;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal21) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.980693)-tan(0.176372)-cos(0.844446)+0.625694/0.982958";
  double res = 0.625056;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal22) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.047708)-tan(0.634364)-cos(0.317483)+0.369710/0.862889";
  double res = -1.209698;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal23) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.227417)-tan(0.102409)-cos(0.362016)+0.326427/0.109519";
  double res = 2.168060;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal24) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.360580)-tan(0.833620)-cos(0.565761)+0.047719/0.866067";
  double res = -1.537678;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal25) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.248821)-tan(0.340091)-cos(0.609999)+0.331105/0.146896";
  double res = 1.326783;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal26) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.380248)-tan(0.018059)-cos(0.961193)+0.788104/0.491340";
  double res = 1.384537;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal27) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.796216)-tan(0.790568)-cos(0.460255)+0.099583/0.945560";
  double res = -1.086302;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal28) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.477926)-tan(0.825987)-cos(0.200872)+0.443728/0.685034";
  double res = -0.956869;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(trigfinal29) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "sin(0.168821)-tan(0.398058)-cos(0.376194)+0.013693/0.453977";
  double res = -1.152393;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *trigfinal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("trigfinal");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, trigfinal0);
  tcase_add_test(tc_core, trigfinal1);
  tcase_add_test(tc_core, trigfinal2);
  tcase_add_test(tc_core, trigfinal3);
  tcase_add_test(tc_core, trigfinal4);
  tcase_add_test(tc_core, trigfinal5);
  tcase_add_test(tc_core, trigfinal6);
  tcase_add_test(tc_core, trigfinal7);
  tcase_add_test(tc_core, trigfinal8);
  tcase_add_test(tc_core, trigfinal9);
  tcase_add_test(tc_core, trigfinal10);
  tcase_add_test(tc_core, trigfinal11);
  tcase_add_test(tc_core, trigfinal12);
  tcase_add_test(tc_core, trigfinal13);
  tcase_add_test(tc_core, trigfinal14);
  tcase_add_test(tc_core, trigfinal15);
  tcase_add_test(tc_core, trigfinal16);
  tcase_add_test(tc_core, trigfinal17);
  tcase_add_test(tc_core, trigfinal18);
  tcase_add_test(tc_core, trigfinal19);
  tcase_add_test(tc_core, trigfinal20);
  tcase_add_test(tc_core, trigfinal21);
  tcase_add_test(tc_core, trigfinal22);
  tcase_add_test(tc_core, trigfinal23);
  tcase_add_test(tc_core, trigfinal24);
  tcase_add_test(tc_core, trigfinal25);
  tcase_add_test(tc_core, trigfinal26);
  tcase_add_test(tc_core, trigfinal27);
  tcase_add_test(tc_core, trigfinal28);
  tcase_add_test(tc_core, trigfinal29);
  suite_add_tcase(s, tc_core);

  return s;
}
