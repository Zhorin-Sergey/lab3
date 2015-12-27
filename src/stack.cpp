#include "stack.h"
#include "list.h"
#include "list.cpp"


template <class valuet>
stack<valuet>::stack() {
  List = new list<valuet>();
}

template <class valuet>
stack<valuet>::stack(stack<valuet> &a) {
  List = new list<valuet>(*(a.List));
}

template <class valuet>
stack<valuet>::~stack() {
  delete List;
}

template <class valuet>
int stack<valuet>::isEmpty() const {
  return (List->GetFirst() == 0);
}

template <class valuet>
int stack<valuet>::isFull() const {
  node<valuet> *tmp;
  try {
    tmp = new node<valuet>;
  }
  catch (...) {
    return 1;
  }
  delete tmp;
  return 0;
}

template <class valuet>
void stack<valuet>::push(valuet _val) {
  if (isFull())
    throw std::exception("Full stack");
  List->insertF(_val);
}

template <class valuet>
valuet stack<valuet>::pop() {
  if (isEmpty())
    throw std::exception("Empty stack");
  valuet result = List->GetFirst()->val;
  node<valuet> *f = (List->del(result));
  delete f;
  return result;
}

template <class valuet>
bool stack<valuet>::operator == (const stack<valuet> &a) {
  if (List->GetFirst() == 0 && a.List->GetFirst() == 0)
    return true;
  if (List->GetFirst() == 0 || a.List->GetFirst() == 0)
    return false;
  node<valuet> *f1 = List->GetFirst();
  node<valuet> *f2 = a.List->GetFirst();
  while (f1->next != 0) {
    if (f1->val != f2->val)
      return false;
    f1 = f1->next;
    f2 = f2->next;
  }
  return true;
}

template <class valuet>
void stack<valuet>::print(){
  List->print();
}

template <class valuet>
valuet stack<valuet>::GetFirstVal()
{
  if (isEmpty()) throw "Stack is empty";
  return List->GetFirst()->val;
}
