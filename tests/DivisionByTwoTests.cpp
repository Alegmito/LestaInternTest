#include <gtest/gtest.h>
#include <DivisionByTwo.h>
#include <functional>

  TEST(DivisionByTwoTests, IsEvenBit_Works)
  {
    EXPECT_TRUE(isEvenBit(0));
    EXPECT_TRUE(isEvenBit(22));
    EXPECT_FALSE(isEvenBit(53));
    EXPECT_FALSE(isEvenBit(-11));
    EXPECT_TRUE(isEvenBit(-42));
  }

  TEST(DivisionByTwoTests, IsEvenShift_Works)
  {
    EXPECT_TRUE(isEvenShift(0));
    EXPECT_TRUE(isEvenShift(42));
    EXPECT_FALSE(isEvenShift(33));
    EXPECT_FALSE(isEvenShift(-11));
    EXPECT_TRUE(isEvenShift(-42));
  }

  TEST(DivisionByTwoTests, IsEvenRandomJoke_ProbabilityIsAboutFiftyPercent)
  {
    auto probability = 0.f;
    auto count = 1000;
    for (size_t i = 0; i < count; i++)
    {
      probability += isEven(i) == isEvenRandomJoke(i) ? 1.f / count : 0;
    }

    ASSERT_TRUE(probability > 0.45 && probability < 0.55);
  }

  TEST(DivisionByTwoTests, IsEvenArrayJoke_Works)
  {
    auto evens = { 0, 22, 14, 36, 338 };
    auto odds = { 1, 53, 555 };

    for (auto& even : evens)
      ASSERT_TRUE(isEvenArrayJoke(even));

    for (auto& odd : odds)
      ASSERT_FALSE(isEvenArrayJoke(odd));
  }