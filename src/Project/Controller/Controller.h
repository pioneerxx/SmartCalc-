#ifndef SRC_CONTROLLER_CONTROLLER_H
#define SRC_CONTROLLER_CONTROLLER_H

#include <QVector>
#include <string>

#include "../Libs/qcustomplot.h"
#include "../Model/Model.h"

namespace s21 {
class Controller {
 public:
  Controller(Model *m);
  ~Controller();
  bool WhichButton(std::string *text, std::string value);
  void Graph(QCustomPlot *plot, std::string text, bool *MemoryFlag,
             bool *ErrorFlag);
  void Clear();
  bool BackSpace(char c, int size);
  std::string Solve(std::string text, double x);
  void ZoomIn(QCustomPlot *plot, std::string text);
  void ZoomOut(QCustomPlot *plot, std::string text);

 private:
  Model *model;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLER_H
