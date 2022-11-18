#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"

int credit_calculate() {
  long double total_credit_amount, monthly_payment;
  long double term, total_payment, overpayment;
  long double interest_rate;
  // char type;
  // type = 'a';
  total_credit_amount = 100000.0;
  term = 5.0*12.0;
  interest_rate = 0.15;
  //if (type == 'a') {
    total_payment = total_credit_amount + \
                    total_credit_amount * term \
                    * interest_rate;
    monthly_payment = total_payment / term;
    overpayment = total_payment - total_credit_amount;
  // }

  printf("%Lf = total\n%Lf = monthly\n%Lf = overpay",\
      total_payment, monthly_payment, overpayment);
  // result = (total + total*interest*term)
  return total_payment;
}

int deposit_calculate() {
  long double total_credit_amount, monthly_payment;
  long double term, total_payment, overpayment;
  long double interest_rate;
  // char type = 'a';
  total_credit_amount = 100000.0;
  term = 5.0*12.0;
  interest_rate = 0.15;
  // if (type == 'a') {
    total_payment = total_credit_amount + \
                    total_credit_amount * term \
                    * interest_rate;
    monthly_payment = total_payment / term;
    overpayment = total_payment - total_credit_amount;
  // }

  printf("%Lf = total\n%Lf = monthly\n%Lf = overpay",\
      total_payment, monthly_payment, overpayment);
  // result = (total + total*interest*term)
  return 1;
}

// int main() {
//   credit_calculate();
//   return 0;
// }
