#include "divisionByTwo.h"
#include <random>

bool isEven(int value) { return value % 2 == 0; }

bool isEvenBit(int value) {
  return (value & 1) == 0;
}

bool isEvenShift(int value)
{
  return (value - (value >> 1 << 1)) == 0;
}

bool isEvenRandomJoke(int value = 0)
{
  std::random_device rd;
  
  std::uniform_int_distribution<int> distribution(0, 1);
  
  return distribution(rd);
}

bool isEvenArrayJoke(int value)
{
  auto lastDigit = value % 10;
  auto evens = { 0, 2, 4, 6, 8 };
  for (auto & even : evens)
  {
    if (even == lastDigit)
      return true;
  }
  return false;
}