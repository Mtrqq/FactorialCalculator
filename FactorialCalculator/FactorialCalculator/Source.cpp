#include "FactorialCalculator.h"

#include <iostream>
#include <chrono>

int main()
{
  std::ios::sync_with_stdio(false);
  auto start = std::chrono::high_resolution_clock::now();
  constexpr auto factorial_array = FactorialCalculator<50>::CalculateFactorialUpTo();
  auto stop = std::chrono::high_resolution_clock::now();
  std::cout << "Timing :" << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
  for (auto element : factorial_array)
  {
    std::cout << element << '\n';
  }
}