#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

finance_t put_data(long double total_credit_amount, long double term,
                   long double interest_rate, char type,
                   long double days_with_cred) {
  finance_t credit = {0};
  credit.total_credit_amount = total_credit_amount;
  credit.term = term;
  credit.interest_rate = interest_rate;
  credit.type_credit = type;
  credit.days_with_cred = days_with_cred + 1;
  if (type == 'b') {
    credit.diff_payment_part = credit.total_credit_amount / term;
    credit.remainder_credit = credit.total_credit_amount;
  }
  return credit;
}

finance_t credit_calculate(finance_t credit) {
  long double monthly_inter = credit.interest_rate / 12 / 100;
  char type = credit.type_credit;
  if (type == 'a') {
    long double annuity_coeff =
        ((monthly_inter * powl((1 + monthly_inter), credit.term)) /
         (powl((1 + monthly_inter), credit.term) - 1));
    credit.monthly_payment = credit.total_credit_amount * annuity_coeff;
    credit.total_payment = credit.monthly_payment * credit.term;
    credit.overpayment = credit.total_payment - credit.total_credit_amount;
  } else if (type == 'b') {
    long double percent_sum =
        (credit.remainder_credit) * (credit.interest_rate / 100 / 12);
    credit.monthly_payment = (credit.diff_payment_part + percent_sum);
    credit.overpayment += credit.monthly_payment;
    credit.total_payment = credit.remainder_credit;  // + credit.overpayment;
    credit.remainder_credit -= credit.diff_payment_part;
  }
  return credit;
}
