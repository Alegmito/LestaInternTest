#pragma once
#include <thread>

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
void Merge(T* array, T* helper, const size_t start, const size_t mid, const size_t end) {
  
  size_t i = start,
    indexFirst = start,
    indexSecond = mid + 1;
  while (indexFirst <= mid && indexSecond <= end)
  {
    if (helper[indexFirst] < helper[indexSecond])
      array[i++] = helper[indexFirst++];
    else
      array[i++] = helper[indexSecond++];
  }

  if (indexSecond <= end)
    for (;i <= end; i++, indexSecond++)
      array[i] = helper[indexSecond];
  else
    for (;i <= end; i++, indexFirst++)
      array[i] = helper[indexFirst];

  for (size_t i = start; i <= end; i++)
    helper[i] = array[i];
}


int GetSortConcurrencyDepth()
{
  return (int)log2(std::thread::hardware_concurrency()) + 4;
}

template <class T>
void MixedSort(T* array, const size_t size, const size_t insertionSortTreshold = 64,
  int concurrencyDepth = GetSortConcurrencyDepth()) {

  if (array == nullptr)
    return;

  if (size <= insertionSortTreshold)
  {
    InsertionSort(array, 0, size - 1);
    return;
  }

  auto helper = new T[size]();
  for (size_t i = 0; i < size; i++)
    helper[i] = array[i];

  MergeSort(array, helper, 0, size - 1, concurrencyDepth);
  delete[] helper;
}

template <class T>
void MergeSort(T* array, T* helper, const size_t start = 0, const size_t end = 0, int concurrencyDepth = GetSortConcurrencyDepth()) {
  if (start == end)
    return;
  
  size_t mid = start + (end - start) / 2;
  if (concurrencyDepth > 0)
  {
    auto leftSortThread = std::thread(&MergeSort<T>, array, helper, start, mid, concurrencyDepth - 1);
    auto rightSortThread = std::thread(&MergeSort<T>, array, helper, mid + 1, end, concurrencyDepth - 1);

    leftSortThread.join();
    rightSortThread.join();
  }
  else
  {
    MergeSort(array, helper, start, mid, concurrencyDepth);
    MergeSort(array, helper, mid + 1, end, concurrencyDepth);
  }
  
  Merge(array, helper, start, mid, end);
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
