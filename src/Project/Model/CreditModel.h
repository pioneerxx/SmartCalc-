#ifndef SRC_MODEL_CREDITMODEL_H
#define SRC_MODEL_CREDITMODEL_H

#include <cmath>

namespace s21 {
class CreditModel {
 public:
  CreditModel();
  ~CreditModel();
  bool CreditCalc(const double &Sum, const double &Span, const double &Percent,
                  double *Monthly_payment, double *Overpayment,
                  double *Overall_payment, double *first_payment, bool r1,
                  int combo);

 private:
};
}  // namespace s21

#endif  // SRC_MODEL_CREDITMODEL_H
