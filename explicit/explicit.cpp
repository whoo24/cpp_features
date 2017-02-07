#include "stdafx.h"
EXPORT_TEST(ExplicitTest)

struct foo {
  operator int() {
    return 42;
  }
};

TEST(ExplicitTest, implicit) {
  foo f;
  int i = f;
  ASSERT_EQ(i, 42);
}

struct boo {
  explicit operator int() {
    return 42;
  }
};

TEST(ExplicitTest, explict) {
  boo f;
  int i = static_cast<int>(f); // error C2440  int i = f;
  ASSERT_EQ(i, 42);
}
