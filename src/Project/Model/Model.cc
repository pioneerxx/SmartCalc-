#include "Model.h"

s21::Model::Model() {}

s21::Model::~Model() {}

bool s21::Model::WhichButton(std::string *text, std::string value) {
  bool res = 1;
  if (!value.compare("1") || !value.compare("2") || !value.compare("3") ||
      !value.compare("4") || !value.compare("5") || !value.compare("6") ||
      !value.compare("7") || !value.compare("8") || !value.compare("9")) {
    res = PrintNum(text, value);
  } else if (!value.compare(".")) {
    res = PrintDot(text);
  } else if (!value.compare("0")) {
    res = PrintZero(text);
  } else if (!value.compare("(") || !value.compare(")")) {
    res = PrintBraces(text, value);
  } else if (!value.compare("mod") || !value.compare("+") ||
             !value.compare("-") || !value.compare("/") ||
             !value.compare("*") || !value.compare("^")) {
    res = PrintOperation(text, value);
  } else if (!value.compare("x")) {
    res = PrintX(text);
  } else if (!value.compare("e")) {
    res = PrintE(text);
  } else {
    res = PrintFunc(text, value);
  }
  return res;
}

bool s21::Model::PrintNum(std::string *text, std::string value) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if (c != 'x' && c != 'e' && c != ')' && text->size() + 1 <= 255) {
    res = 0;
    if (!text->compare("0")) {
      *text = value;
      iszero = 0;
    } else if (c != '0' || isdot || !iszero) {
      text->append(value);
    }
  }
  return res;
}

bool s21::Model::PrintDot(std::string *text) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if (c >= '0' && c <= '9' && isdot == 0 && text->size() + 1 <= 255) {
    text->append(".");
    isdot = 1;
    iszero = 0;
    res = 0;
  }
  return res;
}

bool s21::Model::PrintZero(std::string *text) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if (c != 'x' && c != 'e' && c != ')' && text->size() + 1 <= 255) {
    if (!iszero) {
      iszero = (c < '0' || c > '9') && c != '.' ? 1 : 0;
      text->append("0");
      res = 0;
    }
  }
  return res;
}

void s21::Model::Clear() {
  isdot = 0;
  iszero = 1;
  braces = 0;
}

bool s21::Model::PrintBraces(std::string *text, std::string brace) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if (!brace.compare("(")) {
    if ((c < '0' || c > '9') && c != '.' && c != 'x' && c != 'e' &&
        text->size() + 1 <= 255) {
      text->append(brace);
      braces++;
      isdot = 0;
      iszero = 0;
      res = 0;
    } else if (!text->compare("0")) {
      *text = brace;
      braces++;
      res = 0;
    }
  } else {
    if (((c >= '0' && c <= '9') || c == ')' || c == 'x') && braces > 0 &&
        text->size() + 1 <= 255) {
      text->append(brace);
      iszero = 0;
      isdot = 0;
      res = 0;
      braces--;
    }
  }
  return res;
}

bool s21::Model::PrintOperation(std::string *text, std::string value) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if (((c >= '0' && c <= '9') || c == ')' || c == 'x' || c == 'e') &&
      text->size() + 1 <= 255) {
    if (!text->compare("0") && (!value.compare("+") || !value.compare("-"))) {
      *text = value;
      iszero = 0;
      isdot = 0;
      res = 0;
    } else if (!value.compare("e") &&
               (!value.compare("+") || !value.compare("-"))) {
      text->append(value);
      iszero = 0;
      isdot = 0;
      res = 0;
    } else {
      text->append(value);
      iszero = 0;
      isdot = 0;
      res = 0;
    }
  } else if (c == '(' && (!value.compare("+") || !value.compare("-"))) {
    text->append(value);
    iszero = 0;
    isdot = 0;
    res = 0;
  }
  return res;
}

bool s21::Model::PrintFunc(std::string *text, std::string value) {
  bool res = 1;
  value = !value.compare("√") ? "sqrt" : value;
  char c = text->at(text->size() - 1);
  if ((c < '0' || c > '9') && c != '.' && c != 'x' && c != 'e' && c != ')' &&
      text->size() + 4 <= 255) {
    text->append(value + "(");
    braces++;
    iszero = 0;
    isdot = 0;
    res = 0;
  } else if (!text->compare("0")) {
    *text = value + "(";
    braces++;
    iszero = 0;
    isdot = 0;
    res = 0;
  }
  return res;
}

bool s21::Model::PrintX(std::string *text) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if ((c < '0' || c > '9') && c != '.' && c != 'x' && c != 'e' &&
      text->size() + 1 <= 255) {
    text->append("x");
    res = 0;
  } else if (!text->compare("0")) {
    *text = "x";
    res = 0;
  }
  return res;
}

bool s21::Model::PrintE(std::string *text) {
  bool res = 1;
  char c = text->at(text->size() - 1);
  if (c >= '0' && c <= '9') {
    text->append("e");
    res = 0;
  }
  return res;
}

