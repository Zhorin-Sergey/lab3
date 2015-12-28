#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include <map>
using namespace std;

int prior(char a);

class arithmetic {
  public:
    static string arithmetic_notation(string);
    static double arithmetic_calculation(string);
	static double calculation(string str, double *values, int n);
};
