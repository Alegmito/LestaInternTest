#pragma once

bool isEven(int value);

template<int N>
struct IsEvenTemplate
{
  static bool const value = (N & 1) == 0;
};

bool isEvenBit(int value) ;

bool isEvenShift(int value);

bool isEvenRandomJoke(int value);

bool isEvenArrayJoke(int value);