#include "view.h"

#include "ui_view.h"

s21::View::View(CreditView *v, Controller *c, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::View) {
  controller = c;
  creditview = v;
  ui_->setupUi(this);
  this->setWindowTitle("Smart Calculator++");
  Connection();
  this->setFixedSize(1231, 555);
  ui_->SpinBoxX->hide();
  ui_->LabelX->hide();
  ui_->Plot->setBackground(Qt::transparent);
  ui_->Plot->setInteraction(QCP::iRangeZoom, true);
  ui_->Plot->setInteraction(QCP::iRangeDrag, true);
  ui_->Plot->replot();
}

s21::View::~View() { delete ui_; }

void s21::View::ChangeMode() {
  QAction *action = qobject_cast<QAction *>(sender());
  this->hide();
  if (!action->text().compare("Credit Calculator")) {
    creditview->show();
  } else if (!action->text().compare("Calculator")) {
    this->show();
    creditview->hide();
  }
}

void s21::View::Connection() {
  connect(ui_->Button0, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button1, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button2, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button3, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button4, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button5, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button6, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button7, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button8, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->Button9, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonX, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonE, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonDot, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonPlus, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonMinus, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonMul, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonDiv, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonBraceOpen, &QPushButton::clicked, this,
          &View::Button_click);
  connect(ui_->ButtonBraceClose, &QPushButton::clicked, this,
          &View::Button_click);
  connect(ui_->ButtonMod, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonPow, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonSqrt, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonLog, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonLn, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonSin, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonCos, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonTan, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonAsin, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonAcos, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonAtan, &QPushButton::clicked, this, &View::Button_click);
  connect(ui_->ButtonClear, &QPushButton::clicked, this, &View::Clear);
  connect(ui_->ButtonBackspace, &QPushButton::clicked, this, &View::BackSpace);
  connect(ui_->ButtonEqual, &QPushButton::clicked, this, &View::Solve);
  connect(ui_->ButtonGraph, &QPushButton::clicked, this, &View::Graph);
  connect(ui_->ButtonZoomIn, &QPushButton::clicked, this, &View::ZoomIn);
  connect(ui_->ButtonZoomOut, &QPushButton::clicked, this, &View::ZoomOut);
  connect(ui_->actionCredit_Calculator, &QAction::triggered, this,
          &View::ChangeMode);
  connect(ui_->actionCalculator, &QAction::triggered, this, &View::ChangeMode);
}

void s21::View::keyPressEvent(QKeyEvent *event) {
  if ((event->text() >= '0' && event->text() <= '9') || event->text() == '.' ||
      event->text() == 'x' || event->text() == 'X' || event->text() == '+' ||
      event->text() == '-' || event->text() == '*' || event->text() == '/' ||
      event->text() == '^' || event->text() == '(' || event->text() == ')' ||
      event->text() == 'e' || event->text() == 'E') {
    std::string newtext = ui_->ValueText->text().toStdString();
    bool flag = controller->WhichButton(&newtext, event->text().toStdString());
    if (!flag) {
      ui_->ButtonZoomIn->setDisabled(1);
      ui_->ButtonZoomOut->setDisabled(1);
      ui_->ValueText->setText(QString::fromStdString(newtext));
      if (!event->text().compare("x")) {
        ui_->SpinBoxX->show();
        ui_->LabelX->show();
      }
    }
  } else if (event->key() == Qt::Key_Backspace) {
    BackSpace();
  } else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    Solve();
  }
}

void s21::View::Button_click() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  std::string newtext = ui_->ValueText->text().toStdString();
  bool flag = controller->WhichButton(&newtext, button->text().toStdString());
  if (!flag) {
    ui_->ButtonZoomIn->setDisabled(1);
    ui_->ButtonZoomOut->setDisabled(1);
    ui_->ValueText->setText(QString::fromStdString(newtext));
    if (!button->text().compare("x")) {
      ui_->SpinBoxX->show();
      ui_->LabelX->show();
    }
  }
}

void s21::View::Clear() {
  ui_->ValueText->setText("0");
  controller->Clear();
  ui_->SpinBoxX->hide();
  ui_->ButtonZoomIn->setDisabled(1);
  ui_->ButtonZoomOut->setDisabled(1);
  ui_->LabelX->hide();
  ui_->Plot->clearGraphs();
  ui_->Plot->replot();
}

void s21::View::BackSpace() {
  if (controller->BackSpace(ui_->ValueText->text()
                                .at(ui_->ValueText->text().size() - 1)
                                .toLatin1(),
                            ui_->ValueText->text().size())) {
    ui_->ValueText->setText(
        ui_->ValueText->text().left(ui_->ValueText->text().size() - 1));
  } else {
    ui_->ValueText->setText("0");
  }
  ui_->ButtonZoomIn->setDisabled(1);
  ui_->ButtonZoomOut->setDisabled(1);
  ui_->Plot->clearGraphs();
  ui_->Plot->replot();
}

void s21::View::Solve() {
  ui_->ValueText->setText(QString::fromStdString(controller->Solve(
      ui_->ValueText->text().toStdString(), ui_->SpinBoxX->value())));
}

void s21::View::Graph() {
  bool MemoryFlag = 0, ErrorFlag = 0;
  controller->Graph(ui_->Plot, ui_->ValueText->text().toStdString(),
                    &MemoryFlag, &ErrorFlag);
  if (MemoryFlag) {
    ui_->ValueText->setText("NOT ENOUGH MEMORY");
  } else if (ErrorFlag) {
    ui_->ValueText->setText("ERROR");
  } else {
    ui_->Plot->replot();
    ui_->ButtonZoomIn->setDisabled(0);
    ui_->ButtonZoomOut->setDisabled(0);
  }
}

void s21::View::ZoomIn() {
  controller->ZoomIn(ui_->Plot, ui_->ValueText->text().toStdString());
}

void s21::View::ZoomOut() {
  controller->ZoomOut(ui_->Plot, ui_->ValueText->text().toStdString());
}