bool s21::Model::BackSpace(char c, int size) {
  bool res = 1;
  if (c == ')') {
    braces++;
  } else if (c == '(') {
    braces--;
  } else if (c == '.') {
    isdot = 0;
  } else if (c == '0' && iszero && !isdot && size > 1) {
    iszero = 0;
  } else if (size == 1) {
    res = 0;
    isdot = 0;
    iszero = 1;
  }
  return res;
}

double s21::Model::QueryToNum(char *query, int *ind, double x) {
  char num[256];
  int numind = 0;
  double res = 0;
  if (query[*ind] == 'x') {
    res = x;
    *ind = *ind + 1;
  } else {
    while ((query[*ind] >= 48 && query[*ind] <= 57) || query[*ind] == '.' ||
           ((query[*ind + 1] == '-' || query[*ind + 1] == '+') &&
            query[*ind] == 'e') ||
           ((query[*ind] == '-' || query[*ind] == '+') &&
            query[*ind - 1] == 'e')) {
      num[numind] = query[*ind];
      *ind = *ind + 1;
      numind++;
    }
    num[numind] = '\0';
    res = atof(num);
  }
  return res;
}

int s21::Model::QueryToLex(char *query, int *ind, int *prior) {
  int res = 0;
  if (query[*ind] == '(') {
    res = LBRACEOP;
    *prior = PRIORITY_A;
    *ind = *ind + 1;
  } else if (query[*ind] == ')') {
    res = LBRACECLOSE;
    *prior = PRIORITY_A;
    *ind = *ind + 1;
  } else if (query[*ind] == '+') {
    if (*ind == 0 || query[*ind - 1] == '(') {
      res = LUNPLUS;
    } else {
      res = LPLUS;
    }
    *prior = PRIORITY_F;
    *ind = *ind + 1;
  } else if (query[*ind] == '-') {
    if (*ind == 0 || query[*ind - 1] == '(') {
      res = LUNMINUS;
    } else {
      res = LMINUS;
    }
    *prior = PRIORITY_F;
    *ind = *ind + 1;
  } else if (query[*ind] == '*') {
    res = LMULT;
    *prior = PRIORITY_D;
    *ind = *ind + 1;
  } else if (query[*ind] == '/') {
    res = LDIVIDE;
    *prior = PRIORITY_D;
    *ind = *ind + 1;
  } else if (query[*ind] == '^') {
    res = LPOW;
    *prior = PRIORITY_C;
    *ind = *ind + 1;
  } else if (query[*ind] == 'm') {
    res = LMOD;
    *prior = PRIORITY_D;
    *ind = *ind + 3;
  } else if (query[*ind] == 'c') {
    res = LCOS;
    *prior = PRIORITY_B;
    *ind = *ind + 3;
  } else if (query[*ind] == 't') {
    res = LTAN;
    *prior = PRIORITY_B;
    *ind = *ind + 3;
  } else if (query[*ind] == 'l') {
    if (query[*ind + 1] == 'o') {
      res = LLOG;
      *prior = PRIORITY_B;
      *ind = *ind + 3;
    } else if (query[*ind + 1] == 'n') {
      res = LLN;
      *prior = PRIORITY_B;
      *ind = *ind + 2;
    }
  } else if (query[*ind] == 'a') {
    if (query[*ind + 1] == 'c') {
      res = LACOS;
      *prior = PRIORITY_B;
    } else if (query[*ind + 1] == 's') {
      res = LASIN;
      *prior = PRIORITY_B;
    } else if (query[*ind + 1] == 't') {
      res = LATG;
      *prior = PRIORITY_B;
    }
    *ind = *ind + 4;
  } else if (query[*ind] == 's') {
    if (query[*ind + 1] == 'i') {
      res = LSIN;
      *prior = PRIORITY_B;
      *ind = *ind + 3;
    } else if (query[*ind == 'q']) {
      res = LSQRT;
      *prior = PRIORITY_B;
      *ind = *ind + 4;
    }
  }
  return res;
}

bool s21::Model::Execute() {
  bool flag = 0;
  double val1 = Numbers.top();
  Numbers.pop();
  double val2 = 0;
  double res = 0;
  if (PeekLex() < 7) {
    val2 = Numbers.top();
    Numbers.pop();
  }
  int lex = Operators.top().lexemme;
  Operators.pop();
  if (lex == LPLUS) {
    res = val2 + val1;
  } else if (lex == LMINUS) {
    res = val2 - val1;
  } else if (lex == LMULT) {
    res = val2 * val1;
  } else if (lex == LDIVIDE) {
    res = val2 / val1;
  } else if (lex == LPOW) {
    res = pow(val2, val1);
  } else if (lex == LMOD) {
    res = fmod(val2, val1);
  } else if (lex == LCOS) {
    res = cos(val1);
  } else if (lex == LSIN) {
    res = sin(val1);
  } else if (lex == LTAN) {
    res = tan(val1);
  } else if (lex == LASIN) {
    res = asin(val1);
  } else if (lex == LACOS) {
    res = acos(val1);
  } else if (lex == LATG) {
    res = atan(val1);
  } else if (lex == LSQRT) {
    res = sqrt(val1);
  } else if (lex == LLN) {
    res = log(val1);
  } else if (lex == LLOG) {
    res = log10(val1);
  } else if (lex == LUNMINUS) {
    res = -val1;
  } else if (lex == LUNPLUS) {
    res = val1;
  }
  try {
    Numbers.push(res);
  } catch (std::bad_alloc &e) {
    flag = 1;
    ClearStack(Numbers, Operators);
  }
  return flag;
}

