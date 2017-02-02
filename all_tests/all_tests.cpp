#include "stdafx.h"
#include "gtest\gtest.h"
#include "all_tests\externs.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

