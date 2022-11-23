#include <check.h>
#include <stdio.h>

#include "../smartcalc.h"

START_TEST(sinus0) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.326490) + 24.301101*23.631646 - (81.789821 - 4.602852)/91.522004";
  double res = 573.752358;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinuscheck) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] = "asin(1) mod 5";
  double res = 1.5707;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus1) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.977620) + 39.654933*87.116366 - (96.784381 - 35.454830)/36.677515";
  double res = 3453.750730;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus2) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.739862) + 15.699122*66.615519 - (75.785447 - 79.562711)/45.279390";
  double res = 1046.562762;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus3) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.038374) + 89.235838*82.246356 - (9.921354 - 31.865116)/86.894443";
  double res = 7339.613418;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus4) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.152204) + 80.103024*7.611410 - (42.490982 - 56.147239)/97.798667";
  double res = 609.988241;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus5) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.050774) + 26.483196*66.971735 - (48.881243 - 14.091957)/34.938743";
  double res = 1772.680612;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus6) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.698229) + 31.447318*37.762177 - (70.523333 - 50.686210)/10.818562";
  double res = 1186.328410;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus7) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.323797) + 67.264651*28.457866 - (39.674909 - 26.829323)/29.778098";
  double res = 1914.095196;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus8) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.094594) + 67.313923*46.548101 - (17.129007 - 5.269701)/15.553354";
  double res = 3132.667253;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus9) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.937055) + 31.082222*20.471899 - (7.968167 - 30.116397)/4.764822";
  double res = 641.766209;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus10) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.232337) + 69.282971*32.409001 - (7.171065 - 15.379003)/99.606497";
  double res = 2245.704516;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus11) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.364556) + 70.124957*12.800306 - (26.698770 - 25.735437)/96.757867";
  double res = 897.967495;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus12) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.612126) + 39.965549*73.351500 - (33.867529 - 64.627546)/5.082563";
  double res = 2938.159643;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus13) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.736886) + 13.006734*40.486102 - (45.164661 - 62.474618)/50.691068";
  double res = 527.605410;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus14) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.891299) + 12.461817*8.853653 - (49.798333 - 11.216809)/93.433047";
  double res = 110.697561;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus15) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.834132) + 18.339489*61.602463 - (88.158132 - 7.835831)/65.670698";
  double res = 1129.275324;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus16) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.696821) + 18.264942*32.920781 - (80.979852 - 81.185390)/54.648810";
  double res = 601.941695;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus17) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.086477) + 41.800915*66.164686 - (85.961855 - 47.550647)/54.983923";
  double res = 2765.132175;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus18) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.410860) + 74.243482*52.932255 - (14.341161 - 99.621049)/71.913266";
  double res = 3931.460164;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus19) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.203212) + 64.619305*71.059790 - (28.186435 - 88.311565)/47.709340";
  double res = 4593.296323;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus20) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.885575) + 74.256406*20.193804 - (9.342508 - 7.094172)/83.832423";
  double res = 1500.266788;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus21) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.964111) + 6.780277*19.323468 - (71.016798 - 28.154509)/44.155801";
  double res = 130.869290;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus22) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.575559) + 42.000615*98.058916 - (0.945149 - 54.568121)/79.958441";
  double res = 4119.749773;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus23) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.857182) + 8.090240*85.258652 - (57.167637 - 2.892933)/40.225659";
  double res = 689.169680;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus24) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.794612) + 33.006390*50.353307 - (55.801959 - 17.682196)/4.471694";
  double res = 1654.169788;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus25) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.680263) + 59.686255*26.217499 - (42.297175 - 78.717321)/91.524421";
  double res = 1565.851283;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus26) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.923580) + 42.391091*94.403755 - (46.644601 - 70.210000)/82.691980";
  double res = 4002.960862;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus27) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.763294) + 3.164812*5.343672 - (31.543999 - 52.258247)/75.772929";
  double res = 17.876396;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus28) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.293570) + 88.205368*43.045309 - (78.292761 - 23.447758)/88.633260";
  double res = 3796.497933;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus29) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.465229) + 34.529746*72.167756 - (20.423897 - 18.818996)/17.061736";
  double res = 2492.288840;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus30) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.316934) + 78.871555*67.703517 - (78.105305 - 58.675845)/14.922791";
  double res = 5338.891305;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus31) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.608921) + 96.425632*40.327720 - (81.869093 - 88.481530)/64.700672";
  double res = 3889.300114;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus32) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.365496) + 45.284096*81.532379 - (22.793817 - 29.262539)/54.570732";
  double res = 3692.596057;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus33) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.208821) + 55.473778*6.467527 - (74.322635 - 33.468243)/35.671123";
  double res = 357.840136;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus34) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.481157) + 23.450773*9.752485 - (65.432769 - 16.398011)/78.445015";
  double res = 228.541031;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus35) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.984830) + 75.775391*50.057078 - (66.694735 - 65.339603)/14.784360";
  double res = 3793.836146;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus36) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.855275) + 69.137420*42.813030 - (60.298767 - 45.825526)/68.338419";
  double res = 2960.525364;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus37) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.276406) + 7.367771*72.816822 - (5.492075 - 47.531746)/84.269915";
  double res = 537.269423;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus38) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.497642) + 16.419464*6.859205 - (14.699063 - 90.592001)/48.006579";
  double res = 114.682713;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus39) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.836837) + 97.917054*54.632226 - (18.362512 - 43.019314)/97.791012";
  double res = 5350.421340;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus40) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.171973) + 92.440800*55.894843 - (13.626250 - 87.055809)/30.205632";
  double res = 5169.566168;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus41) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.492743) + 20.607356*53.288552 - (82.530057 - 1.232376)/91.897423";
  double res = 1097.724546;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus42) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.256544) + 8.666275*23.573869 - (26.187464 - 7.678315)/62.357795";
  double res = 204.254549;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus43) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.400856) + 23.835973*49.722526 - (4.256983 - 46.843281)/82.654472";
  double res = 1186.090244;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus44) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.016180) + 34.528933*22.460497 - (58.302972 - 8.881728)/10.411858";
  double res = 770.806534;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus45) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.474931) + 49.722471*14.732009 - (75.097690 - 78.148032)/96.515015";
  double res = 733.000771;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus46) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.943798) + 96.274082*95.026014 - (92.375751 - 51.311710)/25.852330";
  double res = 9147.763609;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus47) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.941269) + 73.861752*95.633392 - (99.141606 - 62.474224)/95.704349";
  double res = 7064.074978;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus48) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.102595) + 34.074524*2.531518 - (46.937329 - 9.827566)/76.466047";
  double res = 85.877390;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus49) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.314382) + 87.562010*80.738411 - (45.373867 - 1.860918)/73.067987";
  double res = 7069.331346;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus50) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.478082) + 35.519512*74.483369 - (15.208001 - 79.413875)/71.451514";
  double res = 2646.971617;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus51) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.052082) + 75.080480*6.766240 - (24.367023 - 13.685224)/23.425034";
  double res = 507.608568;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus52) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.928941) + 15.689776*15.890540 - (1.451775 - 92.332683)/77.684773";
  double res = 251.289865;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus53) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.202723) + 12.497427*32.914929 - (49.650346 - 72.201034)/81.834556";
  double res = 411.828810;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus54) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.943688) + 80.294941*87.266385 - (17.226987 - 78.968514)/89.591785";
  double res = 7008.548101;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus55) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.209178) + 88.136037*62.998369 - (10.129588 - 8.377440)/21.404292";
  double res = 5552.552409;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus56) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.603246) + 2.870377*24.639982 - (29.656503 - 94.378937)/15.703727";
  double res = 75.414831;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus57) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.498664) + 53.441480*57.533339 - (6.077388 - 8.182965)/16.564654";
  double res = 3075.272116;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus58) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.891994) + 2.922202*4.227023 - (82.785591 - 17.500516)/55.820019";
  double res = 11.960976;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus59) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.099500) + 90.692559*7.877599 - (97.261987 - 51.994989)/36.543659";
  double res = 713.300260;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus60) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.402605) + 9.957664*43.143026 - (74.336114 - 63.764949)/98.427894";
  double res = 429.888179;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus61) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.694096) + 91.774889*31.412110 - (75.157546 - 80.029169)/23.070489";
  double res = 2883.693759;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus62) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.080764) + 62.967581*13.047933 - (74.328230 - 52.374614)/99.516781";
  double res = 821.456848;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus63) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.543961) + 74.246315*64.325327 - (22.718381 - 93.943574)/14.899040";
  double res = 4781.216522;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus64) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.520434) + 93.996433*92.793850 - (72.461755 - 62.295455)/58.100274";
  double res = 8722.613126;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus65) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.385633) + 36.694911*47.621385 - (57.014020 - 75.475335)/96.153855";
  double res = 1748.030657;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus66) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.708064) + 86.206242*99.099162 - (22.334120 - 48.196696)/60.114721";
  double res = 8544.046930;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus67) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.803758) + 34.911668*50.284876 - (56.947266 - 88.969840)/53.308005";
  double res = 1756.849584;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus68) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.386838) + 53.653506*81.177200 - (97.110412 - 72.570612)/51.635076";
  double res = 4355.343405;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus69) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.425620) + 86.458010*61.931049 - (82.944929 - 65.690532)/1.598683";
  double res = 5344.055270;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus70) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.661837) + 17.283378*93.497689 - (92.224591 - 65.476841)/25.811586";
  double res = 1615.534212;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus71) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.382949) + 50.897592*11.880000 - (48.774681 - 10.715952)/88.925851";
  double res = 604.609070;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus72) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.978045) + 42.713825*90.877081 - (61.284027 - 84.493443)/90.080236";
  double res = 3882.794772;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus73) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.355301) + 28.765140*83.758998 - (45.471150 - 85.429246)/70.173212";
  double res = 2410.256588;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus74) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.533916) + 16.757654*59.189346 - (36.038690 - 49.533537)/57.600986";
  double res = 992.617791;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus75) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.604784) + 62.306409*51.934361 - (64.607306 - 27.802889)/50.230071";
  double res = 3235.679440;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus76) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.978180) + 16.253477*30.397498 - (31.989145 - 32.599924)/56.155840";
  double res = 494.905399;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus77) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.788094) + 0.112751*70.318997 - (96.459156 - 34.474756)/75.875399";
  double res = 7.820605;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus78) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.729907) + 28.303903*82.286052 - (28.955511 - 51.901834)/43.577525";
  double res = 2330.209777;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus79) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.432135) + 42.643559*79.595760 - (30.233433 - 20.160497)/97.703377";
  double res = 3394.562193;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus80) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.153369) + 47.624713*39.310069 - (38.946637 - 45.662673)/77.610809";
  double res = 1872.370081;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus81) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.499778) + 44.125396*16.396183 - (93.840674 - 11.842545)/41.809418";
  double res = 722.006082;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus82) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.364294) + 49.339508*91.714657 - (47.709405 - 90.563929)/32.951682";
  double res = 4526.812885;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus83) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.796640) + 56.497884*38.139178 - (10.156198 - 43.914427)/58.027732";
  double res = 2156.079632;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus84) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.342197) + 96.170069*48.284106 - (15.268423 - 60.981029)/3.210277";
  double res = 4658.060805;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus85) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.467583) + 95.798055*52.637080 - (78.260033 - 42.163046)/62.663465";
  double res = 5042.404628;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus86) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.851180) + 39.971361*10.056840 - (55.761556 - 79.056138)/13.562989";
  double res = 404.455142;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus87) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.696411) + 14.282639*19.279091 - (4.142698 - 17.217822)/49.499038";
  double res = 276.261917;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus88) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.050361) + 76.647358*11.176123 - (25.463088 - 98.957682)/99.122044";
  double res = 857.412096;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus89) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.419751) + 7.067842*60.950610 - (46.729042 - 36.308996)/41.560488";
  double res = 430.946065;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus90) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.283800) + 3.340061*53.368203 - (87.783340 - 31.487781)/17.696086";
  double res = 175.351800;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus91) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.565578) + 8.699732*89.351843 - (57.918829 - 85.984163)/46.707880";
  double res = 778.473854;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus92) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.931032) + 25.018858*52.488900 - (3.099936 - 4.439229)/87.175471";
  double res = 1314.029969;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus93) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.146589) + 19.655522*82.742142 - (49.874422 - 2.334332)/80.171467";
  double res = 1625.893031;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus94) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.483636) + 62.555093*11.643120 - (54.573052 - 11.864024)/59.717826";
  double res = 728.086272;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus95) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.875321) + 25.958359*51.027122 - (90.408591 - 10.650101)/72.993723";
  double res = 1324.255427;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus96) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.026222) + 4.227205*85.393205 - (92.939365 - 70.764138)/51.562905";
  double res = 360.570769;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus97) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.240507) + 93.147674*52.442045 - (26.623763 - 26.195081)/31.901646";
  double res = 4885.079305;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus98) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.178326) + 64.608022*77.164989 - (90.002446 - 47.790984)/56.268347";
  double res = 4984.904500;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus99) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.496182) + 61.344552*23.076809 - (56.844821 - 18.766211)/45.094625";
  double res = 1415.268201;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus100) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.002409) + 10.680122*92.670395 - (5.035755 - 73.195617)/30.246912";
  double res = 991.987018;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus101) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.279668) + 67.415035*57.653227 - (4.745945 - 0.823328)/24.048521";
  double res = 3886.807218;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus102) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.845438) + 8.912912*49.777782 - (89.205204 - 8.486886)/4.960450";
  double res = 428.140867;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus103) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.913990) + 44.504070*21.468421 - (47.723229 - 37.632489)/51.830770";
  double res = 956.029345;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus104) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.974251) + 97.796908*5.532915 - (15.349925 - 57.570368)/25.147900";
  double res = 543.608180;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus105) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.788394) + 57.780059*70.353339 - (31.691967 - 1.067324)/31.003763";
  double res = 4064.741512;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus106) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.234366) + 45.650645*83.476322 - (3.842894 - 44.728864)/37.250221";
  double res = 3812.077798;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus107) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.259172) + 99.220022*71.352281 - (44.135910 - 41.263709)/40.810551";
  double res = 7079.760787;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus108) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.714039) + 15.421433*10.259205 - (11.755953 - 81.924838)/25.359663";
  double res = 161.633484;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus109) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.899146) + 35.776514*69.695376 - (89.551545 - 34.549240)/75.335678";
  double res = 2493.510312;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus110) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.295947) + 98.453777*80.058881 - (37.422902 - 46.787206)/58.581470";
  double res = 7882.550720;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus111) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.468081) + 46.597177*35.946893 - (70.308952 - 86.046086)/44.133962";
  double res = 1675.831521;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus112) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.345309) + 87.345243*71.541843 - (43.306830 - 89.712593)/10.064531";
  double res = 6253.788996;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus113) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.861537) + 84.362600*25.752413 - (66.893601 - 9.381040)/80.393726";
  double res = 2172.584010;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus114) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.268427) + 11.460410*86.952282 - (63.009055 - 77.929999)/50.260067";
  double res = 997.070866;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus115) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.745364) + 65.029060*40.015905 - (80.771991 - 40.118592)/15.825795";
  double res = 2600.306104;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus116) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.433547) + 36.753936*0.095233 - (15.488675 - 66.999204)/33.322895";
  double res = 5.466068;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus117) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.373226) + 52.451913*76.417883 - (18.852489 - 13.395375)/68.869215";
  double res = 4008.549544;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus118) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.631628) + 37.844524*61.172061 - (61.173940 - 54.125151)/47.400505";
  double res = 2315.469282;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus119) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.777391) + 70.100313*50.983741 - (57.779567 - 30.241356)/44.264912";
  double res = 3574.055530;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus120) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.805952) + 23.386829*29.724499 - (59.975580 - 27.577564)/29.913424";
  double res = 694.800217;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus121) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.515388) + 25.730257*79.142143 - (88.868194 - 44.057555)/44.759666";
  double res = 2035.839407;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus122) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.513408) + 16.834353*6.910487 - (31.609865 - 6.951936)/93.850346";
  double res = 116.561998;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus123) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.855562) + 48.683887*71.233558 - (9.751381 - 63.304191)/53.704414";
  double res = 3469.678570;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus124) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.933910) + 39.615494*88.210918 - (1.657584 - 9.638301)/37.290179";
  double res = 3495.537072;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus125) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.939897) + 22.814406*32.593804 - (81.687029 - 91.427077)/92.898554";
  double res = 744.520624;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus126) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.469118) + 76.366631*79.887483 - (77.564474 - 19.349646)/69.447946";
  double res = 6100.351777;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus127) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.753378) + 8.762521*11.059957 - (17.291505 - 85.958242)/27.651601";
  double res = 100.080497;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus128) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.638628) + 44.581853*96.079286 - (47.704595 - 15.426156)/6.137751";
  double res = 4278.729694;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus129) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.676403) + 22.778640*91.547041 - (14.928442 - 57.875912)/83.563327";
  double res = 2086.457045;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus131) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.006389) + 93.841369*60.521378 - (31.495719 - 72.380264)/1.064212";
  double res = 5717.832998;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus132) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.443720) + 70.975587*20.828008 - (80.034411 - 15.935519)/57.153615";
  double res = 1477.587847;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus133) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.005302) + 43.266595*96.941597 - (57.808657 - 95.804564)/7.896315";
  double res = 4199.149967;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus134) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.550842) + 90.170122*99.388202 - (42.298218 - 56.806376)/78.811026";
  double res = 8962.553879;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus135) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.030504) + 0.600902*46.677731 - (68.705363 - 46.380512)/24.304354";
  double res = 27.160679;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus136) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.068113) + 61.399279*97.238606 - (5.146521 - 15.623830)/0.891878";
  double res = 5982.195842;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus137) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.802898) + 27.194293*90.769096 - (95.347650 - 29.487135)/58.171341";
  double res = 2467.988635;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus138) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.447197) + 34.695634*79.410968 - (67.790939 - 72.233150)/89.789721";
  double res = 2755.695780;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus139) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.371778) + 86.885532*38.479658 - (36.751884 - 86.235131)/8.930059";
  double res = 3349.230078;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus140) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.278009) + 65.780324*93.830867 - (61.366396 - 24.857712)/36.272992";
  double res = 6171.492848;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus141) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.942264) + 97.784537*96.073462 - (31.652553 - 18.727760)/47.488119";
  double res = 9395.035723;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus142) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.887478) + 97.709314*57.070496 - (10.300736 - 71.791406)/71.126193";
  double res = 5577.959030;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus143) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.406729) + 86.171129*92.431289 - (62.601551 - 21.621014)/2.307562";
  double res = 7947.544930;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus144) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.014335) + 35.387824*13.544857 - (78.057253 - 43.379696)/89.223090";
  double res = 478.948677;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus145) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.093790) + 46.433303*27.000119 - (30.844499 - 76.579713)/32.803675";
  double res = 1255.192563;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus146) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.111629) + 42.100498*78.446820 - (69.881072 - 59.327627)/36.090996";
  double res = 3302.469131;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus147) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.304807) + 36.884026*66.319635 - (38.785961 - 8.769303)/96.696661";
  double res = 2446.124818;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus148) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.406236) + 69.315255*76.008788 - (6.177456 - 90.407312)/94.606393";
  double res = 5269.854004;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus149) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.712744) + 86.414721*65.899073 - (1.651829 - 63.108957)/61.868462";
  double res = 5696.297295;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus150) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.473215) + 23.763936*32.009581 - (45.449298 - 6.700481)/30.594496";
  double res = 759.862854;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus151) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.754996) + 73.104782*67.039172 - (14.825968 - 9.497014)/9.412656";
  double res = 4901.003157;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus152) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.342485) + 68.979565*20.489437 - (37.445890 - 78.909422)/9.162016";
  double res = 1418.213870;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus153) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.042311) + 70.041830*33.863192 - (54.864856 - 20.167822)/3.009979";
  double res = 2360.354935;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus154) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.285817) + 86.180487*47.753675 - (61.528326 - 85.308063)/10.092275";
  double res = 4118.073172;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus155) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.360691) + 82.444943*60.161315 - (79.000219 - 14.851954)/30.559039";
  double res = 4958.249960;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus156) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.101649) + 75.005966*54.598006 - (63.978391 - 96.566089)/96.018451";
  double res = 4095.617057;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus157) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.004595) + 50.496121*15.189634 - (12.325228 - 34.398612)/21.808153";
  double res = 768.034350;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus158) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.569650) + 82.221268*21.722446 - (87.134692 - 48.043638)/56.751796";
  double res = 1785.897599;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus159) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.369099) + 55.742714*78.822719 - (46.014318 - 26.540378)/68.913588";
  double res = 4393.870427;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus160) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.640071) + 21.908738*55.819679 - (41.859272 - 1.880637)/62.509256";
  double res = 1222.896407;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus161) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.902745) + 57.451673*99.887861 - (4.849056 - 59.492687)/84.857424";
  double res = 5740.153710;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus162) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.923633) + 93.785083*26.950551 - (54.790736 - 24.619625)/19.904048";
  double res = 2526.841647;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus163) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.453642) + 61.826413*79.125706 - (58.111120 - 43.167578)/76.754459";
  double res = 4892.302129;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus164) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.045466) + 25.064643*48.625568 - (29.084346 - 89.208412)/56.052498";
  double res = 1219.900583;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus165) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.010988) + 93.320821*25.948002 - (11.256339 - 64.466237)/58.550867";
  double res = 2422.408582;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus166) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.016775) + 18.463538*68.917736 - (78.719655 - 5.536908)/13.044803";
  double res = 1266.871885;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus167) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.216239) + 22.207445*46.886938 - (35.421774 - 26.058307)/19.151850";
  double res = 1040.964769;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus168) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.739998) + 49.488985*93.688760 - (75.938184 - 91.182842)/94.032142";
  double res = 4637.398015;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus169) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.191648) + 70.053976*20.711032 - (48.152874 - 23.413047)/23.379822";
  double res = 1450.022461;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus170) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.416647) + 25.448478*32.871128 - (8.033964 - 18.330913)/32.641208";
  double res = 837.240317;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus171) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.648535) + 47.304229*73.063379 - (81.775053 - 36.199206)/39.118604";
  double res = 3455.645725;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus172) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.947686) + 48.231177*29.479036 - (93.183051 - 87.362179)/88.701775";
  double res = 1422.555058;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus173) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.031004) + 23.553393*90.188213 - (22.236143 - 97.359964)/20.304906";
  double res = 2127.969230;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus174) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.506850) + 92.048369*61.947049 - (56.494187 - 57.921689)/40.919292";
  double res = 5702.645201;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus175) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.173322) + 47.818426*35.187555 - (92.173404 - 32.145850)/10.347930";
  double res = 1676.985041;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus176) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.962606) + 38.165324*69.087944 - (15.918091 - 32.630850)/67.929111";
  double res = 2637.830485;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus177) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.976076) + 58.148316*83.383257 - (2.013767 - 79.621510)/58.579718";
  double res = 4850.749081;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus178) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.623883) + 79.562607*18.508183 - (97.114170 - 64.021601)/75.911681";
  double res = 1472.707590;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus179) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.738741) + 96.153752*57.119370 - (76.547487 - 7.782954)/61.896711";
  double res = 5491.804119;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus180) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.478967) + 50.803356*9.774539 - (9.697065 - 34.758371)/35.148090";
  double res = 497.753287;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus181) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.278806) + 97.117208*30.412755 - (18.391254 - 79.497417)/46.443229";
  double res = 2955.192811;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus182) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.488463) + 97.228954*26.585152 - (99.052212 - 10.511052)/22.276165";
  double res = 2581.341068;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus183) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.909815) + 61.097084*82.039704 - (1.222541 - 16.126686)/2.755353";
  double res = 5018.585292;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus184) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.083240) + 13.706692*12.930073 - (31.534640 - 55.046146)/8.183311";
  double res = 180.184775;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus185) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.522438) + 97.105645*49.510803 - (72.810687 - 9.403453)/7.887212";
  double res = 4800.238207;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus186) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.737482) + 35.507419*12.309635 - (92.253613 - 84.378566)/65.480103";
  double res = 437.635513;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus187) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.934922) + 85.065998*8.952134 - (62.954223 - 49.747884)/61.698977";
  double res = 762.112755;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus188) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.834474) + 63.013585*63.450048 - (2.999812 - 47.800995)/19.219438";
  double res = 4001.286922;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus189) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.933457) + 47.171727*62.483027 - (0.451672 - 67.992495)/63.199764";
  double res = 2949.304637;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus190) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.980399) + 88.935456*55.038571 - (37.570501 - 31.135886)/52.753655";
  double res = 4895.589178;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus191) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.823648) + 40.874164*75.011598 - (42.629282 - 56.729704)/96.212386";
  double res = 3066.916530;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus192) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.654552) + 27.394457*52.257218 - (57.945972 - 25.033467)/46.139332";
  double res = 1431.453587;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus193) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.517194) + 99.063360*90.007061 - (45.813000 - 89.792413)/81.104815";
  double res = 8917.438514;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus194) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.600330) + 25.306685*88.713487 - (72.904510 - 49.921463)/89.497611";
  double res = 2245.352381;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus195) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.779845) + 26.780239*66.929253 - (94.954828 - 11.548251)/11.887912";
  double res = 1786.068500;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus196) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.766929) + 65.198066*32.541298 - (42.246874 - 17.175767)/69.774270";
  double res = 2121.964277;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus197) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.695673) + 52.858407*18.024002 - (19.495404 - 74.860468)/43.392126";
  double res = 954.636841;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus198) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.995478) + 15.584027*40.266654 - (11.067110 - 76.294929)/23.026790";
  double res = 631.188353;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus199) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.627412) + 33.017281*80.520837 - (89.976094 - 79.578840)/42.058078";
  double res = 2658.918960;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus200) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.465402) + 53.643407*60.534193 - (91.290933 - 81.623871)/22.658177";
  double res = 3247.282447;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus201) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.106366) + 68.550251*40.681686 - (84.533940 - 39.750262)/60.119760";
  double res = 2788.101000;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus202) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.430925) + 94.644459*7.944450 - (21.052586 - 9.849985)/11.404122";
  double res = 751.333559;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus203) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.347212) + 89.500472*56.440340 - (21.405513 - 51.922757)/63.186506";
  double res = 5052.260306;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus204) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.844313) + 16.409857*86.705415 - (58.232774 - 98.909393)/79.069874";
  double res = 1424.085422;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus205) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.799400) + 73.449450*82.828489 - (10.038123 - 66.915156)/43.801915";
  double res = 6085.722447;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus206) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.485007) + 81.837361*33.514067 - (48.946781 - 12.068055)/74.465563";
  double res = 2742.673766;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus207) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.495760) + 68.645935*76.105104 - (85.083561 - 64.264519)/71.302690";
  double res = 5224.489788;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus208) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.017254) + 25.236893*37.370941 - (66.040853 - 55.061201)/82.970922";
  double res = 943.011356;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus209) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.405383) + 58.160197*57.135514 - (86.918737 - 8.795251)/67.467195";
  double res = 3322.249180;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus210) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.317442) + 58.023304*16.464790 - (68.124068 - 88.352032)/95.346920";
  double res = 955.865791;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus211) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.152106) + 0.028115*69.029580 - (82.094994 - 99.722216)/50.289268";
  double res = 2.442824;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus212) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.904863) + 21.329515*29.147827 - (21.535345 - 76.639626)/96.926969";
  double res = 623.063851;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus213) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.169067) + 43.661807*57.422959 - (41.277260 - 33.712807)/83.812228";
  double res = 2507.268140;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus214) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.316046) + 1.986106*0.227593 - (15.776107 - 38.373083)/94.384139";
  double res = 1.002250;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus215) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.651700) + 12.076768*19.812418 - (59.708689 - 89.552451)/72.401441";
  double res = 240.288712;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus216) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.255764) + 27.250033*43.585182 - (24.463465 - 79.938462)/98.285571";
  double res = 1188.515054;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus217) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.662900) + 94.128395*73.647710 - (39.456049 - 89.187408)/15.635915";
  double res = 6936.136704;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus218) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.647780) + 62.610643*94.355320 - (96.375571 - 32.659512)/64.319011";
  double res = 5907.260094;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus219) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.353022) + 57.722557*19.103705 - (39.977483 - 80.146430)/92.296804";
  double res = 1103.495659;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus220) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.644514) + 32.114263*77.216814 - (12.580215 - 18.168912)/27.815097";
  double res = 2480.562832;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus221) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.738817) + 45.125657*74.297204 - (31.600935 - 34.121278)/38.445307";
  double res = 3353.449129;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus222) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.921605) + 31.561395*32.955823 - (19.343183 - 26.497689)/35.647984";
  double res = 1041.129012;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus223) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.680555) + 87.382297*41.170397 - (5.560879 - 16.285992)/2.369008";
  double res = 3602.720338;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus224) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.642401) + 76.738358*35.090525 - (11.537840 - 16.627204)/78.030706";
  double res = 2693.453639;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus225) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.622667) + 48.504494*81.238740 - (8.032150 - 55.346228)/54.752141";
  double res = 3941.891362;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus226) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.844975) + 38.430424*43.324588 - (20.502602 - 76.107953)/60.236681";
  double res = 1666.653362;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus227) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.012826) + 5.011593*24.424584 - (3.217212 - 94.478015)/65.923455";
  double res = 123.803246;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus228) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.878447) + 8.770861*28.129338 - (88.364682 - 62.301385)/32.771216";
  double res = 246.692953;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus229) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.567681) + 13.559388*44.238512 - (56.270627 - 62.361028)/38.423682";
  double res = 600.543335;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus230) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.325010) + 45.542870*73.513052 - (56.322351 - 87.444784)/18.224288";
  double res = 3350.022436;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus231) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.890404) + 50.247892*67.381077 - (86.082597 - 10.228585)/79.279418";
  double res = 3385.577587;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus232) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.913685) + 18.561280*67.930912 - (61.474603 - 98.955513)/51.643082";
  double res = 1262.402183;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus233) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.526822) + 45.484990*40.688350 - (14.648312 - 32.493672)/11.367471";
  double res = 1852.781814;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus234) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.571047) + 7.796207*53.344440 - (56.531402 - 0.800032)/15.244572";
  double res = 412.768997;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus235) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.284146) + 70.444089*65.047966 - (66.345573 - 4.901274)/40.730029";
  double res = 4581.016484;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus236) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.924860) + 52.265501*60.726702 - (40.038721 - 38.582042)/13.588686";
  double res = 3174.602817;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus237) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.439734) + 59.137127*99.483619 - (52.814819 - 94.745079)/16.522126";
  double res = 5886.138969;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus238) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.934548) + 77.001783*28.778237 - (98.243248 - 13.273742)/39.859285";
  double res = 2214.648116;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus239) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.685378) + 92.995248*32.174103 - (22.812309 - 58.356435)/29.148904";
  double res = 2993.891031;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus240) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.675319) + 98.120314*21.459541 - (4.840753 - 40.283523)/59.375204";
  double res = 2106.838969;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus241) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.381621) + 98.583113*89.811164 - (29.776422 - 5.298090)/92.679298";
  double res = 8853.972375;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus242) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.094076) + 28.930398*69.493450 - (25.396497 - 11.125533)/60.579205";
  double res = 2010.331566;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus243) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.769926) + 54.166369*94.633441 - (0.456632 - 0.155915)/22.621907";
  double res = 5126.632639;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus244) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.898418) + 35.340238*82.170927 - (2.658407 - 52.921328)/83.496132";
  double res = 2905.324456;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus245) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.574899) + 52.083423*11.294709 - (7.631482 - 39.634164)/23.334469";
  double res = 590.182357;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus246) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.879963) + 12.018546*26.608456 - (10.612923 - 69.785680)/60.919793";
  double res = 321.536995;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus247) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.972338) + 53.739778*98.251741 - (18.775201 - 92.003555)/98.512293";
  double res = 5281.596255;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus248) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.368260) + 78.491579*61.332776 - (85.843959 - 41.603146)/98.895530";
  double res = 4814.019047;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus249) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.399640) + 4.911726*26.268199 - (64.514104 - 52.482612)/51.614169";
  double res = 129.178188;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus250) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.915560) + 7.122110*37.854620 - (5.143054 - 89.368492)/99.551537";
  double res = 271.243712;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus251) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.741100) + 8.309133*45.110869 - (66.370328 - 9.839565)/81.385163";
  double res = 374.812710;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus252) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.868640) + 11.348295*13.920207 - (87.090050 - 81.075428)/35.977637";
  double res = 158.566889;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus253) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.614350) + 25.608175*98.794124 - (99.497931 - 35.096691)/80.108693";
  double res = 2529.709707;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus254) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.974396) + 61.044387*13.388718 - (40.236455 - 12.655161)/88.051578";
  double res = 817.820228;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus255) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.693901) + 67.894802*5.543470 - (26.690644 - 19.383058)/66.697798";
  double res = 376.902750;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus256) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.429440) + 67.672439*82.024692 - (17.466690 - 1.707714)/73.623381";
  double res = 5551.013313;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus257) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.202056) + 15.326174*61.962723 - (82.403719 - 90.752009)/3.030560";
  double res = 952.606829;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus258) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.416893) + 43.568324*15.134387 - (8.158194 - 26.934974)/2.683377";
  double res = 666.782248;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus259) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.243372) + 70.441252*74.242824 - (24.087882 - 38.079472)/89.328993";
  double res = 5230.155076;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus260) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.401883) + 91.628121*88.109825 - (57.072471 - 81.136929)/27.117350";
  double res = 8074.616295;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus261) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.394016) + 64.927497*31.200592 - (47.895257 - 66.256918)/69.554530";
  double res = 2026.424253;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus262) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.600123) + 12.721422*1.717547 - (87.057633 - 86.766627)/68.288433";
  double res = 22.410118;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus263) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.734705) + 37.673574*48.771932 - (19.436428 - 80.528979)/53.065298";
  double res = 1839.234637;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus264) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.671931) + 34.908216*74.381516 - (84.621811 - 91.284237)/89.692938";
  double res = 2597.222792;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus265) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.128019) + 0.064376*9.262952 - (66.535035 - 92.840226)/0.723580";
  double res = 37.078187;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus266) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.789191) + 56.088600*33.312483 - (50.883814 - 65.605994)/69.198202";
  double res = 1869.373071;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus267) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.885124) + 20.448035*66.380004 - (29.166131 - 19.527446)/90.435398";
  double res = 1358.008025;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus268) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.043929) + 62.505874*10.900341 - (29.331214 - 89.180204)/65.475712";
  double res = 682.293299;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus269) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.372010) + 3.520495*64.178228 - (62.449765 - 69.797389)/76.768401";
  double res = 226.398332;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus270) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.008820) + 53.760269*97.418074 - (76.770927 - 35.881948)/64.012755";
  double res = 5236.591967;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus271) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.208895) + 79.017948*53.236256 - (63.733148 - 74.897307)/64.387963";
  double res = 4207.000466;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus272) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.741860) + 43.692264*7.014069 - (94.722214 - 23.139404)/61.969681";
  double res = 305.981106;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus273) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.630135) + 58.624371*46.062320 - (52.211613 - 10.816240)/85.777459";
  double res = 2700.481232;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus274) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.721053) + 89.963483*83.410358 - (55.641447 - 91.752015)/63.104576";
  double res = 7505.118689;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus275) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.402249) + 79.398327*10.014815 - (29.276364 - 19.803324)/8.613315";
  double res = 794.451200;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus276) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.429212) + 21.942253*41.446354 - (35.591633 - 98.784076)/43.969200";
  double res = 911.279741;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus277) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.313683) + 79.156885*16.524656 - (69.629825 - 69.469264)/53.523852";
  double res = 1308.345896;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus278) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.531904) + 63.023704*96.773020 - (55.554121 - 52.198165)/67.630782";
  double res = 6099.451706;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus279) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.701158) + 5.792972*64.533967 - (0.664430 - 81.512917)/55.485006";
  double res = 375.945675;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus280) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.094825) + 63.977453*69.851921 - (38.692999 - 0.547090)/57.534338";
  double res = 4468.379631;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus281) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.559120) + 36.437562*19.917513 - (20.870776 - 4.790788)/52.009443";
  double res = 725.966900;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus282) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.850458) + 95.096259*22.822675 - (82.103919 - 74.124343)/79.687703";
  double res = 2171.002508;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus283) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.911739) + 27.129032*7.481131 - (84.868753 - 19.542436)/22.804640";
  double res = 200.881806;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus284) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.949040) + 28.018052*78.052633 - (34.749245 - 94.930559)/70.720460";
  double res = 2188.546584;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus285) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.853137) + 58.928114*15.139163 - (55.207352 - 10.420903)/30.810846";
  double res = 891.422047;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus286) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.384386) + 16.355017*47.605399 - (46.788784 - 82.344208)/29.469128";
  double res = 780.168643;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus287) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.103290) + 31.443779*23.033871 - (67.137856 - 81.437192)/47.753557";
  double res = 724.674509;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus288) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.428782) + 64.704559*43.158514 - (25.223180 - 33.580458)/83.683917";
  double res = 2793.068225;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus289) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.303129) + 19.359832*82.157835 - (95.838850 - 95.580044)/6.621670";
  double res = 1590.821347;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus290) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.923568) + 9.594610*56.394395 - (8.277062 - 38.446251)/29.767517";
  double res = 542.893504;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus291) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.342586) + 85.573096*1.642315 - (2.733239 - 48.363661)/81.224572";
  double res = 141.435722;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus292) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.817678) + 96.225716*25.981211 - (18.327560 - 17.343879)/28.357048";
  double res = 2500.755500;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus293) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.915136) + 2.348083*66.764272 - (43.915456 - 49.986130)/85.551773";
  double res = 157.631639;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus294) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.973357) + 4.363284*31.369357 - (10.372505 - 26.405301)/31.787216";
  double res = 138.204576;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus295) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.311933) + 28.697291*57.819496 - (65.983392 - 39.848019)/53.376410";
  double res = 1659.080131;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus296) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.508762) + 65.153443*82.055505 - (59.581509 - 71.200273)/36.811019";
  double res = 5347.001404;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus297) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.952486) + 32.821705*67.852995 - (16.366695 - 4.629152)/23.416092";
  double res = 2227.364605;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus298) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.052830) + 97.141914*16.041416 - (83.000743 - 55.303372)/89.047082";
  double res = 1558.035620;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

