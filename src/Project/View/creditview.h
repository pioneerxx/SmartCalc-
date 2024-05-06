#ifndef CREDITVIEW_H
#define CREDITVIEW_H

#include <QPixmap>
#include <QWidget>

#include "../Controller/CreditController.h"

namespace Ui {
class creditview;
}

namespace s21 {
class CreditView : public QWidget {
  Q_OBJECT

 public:
  explicit CreditView(CreditController *c, QWidget *parent = nullptr);
  ~CreditView();
  void CreditClick();

 private:
  Ui::creditview *ui_;
  CreditController *controller;
};
}  // namespace s21

#endif  // CREDITVIEW_H
