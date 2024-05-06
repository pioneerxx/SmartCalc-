#include "CreditController.h"

s21::CreditController::CreditController(CreditModel *m) { model = m; }

s21::CreditController::~CreditController() {}

void s21::CreditController::CreditCalc(
    const QDoubleSpinBox &Sum, const QSpinBox &Span,
    const QDoubleSpinBox &Percent, QLabel *Monthly_payment, QLabel *Overpayment,
    QLabel *Overall_payment, QRadioButton *r1, QComboBox *combo) {
  double monthly_payment = 0, overpayment = 0, overallpayment = 0,
         first_payment = 0;
  if (!model->CreditCalc(Sum.value(), Span.value(), Percent.value(),
                         &monthly_payment, &overpayment, &overallpayment,
                         &first_payment, r1->isChecked(),
                         combo->currentIndex())) {
    if (r1->isChecked()) {
      Monthly_payment->setText(QString::number(monthly_payment, 10, 2));
    } else {
      Monthly_payment->setText(QString::number(first_payment, 10, 2) + "..." +
                               QString::number(monthly_payment, 10, 2));
    }
    Overpayment->setText(QString::number(overpayment, 10, 2));
    Overall_payment->setText(QString::number(overallpayment, 10, 2));
  }
}
