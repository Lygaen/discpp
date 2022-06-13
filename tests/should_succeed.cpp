#include <gtest/gtest.h>

TEST(ShouldSucceed, IntSize)
{
    ASSERT_EQ(sizeof(int), 4);
}

TEST(ShouldSucceed, LongLongSize)
{
    ASSERT_EQ(sizeof(long long), 8);
}

TEST(ShouldSucceed, FloatSize)
{
    ASSERT_EQ(sizeof(float), 4);
}

TEST(ShouldSucceed, LongDoubleSize)
{
    ASSERT_EQ(sizeof(double), 8);
}