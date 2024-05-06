#ifndef SRC_VIEW_VIEW_H
#define SRC_VIEW_VIEW_H

#include <QKeyEvent>
#include <QMainWindow>

#include "../Controller/Controller.h"
#include "creditview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(CreditView *v, Controller *c, QWidget *parent = nullptr);
  ~View();

 private:
  Ui::View *ui_;
  Controller *controller;
  CreditView *creditview;
  void keyPressEvent(QKeyEvent *);
  void Button_click();
  void Connection();
  void Clear();
  void Graph();
  void BackSpace();
  void Solve();
  void ZoomIn();
  void ZoomOut();
  void ChangeMode();
};

}  // namespace s21
#endif  // SRC_VIEW_H
