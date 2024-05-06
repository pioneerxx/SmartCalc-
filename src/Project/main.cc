#include <QApplication>

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CreditModel creditmodel;
  s21::CreditController creditcontroller(&creditmodel);
  s21::CreditView creditview(&creditcontroller);
  s21::Model model;
  s21::Controller controller(&model);
  s21::View view(&creditview, &controller);
  view.show();
  return a.exec();
}
