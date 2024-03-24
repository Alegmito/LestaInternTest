// LestaInternCPPTest.cpp : Defines the entry point for the application.
//

#include "MixedSortBenchmark.h"
#include "Sort.h"
#include <chrono>
#include <vector>
#include <cstdarg>

template <typename Func, typename ...Args>
auto measureTimeExecution(Func&& func, Args&&... args)
{
  auto start = std::chrono::high_resolution_clock::now();
  func(args...);
  auto end = std::chrono::high_resolution_clock::now();

  return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

std::vector<int> CreateArrayToSort(size_t size)
{
  std::vector<int> array(size, 0);
  for (size_t i = 0; i < array.size(); i++)
  {
	array[i] = size - i;
  }
  return array;
}

using namespace std;

void RunMixedSortBenchmark(size_t size = 64)
{
  auto insertion = CreateArrayToSort(size);
  auto noInsertion = CreateArrayToSort(size);
  auto twoThreads = CreateArrayToSort(size);
  auto maxThreads = CreateArrayToSort(size);

  std::chrono::microseconds timeInsertion;
  if (size <= 100'000)
	timeInsertion = measureTimeExecution(MixedSort<int>, insertion.data(), size, size, 0);

  auto timeNoInsertion = measureTimeExecution(MixedSort<int>, noInsertion.data(), size, 0, 0);
  auto timeTwoThreads = measureTimeExecution(MixedSort<int>, twoThreads.data(), size, 0, 1);
  auto timeMaxThreads = measureTimeExecution(MixedSort<int>, maxThreads.data(), size, 0, GetSortConcurrencyDepth());

  cout << "Benchmark for size: " << size << endl;
  if (size <= 100'000)
	cout << "With insertion sort: " << timeInsertion.count() / std::pow(10, 3) << " millieconds" << endl;
  else
	cout << "With insertion sort: " << "too long" << endl;
  cout << "Ordinary merge sort: " << timeNoInsertion.count() / std::pow(10, 3) << " milliseconds" << endl;
  cout << "Two threaded merge sort: " << timeTwoThreads.count() / std::pow(10, 3) << " milliseconds" << endl;
  cout << "Max threaded merge sort: " << timeMaxThreads.count() / std::pow(10, 3) << " milliseconds" << endl;
}

int main()
{
	vector<size_t> benchmarkSizes = {  64, 1'000, 10'000, 100'000, 10'000'000, 100'000'000 };

	for (size_t& benchmarkSize: benchmarkSizes)
	{
	  RunMixedSortBenchmark(benchmarkSize);
	}
}