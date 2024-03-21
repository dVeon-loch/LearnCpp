#include "SimpleCalculator.h"
#include <sstream>
#include <locale>
//#include <string>
#include <locale>

void SimpleCalculator::RequestInput()
{
  #define MAX_NAME_LEN 16
  std::string message = R"(
  Please enter the expression you would like to calculate.
  Simple operations are supported while taking into account order of operations.
  e.g. 1 + 2 - 5 * 6 + 7 / 2)";

  std::cout << message << std::endl << std::endl;
  std::string inputString;
  
  // If there was a previous std::cin, clear the input buffer:
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::getline(std::cin, inputString);
  
  //std::cin >> inputString;

  SetInputString(inputString);
  // TODO: Ask again if input not valid? How?
  // TODO: Do something with this result
  ValidateInput();

  // TODO: Both implementations of CalculatorBase will pretty much do this exact same thing in the lines above. So we could potentially move the logic above this line into the base class
  // and then call it before doing the rest in each child class... But that is bad. Do some research on the 'Call Super' antipattern and how to fix it. Hint: template pattern

  // TODO: Parse input into usable structures
  // ProcessInput
  // Set a flag to say that has been processed
}

double SimpleCalculator::CalculateResult() const
{
	ValidateInput();
	// Check flag that input has been processed else return exception or something like that
  return 0.0;
}

bool SimpleCalculator::ValidateInput() const
{
  // TODO:
  // 1. Check if string only contains valid characters for this type of calculator
  // TIPS: 
  // how can we get rid of things like whitespace which is valid? A bit difficult in C++
  // SEE: https://stackoverflow.com/questions/31959532/best-way-to-remove-white-spaces-from-stdstring
  // USING: https://stackoverflow.com/questions/6605282/how-can-i-check-if-a-string-has-special-characters-in-c-effectively
	
	const std::string validChars = "0123456789+-*/";

	// TODO: Investigate using a std::set of validChars, and checking if a char is in that set as you loop through the string.

	std::string rawInput = GetRawInputString();

	rawInput.erase(std::remove_if(
		begin(rawInput), end(rawInput),
		[l = std::locale{}](char ch) { return std::isspace(ch, l); }
	), end(rawInput));

	if (rawInput.find_first_not_of(validChars) != std::string::npos)
	{
		std::cerr << "Error: invalid character \n";
		return false;
	}
	

  return true;
}
