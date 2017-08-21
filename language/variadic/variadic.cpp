#include "stdafx.h"
#include <memory>
EXPORT_TEST(VariadicTest)

int sum () {
  return 0;
}

template <typename ... Types>
int sum (int first, Types ... rest) {
  return first + sum(rest...);
}

TEST(VariadicTest, unique_ptr_ownership) {
  ASSERT_EQ(sum(5, 4, 3), 5+4+3);
}

template <typename Iterator, typename T>
bool CompareN (Iterator&& iter, T&& value) {
  return (*iter == value);
}

template <typename Iterator, typename T1, typename ... Types>
bool CompareN (Iterator&& iter, T1&& value, Types&& ... args) {
  if (*iter != value) {
    return false;
  }
  return CompareN(std::forward<Iterator>(++iter), std::forward<Types>(args)...);
}

template <typename List, typename T1, typename...Types>
bool Compare (List&& container, T1&& first, Types&& ...args) {
  return CompareN(container.cbegin(), std::forward<T1>(first), std::forward<Types>(args)...);
}

TEST(VariadicTest, string_list) {
  std::vector<std::string> tokens = {
    "depth",
    "depth1",
    "depth2",
  };
  
  ASSERT_TRUE(Compare(tokens, "depth", "depth1", "depth2"));
}