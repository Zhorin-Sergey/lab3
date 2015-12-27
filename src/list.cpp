#include "list.h"

template <class valuet>
list<valuet>::list() {
  pFirst = 0;
}

template <class valuet>
list<valuet>::list(list<valuet> &a) {
  pFirst = 0;
  node<valuet>* b = a.pFirst;
  while (b != 0) {
    insertL(b->val);
    b = b->next;
  }
}

template <class valuet>
list<valuet>::~list() {
  node<valuet> *b = pFirst;
  while (pFirst != 0) {
    pFirst = pFirst->next;
    delete b;
    b = pFirst;
  }
}

template <class valuet>
node<valuet>* list<valuet>::poisk(valuet t) {
  if (pFirst == 0)
    throw std::exception("Empty list");
  node<valuet> *tmp = pFirst;
  while ((tmp != 0) && (tmp->val != t))
    tmp = tmp->next;
  if (tmp == 0)
    throw std::exception("Element is not found");
  return tmp;
}

template <class valuet>
node<valuet>* list<valuet>::del(valuet t) {
  if (pFirst == 0)
    throw std::exception("Empty list");
  node<valuet> *tmp = pFirst;
  if (tmp->val == t) {
    pFirst = tmp->next;
    tmp->next = 0;
    return tmp;
  }
  while ((tmp->next != 0) && (tmp->next->val != t))
    tmp = tmp->next;
  if (tmp->next == 0)
    return 0;
  node<valuet> *a = tmp->next;
  tmp->next = a->next;
  a->next = 0;
  return a;
}

template <class valuet>
void list<valuet>::print() {
  if (pFirst == 0) {
    cout << "Empty list" << endl;
    return;
  }
  node<valuet> *tmp = pFirst;
  while (tmp != 0) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

template <class valuet>
void list<valuet>::insertF(valuet t) {
  node<valuet> *tmp = new node<valuet>();
  tmp->val = t;
  tmp->next = pFirst;
  pFirst = tmp;
}

template <class valuet>
void list<valuet>::insertL(valuet t) {
  node<valuet> *tmp = pFirst;
  if (pFirst == 0) {
    insertF(t);
    return;
  }
  while (tmp->next != 0)
    tmp = tmp->next;
  node<valuet> *tmp1 = new node<valuet>();
  tmp1->val = t;
  tmp1->next = 0;
  tmp->next = tmp1;
}

template <class valuet>
void list<valuet>::insertA(valuet t, node<valuet> *a) {
  try {
    poisk(t);
  }
  catch (...) {
    throw exception("Element is not found");
  }
  node<valuet> *tmp = poisk(t);
  a->next = tmp->next;
  tmp->next = a;
}
template <class T>
node<T>* list<T>::GetFirst() {
  return pFirst;
}
