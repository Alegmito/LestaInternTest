#include <gtest/gtest.h>
#include <CircularBuffList.h>

namespace circularBufferTests {
  TEST(CircularBufferListTests, DefaultContstructor_CanNotPushAndPull)
  {
    auto buffer = CircularBuffList<int>();
    buffer.push(3);
    auto result = buffer.pop();

    ASSERT_TRUE(result.get() == nullptr);
  }

  TEST(CircularBufferListTests, AddsNewElements_WhenPushed)
  {
    auto buffer = CircularBuffList<int>(3);
    buffer.push(3)
      .push(4);
    auto actualSize = buffer.getSize();
    auto actualCurrentSize = buffer.getCurrentSize();
    ASSERT_EQ(actualSize, 3);
    ASSERT_EQ(actualCurrentSize, 2);
    ASSERT_EQ(*buffer.pop(), 3);
    ASSERT_EQ(*buffer.pop(), 4);
  }

  TEST(CircularBufferListTests, PushReplacesElements_WhenPushedAfterFull)
  {
    const auto replaceValue = 3;
    auto buffer = CircularBuffList<int>(1).push(2).push(replaceValue);
    ASSERT_EQ(*buffer.pop(), replaceValue);
  }

  TEST(CircularBufferListTests, PopReturnsNull_WhenNoElementsLeft)
  {
    const auto elementValue = 2;
    auto buffer = CircularBuffList<int>(1).push(elementValue);
    ASSERT_EQ(*buffer.pop(), elementValue);
    ASSERT_EQ(buffer.pop(), nullptr);
  }

  TEST(CircularBufferListTests, PushWorks_AfterPushAndPop)
  {
    const auto secondPush = 2;
    auto buffer = CircularBuffList<int>(1).push(1);
    buffer.pop();
    buffer.push(secondPush);
    ASSERT_EQ(*buffer.pop(), secondPush);
  }

  TEST(CircularBufferListTests, CopyConstructor_Works_WhenEmptyBufferInput)
  {
    auto fromCopy = CircularBuffList<int>(0);
    auto toCopy = CircularBuffList<int>(fromCopy);

    ASSERT_EQ(toCopy.getSize(), 0);
  }

  TEST(CircularBufferListTests, CopyConstructor_CopiesInputValues)
  {
    const auto first = 42;
    const auto second = 2012;
    const auto length = 2;
    auto fromCopy = CircularBuffList<int>(length)
      .push(first)
      .push(second);

    auto toCopy = CircularBuffList<int>(fromCopy);
    
    ASSERT_EQ(toCopy.getCurrentSize(), length);
    ASSERT_EQ(*toCopy.pop(), first);
    ASSERT_EQ(*toCopy.pop(), second);
  }
}
