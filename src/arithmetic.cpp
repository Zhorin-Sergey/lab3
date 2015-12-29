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

void Insert(string str, map<char, double> &a) {
  char curr;
  for (int i = 0; i < str.length(); i++) {
    curr = str[i];
    if (((curr >= 0x41) && (curr <= 0x5A)) || ((curr >= 0x61) && (curr <= 0x7A))) 
      if (!a.count(curr)) {
        cout<<" "<<curr<<" = ";
        cin>>a[curr];
        cout<<endl;
      }
    continue;
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

double arithmetic::calculation(string str,  map<char, double> a) {
  if (str == "")
    throw std::exception("Empty expression");
  stack<double> operand;
  double leftOperand;
  double rightOperand;
  char curr;
  for (int i = 0; i < str.length(); i++) {
    curr = str[i];
    if (((curr >= 0x41) && (curr <= 0x5A)) || ((curr >= 0x61) && (curr <= 0x7A))) {
      operand.push(a[curr]);
      continue;
    }
    if (operand.isEmpty())
      throw std::exception("does not match the number of operands");
    rightOperand = operand.pop();
    if (operand.isEmpty())
      throw std::exception("does not match the number of operands");
    leftOperand = operand.pop();
    switch (curr) {
      case '+': {operand.push(leftOperand + rightOperand); break;  }
      case '-':{operand.push(leftOperand - rightOperand); break; }
      case '*':{operand.push(leftOperand * rightOperand); break; }
      case '/':{operand.push(leftOperand / rightOperand); break; }
    }
  }
  double result = operand.pop();
  if (!operand.isEmpty())
    throw std::exception("many operands");
  return result;
}