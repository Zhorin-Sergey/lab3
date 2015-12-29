#include "arithmetic.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() {
  cout << "Converting in a postfix notation" << endl;
  cout << "Input infix notation: " << endl;
  string expression;
  string note;
  double result;
  cout << "   ";
  cin >> expression;
  try {
    note = arithmetic::arithmetic_notation(expression);
    cout<<"Input values"<<endl;
    map<char, double> a;
    Insert(note, a);
    result = arithmetic::calculation(note,a);
  }
  catch (...) {
    cout << "Error! Invalide input" << endl;
    return 1;
  }
  cout << endl;
  cout << "Postfix note: " << endl;
  cout << " " << note << endl;
  cout << endl;
  cout << "Result: " << endl;
  cout << " " << result << endl;
  system("pause");
}