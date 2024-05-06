#ifndef SRC_MODEL_MODEL_H
#define SRC_MODEL_MODEL_H
#include <cmath>
#include <stack>
#include <string>
#include <vector>

namespace s21 {
class Model {
 public:
  Model();
  ~Model();

  struct Opers {
    int lexemme;
    int priority;

    Opers(int lex, int prior) : lexemme(lex), priority(prior){};
  };

  enum Priority {
    PRIORITY_F = 1,
    PRIORITY_D = 2,
    PRIORITY_C = 3,
    PRIORITY_B = 4,
    PRIORITY_A = 5
  };

  enum Lexemme {
    LPLUS = 1,
    LMINUS = 2,
    LMULT = 3,
    LDIVIDE = 4,
    LPOW = 5,
    LMOD = 6,
    LUNPLUS = 7,
    LUNMINUS = 8,
    LCOS = 9,
    LSIN = 10,
    LTAN = 11,
    LASIN = 12,
    LACOS = 13,
    LATG = 14,
    LSQRT = 15,
    LLN = 16,
    LLOG = 17,
    LBRACEOP = 18,
    LBRACECLOSE = 19
  };

  double SmartCalcPlus(char *query, char c, double x, bool *MemoryFlag,
                       bool *ErrorFlag);
  std::string Interpret(double value, bool MemoryFlag, bool ErrorFlag);
  double QueryToNum(char *query, int *ind, double x);
  int QueryToLex(char *query, int *ind, int *prior);
  bool Execute();
  int PeekPrior();
  int PeekLex();
  std::pair<std::vector<double>, std::vector<double>> Graph(char *query, char c,
                                                            bool *MemoryFlag,
                                                            bool *ErrorFlag,
                                                            double *minY,
                                                            double *maxY);
  void ClearStack(std::stack<double> st, std::stack<Opers> st2);

  bool WhichButton(std::string *text, std::string value);
  bool PrintNum(std::string *text, std::string value);
  bool PrintZero(std::string *text);
  bool PrintDot(std::string *text);
  bool PrintBraces(std::string *text, std::string brace);
  bool PrintOperation(std::string *text, std::string value);
  bool PrintX(std::string *text);
  bool PrintE(std::string *text);
  bool PrintFunc(std::string *text, std::string value);
  void Clear();
  bool BackSpace(char c, int size);
  bool ZoomIn();
  bool ZoomOut();
  int getLeftEdge();
  int getRightEdge();

 private:
  std::stack<double> Numbers;
  std::stack<Opers> Operators;
  bool iszero = 1;
  bool isdot = 0;
  int LeftEdge = -50;
  int RightEdge = 50;
  int braces = 0;
};
}  // namespace s21

#endif  // SRC_MODEL_MODEL_H
