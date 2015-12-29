#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include <map>
using namespace std;

void Insert(string, map<char, double> &); 

class arithmetic {
  public:
    static string arithmetic_notation(string);
    static double calculation(string, map<char, double>);;
};
