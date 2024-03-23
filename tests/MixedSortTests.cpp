#include <gtest/gtest.h>

#include "Sort.h"
#include <vector>

namespace SortTests {
  TEST(SortTests, MergeSort_Works_WithNullptr)
  {
    MergeSort<int>(nullptr);
    SUCCEED();
  }

  TEST(SortTests, MergeSort_Works_WithArrays)
  {
    size_t size = 256;
    std::vector<int> unsorted(256, 1);
    std::vector<int> sorted(256, 1);
    for (size_t i = 0; i < size; i++)
    {
      sorted[i] = i;
      unsorted[size - i] = i;
    }

    MergeSort(unsorted.data(), 0, size);

  }
}