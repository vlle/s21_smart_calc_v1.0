#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

finance_info credit_calculate(long double total_credit_amount, long double term,
                              long double interest_rate, char type) {
  long double monthly_payment;
  long double total_payment, overpayment;
  long double annuity_coeff;
  finance_info credit = {0};
  long double monthly_inter = interest_rate/12/100;
  annuity_coeff = ((monthly_inter * powl((1+monthly_inter), term))/(powl((1+monthly_inter), term)-1));
  if (type == 'a') {
    monthly_payment = total_credit_amount * annuity_coeff;
    total_payment = monthly_payment * term;
    overpayment = total_payment - total_credit_amount;
  } else {
    return credit;
    // exit(1);
  }

  printf("%Lf = total\n%Lf = monthly\n%Lf = overpay", total_payment,
         monthly_payment, overpayment);
  credit.total_payment = total_payment;
  credit.monthly_payment = monthly_payment;
  credit.overpayment = overpayment;
  return credit;
}

// int deposit_calculate(long double total_credit_amount, long double term,
//                       long double interest_rate, long double tax_rate) {
// //                       long double period_pay, long double
// capitalize_of_interest,
// //                       long double replenishments, long double
// partial_withdrawals) {
//   //long double monthly_payment;
//   // long double total_payment, overpayment;
//   // total_deposit_amount = 100000.0;
//   // term = 5.0 * 12.0;
//   // interest_rate = 0.15;
//   // total_payment =
//   //   total_credit_amount + total_credit_amount * term * interest_rate;
//   // monthly_payment = total_payment / term;
//   // overpayment = total_payment - total_credit_amount;
//
//   // printf("%Lf = total\n%Lf = monthly\n%Lf = overpay", total_payment,
//   //     monthly_payment, overpayment);
//   return 1;
// }
