#include <gtest.h>
#include "stack.h"
#include "stack.cpp"

TEST(Stack, can_create_stack) {
  stack<char> *s;
  ASSERT_NO_THROW(s = new stack<char>());
}

TEST(Stack, can_create_copied_stack) {
  stack<char> s1;
  s1.push(1);
  s1.push(8);
  ASSERT_NO_THROW(stack<char> s2(s1));
}

TEST(Stack, copied_stack_is_equal_to_sourse_one) {
  stack<char> s1;
  s1.push(3);
  stack<char> s2(s1);
  EXPECT_EQ(true, s1 == s2);
}

TEST(Stack, copied_stack_has_its_own_memory) {
  stack<char> s1;
  s1.push(1);
  s1.push(2);
  stack<char> s2(s1);
  s2.pop();
  s2.push(3);
  EXPECT_EQ(false, s1 == s2);
}

TEST(Stack, IsEmpty_returns_1_when_stack_is_empty) {
  stack<char> s;
  EXPECT_EQ(1, s.isEmpty());
}

TEST(Stack, IsEmpty_returns_0_when_stack_isnt_empty) {
  stack<char> s;
  s.push(1);
  EXPECT_EQ(0, s.isEmpty());
}

TEST(Stack, IsFull_returns_0_when_stack_isnt_full) {
  stack<char> s;
  s.push(1);
  EXPECT_EQ(0, s.isFull());
}

TEST(Stack, can_push_new_element) {
  stack<char> s;
  ASSERT_NO_THROW(s.push(1));
}

TEST(Stack, cant_pop_element_fron_empty_stack) {
  stack<char> s;
  ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_pop_element_from_not_empty_stack) {
  stack<char> s;
  s.push(1);
  ASSERT_NO_THROW(s.pop());
}

TEST(Stack, poped_element_is_equal_to_pushed_one) {
  stack<char> s;
  s.push(1);
  EXPECT_EQ(1, s.pop());
}
