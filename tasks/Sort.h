#pragma once
#include <thread>
#include <execution>

template <class T>
void InsertionSort(T* array, const size_t startIndex, const size_t endIndex) {
  for (size_t i = startIndex + 1; i <= endIndex; i++)
  {
    auto insertCopy = array[i];
    size_t insertIndex = i;

    for (; insertCopy < array[insertIndex - 1] && insertIndex > startIndex; insertIndex--)
      array[insertIndex] = array[insertIndex - 1];

    array[insertIndex] = insertCopy;
  }
}

template <class T>
void Merge(T* array, const size_t start, const size_t mid, const size_t end) {
  auto length = end - start + 1;
  auto copy = new T[length]();

  for (size_t i = 0, j = start; j <= end; i++, j++)
    copy[i] = array[j];
  
  size_t i = start;
  size_t indexFirst = 0;
  size_t indexSecond = mid - start;
  while (indexFirst < mid - start && indexSecond < length)
  {
    if (copy[indexFirst] < copy[indexSecond]) {
      array[i] = copy[indexFirst];
      indexFirst++;
    }
    else {
      array[i] = copy[indexSecond];
      indexSecond++;
    }
    i++;
  }

  if (indexSecond < length)
    for (;i <= end; i++, indexSecond++)
      array[i] = copy[indexSecond];
  else
    for (;i <= end; i++, indexFirst++)
      array[i] = copy[indexFirst];

  delete[] copy;
}


int GetSortConcurrencyDepth()
{
  return (int)log2(std::thread::hardware_concurrency()) + 4;
}

template <class T>
void MixedSort(T* array, const size_t size, const size_t insertionSortTreshold = 64,
  int concurrencyDepth = GetSortConcurrencyDepth()) {
  if (size > insertionSortTreshold)
    MergeSort(array, 0, size - 1, concurrencyDepth);
  else
    InsertionSort(array, 0, size - 1);
}

template <class T>
void MergeSort(T* array, const size_t start = 0, const size_t end = 0, int concurrencyDepth = GetSortConcurrencyDepth()) {
  if (start == end)
    return;
  
  size_t mid = start + (end - start) / 2;
  if (concurrencyDepth > 0)
  {
    auto leftSortThread = std::thread(&MergeSort<T>, array, start, mid, concurrencyDepth - 1);
    auto rightSortThread = std::thread(&MergeSort<T>, array, mid + 1, end, concurrencyDepth - 1);

    leftSortThread.join();
    rightSortThread.join();
  }
  else
  {
    MergeSort(array, start, mid, concurrencyDepth);
    MergeSort(array, mid + 1, end, concurrencyDepth);
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
