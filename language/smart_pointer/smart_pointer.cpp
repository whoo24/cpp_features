#include "stdafx.h"
#include <memory>
EXPORT_TEST(SmartPointerTest)

struct Boo {
  Boo() {
  }

  ~Boo() {
  }
};

TEST(SmartPointerTest, unique_ptr_ownership) {
  std::unique_ptr<Boo> up(new Boo());
  ASSERT_TRUE(up.get());

  const Boo* const up_ptr = up.get();
  ASSERT_TRUE(up.get());
  ASSERT_EQ(up.get(), up_ptr);

  Boo* fp = up.release();

  ASSERT_FALSE(up.get());
  ASSERT_FALSE(up.release());
  ASSERT_TRUE(fp);
  ASSERT_EQ(fp, up_ptr);

  delete fp;
}