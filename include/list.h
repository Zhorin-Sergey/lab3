#pragma once
#include <iostream>
using namespace std;

template <class valuet>
class node {
  public:
    valuet val;
    node *next;
};

template <class valuet>
class list {
  protected:
    node<valuet>* pFirst;
  public:
    list();
    list(list &a);
    ~list();
    node<valuet>* poisk(valuet t);
    node<valuet>* del(valuet t);
    void insertF(valuet t);
    void insertL(valuet t);
    void insertA(valuet t, node<valuet>* a);
    void print();
    node<valuet>* GetFirst();
};
