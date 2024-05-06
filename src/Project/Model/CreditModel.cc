#include "CreditModel.h"

s21::CreditModel::CreditModel() {}

s21::CreditModel::~CreditModel() {}

bool s21::CreditModel::CreditCalc(const double &Sum, const double &Span,
                                  const double &Percent,
                                  double *Monthly_payment, double *Overpayment,
                                  double *Overall_payment,
                                  double *first_payment, bool r1, int combo) {
  bool res = 0;
  if (Sum == 0 || Span == 0 || Percent == 0) {
    res = 1;
  } else {
    double percent_monthly = 0, b = 0, sn = 0, p = 0, month_payment = 0,
           diffsum = 0;
    int span = Span;
    if (combo == 0) {
      span *= 12;
    }
    if (r1) {
      percent_monthly = Percent / 100 / 12;
      month_payment =
          Sum * (percent_monthly / (1 - pow((1 + percent_monthly), -span)));
      *Monthly_payment = month_payment;
      *Overpayment = (span * month_payment) - Sum;
      *Overall_payment = span * month_payment;
    } else {
      b = Sum / span;
      for (int i = 0; i < span; i++) {
        sn = Sum - (b * i);
        p = sn * Percent / 100 / 12;
        month_payment = b + p;
        if (i == 0) {
          *first_payment = month_payment;
        }
        diffsum += month_payment;
      }
      *Monthly_payment = month_payment;
      *Overpayment = diffsum - Sum;
      *Overall_payment = diffsum;
    }
  }
  return res;
}
