#pragma once
#include <array>

template <std::size_t MaxFactorial>
class FactorialCalculator
{
public:
  constexpr static auto CalculateFactorialUpTo()
  {
    std::array<unsigned long long, MaxFactorial + 1> factorial_array{};
    auto array_assigner = [&factorial_array](unsigned int index, unsigned long long value) constexpr
    {
      factorial_array[index] = value;
    };
    UnrollFactorialCalculation<MaxFactorial>(array_assigner);
    return factorial_array;
  }
private:
  template <unsigned int Index, typename FunctionType>
  constexpr static void UnrollFactorialCalculation(const FunctionType& function)
  {
    function(Index, CalculateFactorialAt<Index>());
    if constexpr (Index != 0u)
    {
      UnrollFactorialCalculation<Index - 1u>(function);
    }
  }

  template <unsigned int Index>
  constexpr static unsigned long long CalculateFactorialAt()
  {
    return CalculateFactorialAt<Index - 1u>() * Index;
  }

  template <>
  constexpr static unsigned long long CalculateFactorialAt<0u>()
  {
    return 1;
  }
};