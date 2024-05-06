#include "creditview.h"

#include "ui_creditview.h"

s21::CreditView::CreditView(CreditController *c, QWidget *parent)
    : QWidget(parent), ui_(new Ui::creditview) {
  ui_->setupUi(this);
  this->setWindowTitle("Credit Calculator++");
  ui_->Image->setPixmap(QPixmap(":/Resources/credit.jpg").scaled(601, 421));
  connect(ui_->ButtonCalculate, &QPushButton::clicked, this,
          &CreditView::CreditClick);
  controller = c;
  this->setFixedSize(1130, 419);
}

s21::CreditView::~CreditView() { delete ui_; }

void s21::CreditView::CreditClick() {
  controller->CreditCalc(*ui_->SpinSum, *ui_->SpinSpan, *ui_->SpinPercent,
                         ui_->MonthlyPayment, ui_->Overpayment,
                         ui_->OverallPayment, ui_->Radio1, ui_->MeasurementBox);
}
