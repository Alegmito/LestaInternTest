#include <gtest/gtest.h>

#include "Sort.h"
#include <vector>

namespace SortTests {

  auto generateTestArray(size_t size)
  {
    std::vector<int> unsorted(size, 1);
    std::vector<int> sorted(size, 1);
    for (size_t i = 0; i < size; i++)
    {
      sorted[i] = i;
      unsorted[size - i - 1] = i;
    }

    return std::tuple<std::vector<int>, std::vector<int>>({ unsorted , sorted });
  }

  TEST(SortTests, MergeSort_Works_WithNullptr)
  {
    MergeSort<int>(nullptr);
    SUCCEED();
  }

  TEST(SortTests, MergeSort_UsesInsertionDefault_WhenSmallArrays)
  {
    auto size = 100;
    auto [toSort, sorted] = generateTestArray(size);

    MixedSort(toSort.data(), size, size, 0);
    ASSERT_EQ(sorted, toSort);
  }

  TEST(SortTests, MergeSort_UsesMerge_WhenInsertionStepZero)
  {
    size_t size = 100;
    auto [toSort, sorted] = generateTestArray(size);

    MixedSort(toSort.data(), size, 0, 0);
    ASSERT_EQ(sorted, toSort);
  }

  TEST(SortTests, MergeSort_UsesThreads_WhenConcurrencyDepthNotZero)
  {
    size_t size = 1000;
    auto [toSort, sorted] = generateTestArray(size);

    MixedSort(toSort.data(), size, 64, 1);
    ASSERT_EQ(sorted, toSort);
  }

  TEST(SortTests, MergeSort_Works_WithArrays)
  {
    size_t size = 256;
    std::vector<int> unsorted(size, 1);
    std::vector<int> sorted(size, 1);
    for (size_t i = 0; i < size; i++)
    {
      sorted[i] = i;
      unsorted[size - i - 1] = i;
    }

    MixedSort(unsorted.data(), size);
    ASSERT_EQ(sorted, unsorted);

  }
}