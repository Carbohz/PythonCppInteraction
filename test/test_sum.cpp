#include "sum.h"
#include <gtest/gtest.h>

TEST(DummyLib, Sum) {
  int a = 2;
  int b = 3;
  int c = Sum(a, b);

  ASSERT_EQ(c, 5);
}