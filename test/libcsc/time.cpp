#include "libcsc/time/time.hpp"
#include <gtest/gtest.h>
#include <sstream>

using namespace csctime;
using namespace csctime::literals; 

TEST(TimeTest, ConstructorAndGetSeconds) {
  const Time t(12345);
  EXPECT_EQ(t.getSeconds(), 12345);
}

TEST(TimeTest, ComparisonOperators) {
  const Time t1(100);
  const Time t2(200);
  EXPECT_TRUE(t1 < t2);
  EXPECT_TRUE(t1 <= t2);
  EXPECT_FALSE(t1 > t2);
  EXPECT_FALSE(t1 >= t2);
  EXPECT_TRUE(t1 != t2);
}

TEST(TimeTest, OutputOperator) {
  const Time t(3666);
  std::ostringstream oss;
  oss << t;
  EXPECT_EQ(oss.str(), "0d 1h 1m 6s");
}

TEST(TimeSpanTest, ConstructorAndGetSeconds) {
  const TimeSpan ts(54321);
  EXPECT_EQ(ts.getSeconds(), 54321);
}

TEST(TimeSpanTest, ComparisonOperators) {
  const TimeSpan ts1(1000);
  const TimeSpan ts2(2000);
  EXPECT_TRUE(ts1 < ts2);
  EXPECT_TRUE(ts1 <= ts2);
  EXPECT_FALSE(ts1 > ts2);
  EXPECT_FALSE(ts1 >= ts2);
  EXPECT_TRUE(ts1 != ts2);
}

TEST(TimeSpanTest, OutputOperator) {
  const TimeSpan ts(54321);
  std::ostringstream oss;
  oss << ts;
  EXPECT_EQ(oss.str(), "0d 15h 5m 21s");
}

TEST(OverloadedOperatorsTest, PlusOperator) {
  const Time t(100);
  const TimeSpan ts(50);
  const Time result = t + ts;
  EXPECT_EQ(result.getSeconds(), 150);
}

TEST(OverloadedOperatorsTest, MinusOperator) {
  const Time t(100);
  const TimeSpan ts(50);
  const Time result = t - ts;
  EXPECT_EQ(result.getSeconds(), 50);
}

TEST(OverloadedOperatorsTest, TimeSpanMinusTime) {
  const Time t1(100);
  const Time t2(50);
  const TimeSpan result = t1 - t2;
  EXPECT_EQ(result.getSeconds(), 50);
}

TEST(LiteralsTest, DaysLiteral) {
  const TimeSpan ts = 2_d;
  EXPECT_EQ(ts.getSeconds(), 2 * 24 * 3600);
}

TEST(LiteralsTest, HoursLiteral) {
  const TimeSpan ts = 3_h;
  EXPECT_EQ(ts.getSeconds(), 3 * 3600);
}

TEST(LiteralsTest, MinutesLiteral) {
  const TimeSpan ts = 4_m;
  EXPECT_EQ(ts.getSeconds(), 4 * 60);
}

TEST(LiteralsTest, SecondsLiteral) {
  const TimeSpan ts = 5_s;
  EXPECT_EQ(ts.getSeconds(), 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
