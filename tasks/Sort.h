#pragma once
#include <thread>

template <class T>
void insertionSort(T* array, const size_t startIndex, const size_t endIndex) {
  for (size_t i = startIndex + 1; i < endIndex; i++)
  {
    auto insertCopy = array[i];
    size_t insertIndex = i;

    for (size_t j = i; insertCopy < array[j] || j > 0; j--)
      array[j] = array[j - 1];

    array[insertIndex] = insertCopy;
  }
}

template <class T>
void Merge(T* array, const size_t start, const size_t mid, const size_t end) {
  auto length = end - start + 1;
  auto copy = new T[length]();

  for (size_t i = 0, j = start; j < end; i++, j++)
    copy[i] = array[j];
  
  size_t i = 0;
  size_t indexFirstHalf = 0;
  size_t indexSecondHalf = mid - start;
  while (indexFirstHalf < mid - start || indexSecondHalf < length)
  {
    auto compared = copy[indexFirstHalf] < copy[indexSecondHalf];
    if (copy[indexFirstHalf] < copy[indexSecondHalf]) {
      array[i] = copy[indexFirstHalf];
      indexFirstHalf++;
    }
    else {
      array[i] = copy[indexSecondHalf];
      indexSecondHalf++;
    }
    i++;
  }

  if (indexSecondHalf < length)
    for (;i < length; i++, indexSecondHalf++)
      array[i] = copy[indexSecondHalf];
  else
    for (;i < length; i++, indexFirstHalf++)
      array[i] = copy[indexFirstHalf];

  delete[] copy;
}


int GetSortConcurrencyDepth()
{
  return (int)log2(std::thread::hardware_concurrency()) + 4;
}

template <class T>
void MergeSort(T* array, const size_t start = 0, const size_t end = 0, const size_t insertionSortStep = 64,
  int concurrencyDepth = GetSortConcurrencyDepth()) {
  if (end - start + 1 <= insertionSortStep)
    return insertionSort(array, start, end);

  if (start == end)
    return;
  
  size_t mid = end / 2;
  if (concurrencyDepth > 0)
  {
    auto leftSortThread = std::thread(&MergeSort<T>, array, start, mid, insertionSortStep, concurrencyDepth - 1);
    auto rightSortThread = std::thread(&MergeSort<T>, array, mid + 1, end, insertionSortStep, concurrencyDepth - 1);

    leftSortThread.join();
    rightSortThread.join();
  }
  else
  {
    MergeSort(array, start, mid, insertionSortStep);
    MergeSort(array, mid + 1, end, insertionSortStep);
  }
  
  Merge(array, start, mid + 1, end);
}

template <class T>
void MergeSortIterative(T* array, size_t start, size_t end, const size_t insertionSortStep = 64) {
  if (insertionSortStep > 0)
  {
    for (size_t i = 0; i < size; i += insertionSortStep)
    {
      size_t nextIndex = i + insertionSortStep;
      insertionSort(array, i, nextIndex > size ? size : nextIndex;)
    }

  }

  size_t MergeSteps = size
    for (size_t i = 1, j = insertionSortStep; i <= size; i++)
    {
      size_t j =
    }
  for (size_t j = 0; j < size)
}
