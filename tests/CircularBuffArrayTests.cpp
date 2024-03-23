#include <gtest/gtest.h>
#include <CircularBuffArray.h>
#include <vector>

namespace circularBufferTests {

  TEST(CircularBuffArrayTests, Push_AddsElements) {
    const auto numberOfElements = 2;
    NumWrap initial(1);
    CircularBuffArray<NumWrap> buffer_(numberOfElements, initial);
    buffer_.push(NumWrap(3));
    buffer_.push(NumWrap(2));
    
    EXPECT_EQ(buffer_.getCurrentSize(), buffer_.getSize());
    EXPECT_EQ(buffer_.getSize(), numberOfElements);
  }

  TEST(CircularBuffArrayTests, Empty_DefaultContstructor_CantPushAndPop) {
    auto buffer = CircularBuffArray<NumWrap>();
    buffer.push(NumWrap(42));
    auto result = buffer.pop();
    EXPECT_FALSE(result.has_value());
  }

  TEST(CircularBuffArrayTests, ZeroSizedBuff_CantPushAndPop)
  {
    auto buffer = CircularBuffArray<NumWrap>(0, NumWrap(3));
    buffer.push(NumWrap(42));
    auto result = buffer.pop();
    EXPECT_FALSE(result.has_value());
  }

  TEST(CircularBuffArrayTests, CopyConstructor_Works_WhenCopyEmpty)
  {
    auto fromCopy = CircularBuffArray<int>(0);
    auto ToCopy = CircularBuffArray(fromCopy);

    EXPECT_FALSE(ToCopy.pop().has_value());
  }

  TEST(CircularBuffArrayTests, CopyConstructor_Works_WhenCopyNotEmpty)
  {
    auto size = 2;
    auto fromCopy = CircularBuffArray<int>(size);
    std::vector<int> values = { 2, 3, 4 };
    for (auto value : values)
      fromCopy.push(value);
    values[1] = 5;

    auto toCopy = CircularBuffArray<int>(fromCopy);
    EXPECT_TRUE(toCopy.getSize() == size && toCopy.getCurrentSize() == size);
    EXPECT_TRUE(toCopy.pop() == 3);
    EXPECT_TRUE(toCopy.pop() == 4);
  }

  TEST(CircularBuffArrayTests, AssignemtOp_DoNotChange_WhenAssignToSelf)
  {
    auto buffer = CircularBuffArray<NumWrap>(1, NumWrap(1));
    buffer = buffer;

    EXPECT_TRUE(buffer.getCurrentSize() == 0);
    EXPECT_TRUE(buffer.getSize() == 1);
  }

  TEST(CircularBuffArrayTests, AssignemtOp_MakesBufferEmpty_WhenAssignToEmpty)
  {
    auto buffer = CircularBuffArray<NumWrap>(3, NumWrap(1));
    auto empty = CircularBuffArray<NumWrap>();
    buffer = empty;

    EXPECT_TRUE(buffer.getSize() == 0);
  }

  TEST(CircularBuffArrayTests, AssignemtOp_Works_WhenAssignToSmallerBuffer)
  {
    auto buffer = CircularBuffArray<NumWrap>(3, NumWrap(1));
    auto toCopy = CircularBuffArray<NumWrap>(2, NumWrap(1));
    toCopy.push(NumWrap(3));

    buffer = toCopy;

    ASSERT_TRUE(buffer.getSize() == 2);
    ASSERT_TRUE(buffer.getCurrentSize() == 1);
    ASSERT_TRUE(buffer.pop().has_value());
    ASSERT_FALSE(buffer.pop().has_value());
  }

  TEST(CircularBuffArrayTests, AssignemtOp_Works_WhenAssignToBiggerBuffer)
  {
    auto buffer = CircularBuffArray<NumWrap>(1, NumWrap(1));
    auto toCopy = CircularBuffArray<NumWrap>(2, NumWrap(1));
    toCopy.push(NumWrap(3))
      .push(NumWrap(3));

    buffer = toCopy;

    ASSERT_TRUE(buffer.getSize() == 2);
    ASSERT_TRUE(buffer.getCurrentSize() == 2);
    ASSERT_TRUE(buffer.pop().has_value());
    ASSERT_TRUE(buffer.pop().has_value());
    ASSERT_FALSE(buffer.pop().has_value());
  }
}