#pragma once
#include <optional>


template <class T>
class CircularBuffArray {
  size_t currentSize = 0;
  size_t bufferStart = 0;
  size_t size = 0;
  T* data_ = nullptr;

  void copyData(const CircularBuffArray& from)
  {
    data_ = (T*) operator new(from.size * sizeof(T));
    // copy till capacity to initialize all memory
    for (size_t i = 0, fromIndex = from.bufferStart; i < from.size; i++)
    {
      new (data_ + i) T(from.data_[fromIndex]);
      fromIndex = (fromIndex + 1) % size;
    }
  };

  void freeData()
  {
    freeData(data_);
    data_ = nullptr;
  };

  void freeData(T* data);

public:
  CircularBuffArray(size_t size, const T& value = T());

  CircularBuffArray() {};

  CircularBuffArray(CircularBuffArray& from);

  ~CircularBuffArray();

  CircularBuffArray& operator=(const CircularBuffArray& from);

  void clear();

  CircularBuffArray& push(T& value);

  std::optional<T> pop();

  size_t getCurrentSize() const { return currentSize; };

  size_t getSize() const { return size; };
};

template<class T>
void CircularBuffArray<T>::freeData(T* data)
{
  if (data == nullptr)
    return;

  for (size_t i = 0; i < size; i++)
    data[i].~T();

  operator delete[](data);
}

template<class T>
CircularBuffArray<T>::CircularBuffArray(size_t size, const T& defaultValue)
// Use placement new in order to weaken requirements for T
  :size(size)
{
  if (size == 0)
    return;

  data_ = (T*) operator new(size * sizeof(T));
  for (size_t i = 0; i < size; i++)
    new (data_ + i) T(defaultValue);
}

template<class T>
CircularBuffArray<T>::CircularBuffArray(CircularBuffArray& from)
  :size(from.size), currentSize(from.currentSize)
{
  if (size == 0)
    return;
  
  copyData(from);
}

template<class T>
CircularBuffArray<T>::~CircularBuffArray()
{
  freeData();
  clear();
  size = 0;
}

template<class T>
CircularBuffArray<T>& CircularBuffArray<T>::operator=(const CircularBuffArray& from)
{
  if (this == &from)
    return *this;

  if (from.size == 0)
  {
    freeData();
    clear();
    size = 0;
    return *this;
  }

  auto previousData = data_;

  copyData(from);
  size = from.size;
  currentSize = from.currentSize;
  freeData(previousData);
}

template<class T>
void CircularBuffArray<T>::clear()
{
  bufferStart = 0;
  currentSize = 0;
}

template<class T>
CircularBuffArray<T>& CircularBuffArray<T>::push(T& value)
{
  if (size == 0)
    return *this;

  if (currentSize < size)
    currentSize++;
  else
    bufferStart = (bufferStart + 1) % size;

  auto pushIndex = (bufferStart + currentSize - 1) % size;
  data_[pushIndex] = value;
  return *this;
}

template<class T>
std::optional<T> CircularBuffArray<T>::pop()
{
  if (currentSize == 0)
    return std::nullopt;
 
  auto resultIndex = bufferStart;
  bufferStart = (bufferStart + 1) % size;
  currentSize--;

  return std::optional<T>(data_[resultIndex]);
}

// for testing purposes
class NumWrap {
  double number;
public:
  NumWrap(double num) : number(num) {};
  NumWrap(const NumWrap& num) : number(num.number) {};
  NumWrap& operator=(const NumWrap& num)
  {
    if (&num == this)
      return *this;

    number = num.number;

    return *this;
  }
  ~NumWrap()
  {
    int a = 0;
  };
};