#include "SimpleCalculator.h"

void SimpleCalculator::RequestInput()
{
  std::string message = R"(
  Please enter the expression you would like to calculate.
  Simple operations are supported while taking into account order of operations.
  e.g. 1 + 2 - 5 * 6 + 7 / 2)";

  std::cout << message << "\n\n";
  std::string inputString;
  std::cin >> inputString;

  SetInputString(inputString);
  // TODO: Ask again if input not valid? How?
  ValidateInput();

  // TODO: Both implementations of CalculatorBase will pretty much do this exact same thing in the lines above. So we could potentially move the logic above this line into the base class
  // and then call it before doing the rest in each child class... But that is bad. Do some research on the 'Call Super' antipattern and how to fix it. Hint: template pattern

  // TODO: Parse input into usable structures
}

double SimpleCalculator::CalculateResult() const
{
  return 0.0;
}

bool SimpleCalculator::ValidateInput() const
{
  // TODO:
  // 1. Check if string only contains valid characters for this type of calculator
  // TIPS: 
  // how can we get rid of things like whitespace which is valid? A bit difficult in C++
  // SEE: https://stackoverflow.com/questions/31959532/best-way-to-remove-white-spaces-from-stdstring

  return false;
}
