#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

finance_info put_data(long double total_credit_amount, long double term,
                              long double interest_rate, char type, long double days_with_cred) {
  finance_info credit = {0};
  credit.total_credit_amount = total_credit_amount;
  credit.term = term;
  credit.interest_rate = interest_rate;
  credit.type_credit = type;
  credit.days_with_cred = days_with_cred + 1;
  if (type == 'b') {
    credit.diff_payment_part = credit.total_credit_amount / term;
  }
  return credit;
}

finance_info credit_calculate(finance_info credit) {
  long double annuity_coeff;
  long double monthly_inter = credit.interest_rate/12/100;
  char type = credit.type_credit;
  if (type == 'a') {
    annuity_coeff = ((monthly_inter * powl((1+monthly_inter), credit.term))/(powl((1+monthly_inter), credit.term)-1));
    credit.monthly_payment = credit.total_credit_amount * annuity_coeff;
    credit.total_payment = credit.monthly_payment * credit.term;
    credit.overpayment = credit.total_payment - credit.total_credit_amount;
  } else if (type == 'b') {
    credit.diff_payment_part = credit.total_credit_amount / credit.term;
    credit.pay_percent = credit.total_credit_amount * credit.interest_rate/1200;
    credit.monthly_payment = credit.diff_payment_part + credit.pay_percent;
    credit.overpayment += credit.pay_percent;
    credit.total_payment = credit.overpayment + credit.total_credit_amount;
  }

  printf("%Lf = total\n%Lf = monthly\n%Lf = overpay", credit.total_payment,
         credit.monthly_payment, credit.overpayment);
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
