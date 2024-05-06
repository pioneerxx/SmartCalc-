#ifndef SRC_CONTROLLER_CREDITCONTROLLER_H
#define SRC_CONTROLLER_CREDITCONTROLLER_H

#include <QComboBox>
#include <QLabel>
#include <QRadioButton>
#include <QSpinBox>

#include "../Model/CreditModel.h"

namespace s21 {
class CreditController {
 public:
  CreditController(CreditModel *m);
  ~CreditController();
  void CreditCalc(const QDoubleSpinBox &Sum, const QSpinBox &Span,
                  const QDoubleSpinBox &Percent, QLabel *Monthly_payment,
                  QLabel *Overpayment, QLabel *Overall_payment,
                  QRadioButton *r1, QComboBox *combo);

 private:
  CreditModel *model;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CREDITCONTROLLER_H
