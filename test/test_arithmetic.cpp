#include <gtest.h>
#include "arithmetic.cpp"

TEST(arithmetic, can_convert_in_a_postfix_notation) {
  string str1 = "a+(b-c)*d-f/(g+h)";
  string str2 = "abc-d*+fgh+/-";
  string str3 = arithmetic::arithmetic_notation(str1);
  EXPECT_EQ(str2, str3);
}

TEST(arithmetic, can_calculate_expresion_in_a_postfix_notation) {
  string str1 = "a+b*c";
  double d2 = 7;
  double d[3] = { 1, 2, 3 };
  string str2 = arithmetic::arithmetic_notation(str1);
  double d1 = arithmetic::calculation(str2, d, 2);
  EXPECT_EQ(d1, d2);
}

TEST(arithmetic, can_not_calculate_expresion_with_wrong_arguments) {
  string str1 = "a+b*c";
  double d2 = 7;
  double d[3] = { 1, 2, 3 };
  string str2 = arithmetic::arithmetic_notation(str1);
  ASSERT_ANY_THROW(arithmetic::calculation(str2, d, 1));
}

TEST(arithmetic, throws_when_input_invalid) {
  string str1 = "a+(b-c";
  EXPECT_ANY_THROW(arithmetic::arithmetic_notation(str1));
}

TEST(arithmetic, throws_when_try_convert_empty_wtring) {
  string str1 = "";
  EXPECT_ANY_THROW(arithmetic::arithmetic_notation(str1));
}