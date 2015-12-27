#pragma once

#include "list.h"

template <class valuet>
class stack {
  private:
    list<valuet>* List;
  public:
    stack();
    stack(stack<valuet> &a);
    ~stack();
    bool stack<valuet>::operator == (const stack<valuet>& a);
    int isFull() const;
    int isEmpty() const;
    void push(valuet t);
    valuet pop();
    void print();
    valuet GetFirstVal();
};
