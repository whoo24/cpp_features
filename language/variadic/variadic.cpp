#include "stdafx.h"
#include <memory>
EXPORT_TEST(VariadicTest)

int sum() {
  return 0;
}

template <typename ... Types>
int sum(int first, Types ... rest) {
  return first + sum(rest...);
}

TEST(VariadicTest, unique_ptr_ownership) {
  ASSERT_EQ(sum(5, 4, 3), 5+4+3);
}