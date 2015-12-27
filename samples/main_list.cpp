#include "list.h"
#include "list.cpp"
#include <iostream>

using namespace std;

int main() {
  list<int> l;
  l.insertL(5);
  l.insertL(3);
  l.insertL(8);
  l.insertL(1);
  l.insertL(2);
  cout << "List :" << endl;
  l.print();
  cout << "Copied list is equal :" << endl;
  list<int> l1(l);
  l1.print();
  cout << "Insertion element with key = 10 in the first position" << endl;
  l1.insertF(10);
  l1.print();
  cout << "Insertion element with key = 10 in the last position" << endl;
  l1.insertL(10);
  l1.print();
  cout << "Insertion element with key = 10 after the element with key = 8" << endl;
  node<int> *n = new node<int>;
  n->val = 10;
  l1.insertA(8, n);
  l1.print();
  cout << "Delete element with key = 1" << endl;
  l1.del(1);
  l1.print();
  cout << "Delete first occurrence of elemnt with key = 10" << endl;
  l1.del(10);
  l1.print();
  cout << "Getting key from first element" << endl;
  cout << l1.GetFirst()->val << endl;
  return 0;
}
