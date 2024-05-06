#include "Controller.h"

s21::Controller::Controller(s21::Model *m) { model = m; }

s21::Controller::~Controller(){};

bool s21::Controller::WhichButton(std::string *text, std::string value) {
  return model->WhichButton(text, value);
}

void s21::Controller::Clear() { model->Clear(); }

bool s21::Controller::BackSpace(char c, int size) {
  return model->BackSpace(c, size);
}

std::string s21::Controller::Solve(std::string text, double x) {
  char *c = &text[0];
  bool MemoryFlag = 0, ErrorFlag = 0;
  double val = model->Model::SmartCalcPlus(c, text.at(text.size() - 1), x,
                                           &MemoryFlag, &ErrorFlag);
  return model->Interpret(val, MemoryFlag, ErrorFlag);
}

void s21::Controller::Graph(QCustomPlot *plot, std::string text,
                            bool *MemoryFlag, bool *ErrorFlag) {
  char *c = &text[0];
  double minY = 0, maxY = 0;
  std::pair<std::vector<double>, std::vector<double>> res = model->Graph(
      c, text.at(text.size() - 1), MemoryFlag, ErrorFlag, &minY, &maxY);
  if (!*MemoryFlag && !*ErrorFlag) {
    plot->clearGraphs();
    plot->addGraph();
    plot->graph(0)->setData(
        QVector<double>(res.first.begin(), res.first.end()),
        QVector<double>(res.second.begin(), res.second.end()));
    plot->xAxis->setLabel("x");
    plot->yAxis->setLabel("y");
    plot->xAxis->setRange(model->getLeftEdge(), model->getRightEdge());
    plot->yAxis->setRange(minY, maxY);
    plot->setInteraction(QCP::iRangeZoom, true);
    plot->setInteraction(QCP::iRangeDrag, true);
    plot->setBackground(QBrush(Qt::transparent));
    plot->resize(561, 311);
  }
}

void s21::Controller::ZoomIn(QCustomPlot *plot, std::string text) {
  bool a = 0, b = 0;
  if (!model->ZoomIn()) {
    Graph(plot, text, &a, &b);
    plot->replot();
  }
}

void s21::Controller::ZoomOut(QCustomPlot *plot, std::string text) {
  bool a = 0, b = 0;
  if (!model->ZoomOut()) {
    Graph(plot, text, &a, &b);
    plot->replot();
  }
}
