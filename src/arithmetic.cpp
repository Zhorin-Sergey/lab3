#include "arithmetic.h"
#include "stack.h"
#include "stack.cpp"

int prior(char a) {
  switch (a) {
  case '=': return 0;
  case '(': return 1;
  case '+': return 2;
  case '-': return 2;
  case '*': return 3;
  case '/': return 4;
  default: return -1;
  }
}

string arithmetic::arithmetic_notation(string str) {
  stack<char> operStack;
  stack<char> vrStack;
  char tmp;
  for (int i = 0; i < str.length(); i++) {
    tmp = str[i];
    if (prior(tmp) != -1) {			
      if ((!operStack.isEmpty()) && (prior(tmp) <= prior(operStack.GetFirstVal())) && (tmp != '('))
        while ((!operStack.isEmpty()) && (prior(tmp) <= prior(operStack.GetFirstVal())))
          vrStack.push(operStack.pop());
      operStack.push(tmp);
      continue;
    }

    if (((tmp >= 0x41) && (tmp <= 0x5A)) || ((tmp >= 0x61) && (tmp <= 0x7A))) {
      vrStack.push(tmp);
      continue;
    }
    if (tmp == ')') {
      while ((!operStack.isEmpty()) && (operStack.GetFirstVal() != '('))
        vrStack.push(operStack.pop());
      if (operStack.isEmpty())
        throw exception("Right Bracket is not found");
      operStack.pop();
      continue;
    }
    throw exception("Invalid characters");
  }
  while (!operStack.isEmpty()) {
    if (operStack.GetFirstVal() == '(')
      throw exception("Left Bracket is not found");
    vrStack.push(operStack.pop());
  }

  if (vrStack.isEmpty())
    throw exception("No data");
  string result;
  string tmp1;
  while (!vrStack.isEmpty()) {
    tmp1 = vrStack.pop();
    result.insert(0, tmp1);
  }
  return result;
}

double arithmetic::arithmetic_calculation(string str) {
  if (str == "")
    throw exception("No data");
  stack<double> vrStack;
  char buff;
  double leftOperand;
  double rightOperand;
  map<char, double> values;
  cout << "Input values: " << endl;
  for (int i = 0; i < str.length(); i++) {
    buff = str[i];
    if (((buff >= 0x41) && (buff <= 0x5A)) || ((buff >= 0x61) && (buff <= 0x7A))) {
      if (!values.count(buff)) {
        cout << " " << buff << " = ";
        cin >> values[buff];
      }
      vrStack.push(values[buff]);
      continue;
    }
    if (vrStack.isEmpty())
      throw exception("right operand is missing");
    rightOperand = vrStack.pop();
    if (vrStack.isEmpty())
      throw exception("left operand is missing");
    leftOperand = vrStack.pop();
    switch (buff) {
      case '+':{vrStack.push(leftOperand + rightOperand); break; }
      case '-':{vrStack.push(leftOperand - rightOperand); break; }
      case '*':{vrStack.push(leftOperand * rightOperand); break; }
      case '/':{vrStack.push(leftOperand / rightOperand); break; }
      case '=': return rightOperand;
    }
  }
  double result = vrStack.pop();
  if (!vrStack.isEmpty())
    throw exception("too many operands");
  return result;
}

double arithmetic::calculation(string str, double *values, int n) {
  if (str == "")
    throw std::exception("Empty expression");
  stack<double> vrStack;
  double leftOperand;
  double rightOperand;
  map<char, double> value;
  char buff;
  int j = 0;
  for (int i = 0; i < str.length(); i++) {
    buff = str[i];
	if (((buff >= 0x41) && (buff <= 0x5A)) || ((buff >= 0x61) && (buff <= 0x7A))) {
      if (j > n)
        throw std::exception("Too many values");
	  if (!value.count(buff)) {
        value[buff] = values[j];
        j++;
      }
	  vrStack.push(value[buff]);
      continue;
    }
	if (vrStack.isEmpty())
      throw std::exception("right operand is missing");
	rightOperand = vrStack.pop();
	if (vrStack.isEmpty())
      throw std::exception("left operand is missing");
	leftOperand = vrStack.pop();
	switch (buff) {
      case '+': {
        vrStack.push(leftOperand + rightOperand);
        break;
      }
	  case '-':{vrStack.push(leftOperand - rightOperand); break; }
	  case '*':{vrStack.push(leftOperand * rightOperand); break; }
	  case '/':{vrStack.push(leftOperand / rightOperand); break; }
    }
  }
  double result = vrStack.pop();
  if (!vrStack.isEmpty())
    throw std::exception("too many operands");
  return result;
}