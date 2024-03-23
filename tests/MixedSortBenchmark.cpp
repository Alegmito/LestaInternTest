// LestaInternCPPTest.cpp : Defines the entry point for the application.
//

#include "MixedSortBenchmark.h"
#include "Sort.h"
#include <chrono>
#include <vector>
#include <cstdarg>

template <typename F, typename ...Args>
auto apply(F&& function, Args&&... arguments)
-> decltype(function(std::forward<Args>(arguments)...))
{
  return function(std::forward<Args>(arguments)...);
}

template </*typename TDuration = std::chrono::seconds, */typename Func, typename ...Args>
auto measureTimeExecution(Func&& func, Args&&... args)
{
  auto start = std::chrono::high_resolution_clock::now();
  func(args...);
  auto end = std::chrono::high_resolution_clock::now();

  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
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

  std::chrono::milliseconds timeInsertion;
  if (size <= 100000)
  {
	timeInsertion = measureTimeExecution(MixedSort<int>, insertion.data(), size, size, 0);
  }
  auto timeNoInsertion = measureTimeExecution(MixedSort<int>, noInsertion.data(), size, 0, 0);
  auto timeTwoThreads = measureTimeExecution(MixedSort<int>, twoThreads.data(), size, 0, 1);
  auto timeMaxThreads = measureTimeExecution(MixedSort<int>, maxThreads.data(), size, 0, GetSortConcurrencyDepth());

  cout << "Benchmark for size: " << size << endl;
  cout << "With insertion sort: " << timeInsertion.count() << " millieconds" << endl;
  cout << "Ordinary merge sort: " << timeNoInsertion.count() << " milliseconds" << endl;
  cout << "Two threaded merge sort: " << timeTwoThreads.count() << " milliseconds" << endl;
  cout << "Max threaded merge sort: " << timeMaxThreads.count() << " milliseconds" << endl;
}

int main()
{
	cout << "Hello CMake." << endl;
    const auto numberOfElements = 2;

	auto fun = [](std::string a, std::string const& b) { return a += b; };
	auto result = "Hello world";
	std::string s("world");

	vector<size_t> benchmarkSizes = { 10000, 100000/*, 10000000*/ };

	for (size_t& benchmarkSize: benchmarkSizes)
	{
	  RunMixedSortBenchmark(benchmarkSize);
	}
}