START_TEST(sinus299) {
  char funcstr[MAX_ENTRY_SIZE] = {"\0"};
  char b[100] =
      "sin(0.168387) + 96.122012*70.489424 - (62.122012 - 70.761360)/67.916168";
  double res = 6775.880037;
  char *prs = parse_oper(funcstr, b);
  double my_res = cal_oper(prs);
  ck_assert_double_eq_tol(res, my_res, 0.0001);
}
END_TEST

Suite *sinus_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sinus");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, sinus0);
  tcase_add_test(tc_core, sinus1);
  tcase_add_test(tc_core, sinus2);
  tcase_add_test(tc_core, sinus3);
  tcase_add_test(tc_core, sinus4);
  tcase_add_test(tc_core, sinus5);
  tcase_add_test(tc_core, sinus6);
  tcase_add_test(tc_core, sinus7);
  tcase_add_test(tc_core, sinus8);
  tcase_add_test(tc_core, sinus9);
  tcase_add_test(tc_core, sinus10);
  tcase_add_test(tc_core, sinus11);
  tcase_add_test(tc_core, sinus12);
  tcase_add_test(tc_core, sinus13);
  tcase_add_test(tc_core, sinus14);
  tcase_add_test(tc_core, sinus15);
  tcase_add_test(tc_core, sinus16);
  tcase_add_test(tc_core, sinus17);
  tcase_add_test(tc_core, sinus18);
  tcase_add_test(tc_core, sinus19);
  tcase_add_test(tc_core, sinus20);
  tcase_add_test(tc_core, sinus21);
  tcase_add_test(tc_core, sinus22);
  tcase_add_test(tc_core, sinus23);
  tcase_add_test(tc_core, sinus24);
  tcase_add_test(tc_core, sinus25);
  tcase_add_test(tc_core, sinus26);
  tcase_add_test(tc_core, sinus27);
  tcase_add_test(tc_core, sinus28);
  tcase_add_test(tc_core, sinus29);
  tcase_add_test(tc_core, sinus30);
  tcase_add_test(tc_core, sinus31);
  tcase_add_test(tc_core, sinus32);
  tcase_add_test(tc_core, sinus33);
  tcase_add_test(tc_core, sinus34);
  tcase_add_test(tc_core, sinus35);
  tcase_add_test(tc_core, sinus36);
  tcase_add_test(tc_core, sinus37);
  tcase_add_test(tc_core, sinus38);
  tcase_add_test(tc_core, sinus39);
  tcase_add_test(tc_core, sinus40);
  tcase_add_test(tc_core, sinus41);
  tcase_add_test(tc_core, sinus42);
  tcase_add_test(tc_core, sinus43);
  tcase_add_test(tc_core, sinus44);
  tcase_add_test(tc_core, sinus45);
  tcase_add_test(tc_core, sinus46);
  tcase_add_test(tc_core, sinus47);
  tcase_add_test(tc_core, sinus48);
  tcase_add_test(tc_core, sinus49);
  tcase_add_test(tc_core, sinus50);
  tcase_add_test(tc_core, sinus51);
  tcase_add_test(tc_core, sinus52);
  tcase_add_test(tc_core, sinus53);
  tcase_add_test(tc_core, sinus54);
  tcase_add_test(tc_core, sinus55);
  tcase_add_test(tc_core, sinus56);
  tcase_add_test(tc_core, sinus57);
  tcase_add_test(tc_core, sinus58);
  tcase_add_test(tc_core, sinus59);
  tcase_add_test(tc_core, sinus60);
  tcase_add_test(tc_core, sinus61);
  tcase_add_test(tc_core, sinus62);
  tcase_add_test(tc_core, sinus63);
  tcase_add_test(tc_core, sinus64);
  tcase_add_test(tc_core, sinus65);
  tcase_add_test(tc_core, sinus66);
  tcase_add_test(tc_core, sinus67);
  tcase_add_test(tc_core, sinus68);
  tcase_add_test(tc_core, sinus69);
  tcase_add_test(tc_core, sinus70);
  tcase_add_test(tc_core, sinus71);
  tcase_add_test(tc_core, sinus72);
  tcase_add_test(tc_core, sinus73);
  tcase_add_test(tc_core, sinus74);
  tcase_add_test(tc_core, sinus75);
  tcase_add_test(tc_core, sinus76);
  tcase_add_test(tc_core, sinus77);
  tcase_add_test(tc_core, sinus78);
  tcase_add_test(tc_core, sinus79);
  tcase_add_test(tc_core, sinus80);
  tcase_add_test(tc_core, sinus81);
  tcase_add_test(tc_core, sinus82);
  tcase_add_test(tc_core, sinus83);
  tcase_add_test(tc_core, sinus84);
  tcase_add_test(tc_core, sinus85);
  tcase_add_test(tc_core, sinus86);
  tcase_add_test(tc_core, sinus87);
  tcase_add_test(tc_core, sinus88);
  tcase_add_test(tc_core, sinus89);
  tcase_add_test(tc_core, sinus90);
  tcase_add_test(tc_core, sinus91);
  tcase_add_test(tc_core, sinus92);
  tcase_add_test(tc_core, sinus93);
  tcase_add_test(tc_core, sinus94);
  tcase_add_test(tc_core, sinus95);
  tcase_add_test(tc_core, sinus96);
  tcase_add_test(tc_core, sinus97);
  tcase_add_test(tc_core, sinus98);
  tcase_add_test(tc_core, sinus99);
  tcase_add_test(tc_core, sinus100);
  tcase_add_test(tc_core, sinus101);
  tcase_add_test(tc_core, sinus102);
  tcase_add_test(tc_core, sinus103);
  tcase_add_test(tc_core, sinus104);
  tcase_add_test(tc_core, sinus105);
  tcase_add_test(tc_core, sinus106);
  tcase_add_test(tc_core, sinus107);
  tcase_add_test(tc_core, sinus108);
  tcase_add_test(tc_core, sinus109);
  tcase_add_test(tc_core, sinus110);
  tcase_add_test(tc_core, sinus111);
  tcase_add_test(tc_core, sinus112);
  tcase_add_test(tc_core, sinus113);
  tcase_add_test(tc_core, sinus114);
  tcase_add_test(tc_core, sinus115);
  tcase_add_test(tc_core, sinus116);
  tcase_add_test(tc_core, sinus117);
  tcase_add_test(tc_core, sinus118);
  tcase_add_test(tc_core, sinus119);
  tcase_add_test(tc_core, sinus120);
  tcase_add_test(tc_core, sinus121);
  tcase_add_test(tc_core, sinus122);
  tcase_add_test(tc_core, sinus123);
  tcase_add_test(tc_core, sinus124);
  tcase_add_test(tc_core, sinus125);
  tcase_add_test(tc_core, sinus126);
  tcase_add_test(tc_core, sinus127);
  tcase_add_test(tc_core, sinus128);
  tcase_add_test(tc_core, sinus129);
  tcase_add_test(tc_core, sinus131);
  tcase_add_test(tc_core, sinus132);
  tcase_add_test(tc_core, sinus133);
  tcase_add_test(tc_core, sinus134);
  tcase_add_test(tc_core, sinus135);
  tcase_add_test(tc_core, sinus136);
  tcase_add_test(tc_core, sinus137);
  tcase_add_test(tc_core, sinus138);
  tcase_add_test(tc_core, sinus139);
  tcase_add_test(tc_core, sinus140);
  tcase_add_test(tc_core, sinus141);
  tcase_add_test(tc_core, sinus142);
  tcase_add_test(tc_core, sinus143);
  tcase_add_test(tc_core, sinus144);
  tcase_add_test(tc_core, sinus145);
  tcase_add_test(tc_core, sinus146);
  tcase_add_test(tc_core, sinus147);
  tcase_add_test(tc_core, sinus148);
  tcase_add_test(tc_core, sinus149);
  tcase_add_test(tc_core, sinus150);
  tcase_add_test(tc_core, sinus151);
  tcase_add_test(tc_core, sinus152);
  tcase_add_test(tc_core, sinus153);
  tcase_add_test(tc_core, sinus154);
  tcase_add_test(tc_core, sinus155);
  tcase_add_test(tc_core, sinus156);
  tcase_add_test(tc_core, sinus157);
  tcase_add_test(tc_core, sinus158);
  tcase_add_test(tc_core, sinus159);
  tcase_add_test(tc_core, sinus160);
  tcase_add_test(tc_core, sinus161);
  tcase_add_test(tc_core, sinus162);
  tcase_add_test(tc_core, sinus163);
  tcase_add_test(tc_core, sinus164);
  tcase_add_test(tc_core, sinus165);
  tcase_add_test(tc_core, sinus166);
  tcase_add_test(tc_core, sinus167);
  tcase_add_test(tc_core, sinus168);
  tcase_add_test(tc_core, sinus169);
  tcase_add_test(tc_core, sinus170);
  tcase_add_test(tc_core, sinus171);
  tcase_add_test(tc_core, sinus172);
  tcase_add_test(tc_core, sinus173);
  tcase_add_test(tc_core, sinus174);
  tcase_add_test(tc_core, sinus175);
  tcase_add_test(tc_core, sinus176);
  tcase_add_test(tc_core, sinus177);
  tcase_add_test(tc_core, sinus178);
  tcase_add_test(tc_core, sinus179);
  tcase_add_test(tc_core, sinus180);
  tcase_add_test(tc_core, sinus181);
  tcase_add_test(tc_core, sinus182);
  tcase_add_test(tc_core, sinus183);
  tcase_add_test(tc_core, sinus184);
  tcase_add_test(tc_core, sinus185);
  tcase_add_test(tc_core, sinus186);
  tcase_add_test(tc_core, sinus187);
  tcase_add_test(tc_core, sinus188);
  tcase_add_test(tc_core, sinus189);
  tcase_add_test(tc_core, sinus190);
  tcase_add_test(tc_core, sinus191);
  tcase_add_test(tc_core, sinus192);
  tcase_add_test(tc_core, sinus193);
  tcase_add_test(tc_core, sinus194);
  tcase_add_test(tc_core, sinus195);
  tcase_add_test(tc_core, sinus196);
  tcase_add_test(tc_core, sinus197);
  tcase_add_test(tc_core, sinus198);
  tcase_add_test(tc_core, sinus199);
  tcase_add_test(tc_core, sinus200);
  tcase_add_test(tc_core, sinus201);
  tcase_add_test(tc_core, sinus202);
  tcase_add_test(tc_core, sinus203);
  tcase_add_test(tc_core, sinus204);
  tcase_add_test(tc_core, sinus205);
  tcase_add_test(tc_core, sinus206);
  tcase_add_test(tc_core, sinus207);
  tcase_add_test(tc_core, sinus208);
  tcase_add_test(tc_core, sinus209);
  tcase_add_test(tc_core, sinus210);
  tcase_add_test(tc_core, sinus211);
  tcase_add_test(tc_core, sinus212);
  tcase_add_test(tc_core, sinus213);
  tcase_add_test(tc_core, sinus214);
  tcase_add_test(tc_core, sinus215);
  tcase_add_test(tc_core, sinus216);
  tcase_add_test(tc_core, sinus217);
  tcase_add_test(tc_core, sinus218);
  tcase_add_test(tc_core, sinus219);
  tcase_add_test(tc_core, sinus220);
  tcase_add_test(tc_core, sinus221);
  tcase_add_test(tc_core, sinus222);
  tcase_add_test(tc_core, sinus223);
  tcase_add_test(tc_core, sinus224);
  tcase_add_test(tc_core, sinus225);
  tcase_add_test(tc_core, sinus226);
  tcase_add_test(tc_core, sinus227);
  tcase_add_test(tc_core, sinus228);
  tcase_add_test(tc_core, sinus229);
  tcase_add_test(tc_core, sinus230);
  tcase_add_test(tc_core, sinus231);
  tcase_add_test(tc_core, sinus232);
  tcase_add_test(tc_core, sinus233);
  tcase_add_test(tc_core, sinus234);
  tcase_add_test(tc_core, sinus235);
  tcase_add_test(tc_core, sinus236);
  tcase_add_test(tc_core, sinus237);
  tcase_add_test(tc_core, sinus238);
  tcase_add_test(tc_core, sinus239);
  tcase_add_test(tc_core, sinus240);
  tcase_add_test(tc_core, sinus241);
  tcase_add_test(tc_core, sinus242);
  tcase_add_test(tc_core, sinus243);
  tcase_add_test(tc_core, sinus244);
  tcase_add_test(tc_core, sinus245);
  tcase_add_test(tc_core, sinus246);
  tcase_add_test(tc_core, sinus247);
  tcase_add_test(tc_core, sinus248);
  tcase_add_test(tc_core, sinus249);
  tcase_add_test(tc_core, sinus250);
  tcase_add_test(tc_core, sinus251);
  tcase_add_test(tc_core, sinus252);
  tcase_add_test(tc_core, sinus253);
  tcase_add_test(tc_core, sinus254);
  tcase_add_test(tc_core, sinus255);
  tcase_add_test(tc_core, sinus256);
  tcase_add_test(tc_core, sinus257);
  tcase_add_test(tc_core, sinus258);
  tcase_add_test(tc_core, sinus259);
  tcase_add_test(tc_core, sinus260);
  tcase_add_test(tc_core, sinus261);
  tcase_add_test(tc_core, sinus262);
  tcase_add_test(tc_core, sinus263);
  tcase_add_test(tc_core, sinus264);
  tcase_add_test(tc_core, sinus265);
  tcase_add_test(tc_core, sinus266);
  tcase_add_test(tc_core, sinus267);
  tcase_add_test(tc_core, sinus268);
  tcase_add_test(tc_core, sinus269);
  tcase_add_test(tc_core, sinus270);
  tcase_add_test(tc_core, sinus271);
  tcase_add_test(tc_core, sinus272);
  tcase_add_test(tc_core, sinus273);
  tcase_add_test(tc_core, sinus274);
  tcase_add_test(tc_core, sinus275);
  tcase_add_test(tc_core, sinus276);
  tcase_add_test(tc_core, sinus277);
  tcase_add_test(tc_core, sinus278);
  tcase_add_test(tc_core, sinus279);
  tcase_add_test(tc_core, sinus280);
  tcase_add_test(tc_core, sinus281);
  tcase_add_test(tc_core, sinus282);
  tcase_add_test(tc_core, sinus283);
  tcase_add_test(tc_core, sinus284);
  tcase_add_test(tc_core, sinus285);
  tcase_add_test(tc_core, sinus286);
  tcase_add_test(tc_core, sinus287);
  tcase_add_test(tc_core, sinus288);
  tcase_add_test(tc_core, sinus289);
  tcase_add_test(tc_core, sinus290);
  tcase_add_test(tc_core, sinus291);
  tcase_add_test(tc_core, sinus292);
  tcase_add_test(tc_core, sinus293);
  tcase_add_test(tc_core, sinus294);
  tcase_add_test(tc_core, sinus295);
  tcase_add_test(tc_core, sinus296);
  tcase_add_test(tc_core, sinus297);
  tcase_add_test(tc_core, sinus298);
  tcase_add_test(tc_core, sinus299);
  tcase_add_test(tc_core, sinuscheck);
  suite_add_tcase(s, tc_core);

  return s;
}
