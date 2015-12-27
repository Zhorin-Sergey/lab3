#include <iostream>
#include <string>

#include "arithmetic.h"
using namespace std;

int main() {
  cout << "Converting in a postfix notation" << endl;
  cout << "Input infix notation: " << endl;
  string str;
  cout << " ";
  cin >> str;
  string notation;
  double result;
  try {
    notation = arithmetic::arithmetic_notation(str);
    result = arithmetic::arithmetic_calculation(notation);
  }
  catch (...) {
    cout << "Error! Invalide input" << endl;
    return 1;
  }
  cout << endl;
  cout << "Postfix notation: " << endl;
  cout << " " << notation << endl;
  cout << endl;
  cout << "Result: " << endl;
  cout << " " << result << endl;
  system("pause");
}
