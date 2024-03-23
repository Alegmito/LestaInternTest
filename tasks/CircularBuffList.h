#pragma once
#include <memory>

template <class T>
class Element {
  std::unique_ptr<T> data;
  Element* next = nullptr;
public:
  Element(const T& data_ = T()) {
    data = std::unique_ptr<T>(new T(data_));
  }
  void setNext(Element<T>* next_) { next = next_; }
  Element* getNext() { return next; }
  std::unique_ptr<T>& getData(){ return data; }
  void setData(const T& data_ = T()) { data.reset(new T(data_)); }
};

template <class T>
class CircularBuffList {
  size_t size = 0;
  size_t currentSize = 0;

  Element<T>* start = nullptr;
  Element<T>* end = nullptr;
public:
  CircularBuffList(size_t size_ = 0) : size(size_){ };

  CircularBuffList(const CircularBuffList<T>& from)
    : size(from.size), currentSize(from.currentSize)
  {
    if (from.start == nullptr)
      return;

    auto current = start = new Element<T>(*from.start->getData());
    auto fromCurrent = from.start->getNext();
    while (fromCurrent != nullptr)
    {
      auto previous = current;
      current = new Element<T>(*fromCurrent->getData());
      previous->setNext(current);
      fromCurrent = fromCurrent->getNext();
    }
    end = current;
    if (current->getNext() == nullptr)
    {

    }
  };

  ~CircularBuffList() {
    while (start != nullptr)
    {
      auto toDelete = start;
      start = start->getNext();
      delete toDelete;
    }
    end = nullptr;
    currentSize = 0;
    size = 0;
  }

  CircularBuffList& push(const T& value) {
    if (size == 0)
      return *this;

    auto newElement = new Element<T>(value);

    if (start == nullptr)
    {
      start = end = newElement;
      currentSize++;
      return *this;
    }

    if (size == currentSize && start == end)
    {
      auto startCopy = start;
      start = end = newElement;
      delete startCopy;
      return *this;
    }

    if (size == currentSize)
    {
      auto startCopy = start;
      start = start->getNext();
      delete startCopy;
    }

    if (size > currentSize)
      currentSize++;

    auto endCopy = end;
    end = newElement;

    if (endCopy != nullptr)
      endCopy->setNext(end);

    return* this;
  };

  std::unique_ptr<T> pop() {

    std::unique_ptr<T> result(nullptr);
    if (size == 0 || currentSize == 0)
      return result;

    currentSize--;
    auto startCopy = start;
    if (start->getNext() != nullptr)
      start = start->getNext();
    else
      start = end = nullptr;

    result.swap(startCopy->getData());
    delete startCopy;
    return result;
  };

  size_t getSize() { return size; }
  size_t getCurrentSize() { return currentSize; }
};