int s21::Model::PeekPrior() {
  int res = 0;
  if (!Operators.empty()) {
    res = Operators.top().priority;
  }
  return res;
}

int s21::Model::PeekLex() {
  int res = 0;
  if (!Operators.empty()) {
    res = Operators.top().lexemme;
  }
  return res;
}

double s21::Model::SmartCalcPlus(char *query, char c, double x,
                                 bool *MemoryFlag, bool *ErrorFlag) {
  *ErrorFlag =
      (((c >= '0' && c <= '9') || c == ')' || c == 'x') && braces == 0) ? 0 : 1;
  double res = 0, tmp = 0;
  int ind = 0, lex = 0, priority = 0;
  while (query[ind] != '\0' && !*MemoryFlag && !*ErrorFlag) {
    if ((query[ind] >= 48 && query[ind] <= 57) || query[ind] == 'x') {
      tmp = QueryToNum(query, &ind, x);
      try {
        Numbers.push(tmp);
      } catch (std::bad_alloc &e) {
        *MemoryFlag = 1;
        ClearStack(Numbers, Operators);
      }
    } else {
      lex = QueryToLex(query, &ind, &priority);
      if (lex == LBRACECLOSE) {
        while (PeekLex() != LBRACEOP && !*MemoryFlag) {
          *MemoryFlag = Execute();
        }
        Operators.pop();
      } else if (lex == LBRACEOP) {
        try {
          Operators.push(Opers(lex, priority));
        } catch (std::bad_alloc &e) {
          *MemoryFlag = 1;
          ClearStack(Numbers, Operators);
        }
      } else {
        while (PeekPrior() >= priority && PeekPrior() != PRIORITY_A &&
               !*MemoryFlag) {
          *MemoryFlag = Execute();
        }
        try {
          Operators.push(Opers(lex, priority));
        } catch (std::bad_alloc &e) {
          *MemoryFlag = 1;
          ClearStack(Numbers, Operators);
        }
      }
    }
  }
  while (!Operators.empty() && !*MemoryFlag) {
    *MemoryFlag = Execute();
  }
  if (!Numbers.empty() && !*MemoryFlag) {
    res = Numbers.top();
    Numbers.pop();
  }
  return res;
}

void s21::Model::ClearStack(std::stack<double> st, std::stack<Opers> st2) {
  while (!st.empty() || !st2.empty()) {
    if (!st.empty()) {
      st.pop();
    }
    if (!st2.empty()) {
      st2.pop();
    }
  }
}

std::string s21::Model::Interpret(double value, bool MemoryFlag,
                                  bool ErrorFlag) {
  std::string result = "";
  if (MemoryFlag) {
    result = "NOT ENOUGH MEMORY";
  } else if (std::isnan(value) || std::isinf(value) || ErrorFlag) {
    result = "ERROR";
  } else {
    isdot = 1;
    result = std::to_string(value);
  }
  return result;
}

std::pair<std::vector<double>, std::vector<double>> s21::Model::Graph(
    char *query, char c, bool *MemoryFlag, bool *ErrorFlag, double *minY,
    double *maxY) {
  *MemoryFlag = *ErrorFlag = 0;
  double h = 0.1, X = LeftEdge;
  int N = (RightEdge - LeftEdge) / h + 2;
  std::vector<double> x(N);
  std::vector<double> y(N);
  for (int i = 0; i < N && !*MemoryFlag && !*ErrorFlag; i++) {
    x[i] = X;
    y[i] = SmartCalcPlus(query, c, X, MemoryFlag, ErrorFlag);
    X = (int)(X * 10) == -1 ? 0 : X + h;
  }
  if (!*MemoryFlag && !*ErrorFlag) {
    *minY = y[0];
    *maxY = y[0];
    for (int i = 1; i < N; i++) {
      *minY = y[i] < *minY ? y[i] : *minY;
      *maxY = y[i] > *maxY ? y[i] : *maxY;
    }
  }
  return std::pair<std::vector<double>, std::vector<double>>(x, y);
}

bool s21::Model::ZoomIn() {
  bool res = 1;
  if (LeftEdge + 5 < RightEdge - 5) {
    LeftEdge += 5;
    RightEdge -= 5;
    res = 0;
  }
  return res;
}

bool s21::Model::ZoomOut() {
  bool res = 1;
  if (LeftEdge - 5 >= -1000000 && RightEdge + 5 <= 1000000) {
    LeftEdge -= 5;
    RightEdge += 5;
    res = 0;
  }
  return res;
}

int s21::Model::getLeftEdge() { return LeftEdge; }
int s21::Model::getRightEdge() { return RightEdge; }
