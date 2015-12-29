#include <gtest.h>
#include "list.h"
#include "list.cpp"

TEST(List, can_create_list) {
  list<char> *List;
  ASSERT_NO_THROW(List = new list<char>);
}

TEST(List, can_create_copied_list) {
  list<char> list1;
  list1.insertL(1);
  ASSERT_NO_THROW(list<char> list2(list1));
}

TEST(List, copied_list_is_equal_to_sourse_one) {
  list<char> list1;
  list1.insertL(1);
  list<char> list2(list1);
  EXPECT_EQ(list2.GetFirst()->val, 1);
}

TEST(List, copied_list_has_its_own_memory) {
  list<char> list1;
  list1.insertL(1);
  list<char> list2(list1);
  list2.insertL(2);
  list2.del(1);
  EXPECT_NE(list2.GetFirst()->val, list1.GetFirst()->val);
}

TEST(List, can_print_empty_list) {
  list<char> list1;
  ASSERT_NO_THROW(list1.print());
}

TEST(List, can_find_element) {
  list<char> list1;
  list1.insertL(2);
  list1.insertL(3);
  list1.insertL(4);
  list1.insertL(5);
  ASSERT_TRUE(list1.poisk(3) != 0);
}

TEST(List, throws_when_cant_find_element) {
  list<char> list1;
  list1.insertL(2);
  list1.insertL(3);
  list1.insertL(4);
  list1.insertL(5);
  ASSERT_ANY_THROW(list1.poisk(7));
}

TEST(List, throws_when_search_in_empty_list) {
  list<char> list1;
  ASSERT_ANY_THROW(list1.poisk(7));
}

TEST(List, can_delete_element) {
  list<char> list1;
  list1.insertL(2);
  list1.insertL(3);
  list1.insertL(4);
  list1.insertL(5);
  ASSERT_NO_THROW(list1.del(5));
  ASSERT_ANY_THROW(list1.poisk(5));
}

TEST(List, return_null_when_delete_not_actual_value) {
  list<char> list1;
  list1.insertL(2);
  list1.insertL(3);
  list1.insertL(4);
  list1.insertL(5);
  EXPECT_EQ(0, list1.del(11));
}

TEST(List, can_delete_first_element) {
  list<char> list1;
  list1.insertL(2);
  list1.insertL(3);
  list1.insertL(4);
  list1.insertL(5);
  ASSERT_NO_THROW(list1.del(2));
}

TEST(List, throws_when_try_delete_in_empty_list) {
  list<char> list;
  ASSERT_ANY_THROW(list.del(1));
}

TEST(List, can_insert_first_element) {
  list<char> list;
  ASSERT_NO_THROW(list.insertF(5));
  EXPECT_EQ(5, list.GetFirst()->val);
}

TEST(List, can_insert_last_element) {
  list<char> list;
  list.insertF(2);
  ASSERT_NO_THROW(list.insertL(5));
}

TEST(List, can_insert_last_element_when_list_is_empty) {
  list<char> list;
  ASSERT_NO_THROW(list.insertL(5));
  EXPECT_EQ(5, list.GetFirst()->val);
}

TEST(List, can_insert_after) {
  list<char> list;
  list.insertL(5);
  list.insertL(6);
  list.insertL(7);
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_NO_THROW(list.insertA(5, a));
}

TEST(List, can_insert_after_when_it_last) {
  list<char> list;
  list.insertL(5);
  list.insertL(6);
  list.insertL(7);
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_NO_THROW(list.insertA(7, a));
}

TEST(List, throws_when_cant_find_place_to_insert_after) {
  list<char> list;
  list.insertL(5);
  list.insertL(7);
  list.insertL(9);
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_ANY_THROW(list.insertA(8, a));
}

TEST(List, throws_when_insert_after_in_empty_list) {
  list<char> list;
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_ANY_THROW(list.insertA(5, a));
}

TEST(List, can_get_first) {
  list<char> list;
  list.insertL(5);
  list.insertL(6);
  list.insertL(7);
  ASSERT_NO_THROW(list.GetFirst());
  EXPECT_EQ(5, list.GetFirst()->val);
}
