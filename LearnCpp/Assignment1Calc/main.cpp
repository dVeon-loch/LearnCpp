#include <iostream>

#include <string>
#include <vector>

bool isNumeric;

int main()
{
	std::cout << "Welcome to the simple calculator!" << std::endl;
	std::cout << "Enter the first number:" << std::endl;
	std::string firstNum;

	std::cin >> firstNum;

	std::vector<std::string> calculations;
	calculations.resize(5);


	bool isNumeric = true;
	for (const auto& digit : firstNum)
	{
		bool charIsDigit = std::isdigit(digit);
		if (!charIsDigit)
		{
			isNumeric = false;
			break;
		}
	}

	std::cout << "Enter the second number:" << std::endl;
	std::string secondNum;

	std::cin >> secondNum;

	for (const auto& digit : secondNum)
	{
		bool charIsDigit = std::isdigit(digit);
		if (!charIsDigit)
		{
			isNumeric = false;
			break;
		}
	}

	if (!isNumeric)
	{
		std::cout << "Invalid Input!" << std::endl;
		return 1;
	}

	std::cout << "Enter the operation (+, -, *, /):" << std::endl;
	std::string operation;

	std::cin >> operation;

	if (operation.length() > 1)
	{
		std::cout << "Invalid Operation!" << std::endl;
		return 1;
	}

	std::cout << "You entered: " << firstNum << " " << operation << " " << secondNum << std::endl;

	// DO CALC
	int result = 99999;

	// CTRL + K + C   Comment
	// CTRL + K + U   Uncomment


	if (operation == "+")
	{
		
		result = std::stoi(firstNum) + std::stoi(secondNum);
	}
	else if (operation == "-")
	{
		result = std::stoi(firstNum) - std::stoi(secondNum);
	} 
	else if (operation == "*")
	{
		result = std::stoi(firstNum) * std::stoi(secondNum);
	} 
	else if (operation == "/")
	{
		try 
		{
		result = std::stoi(firstNum) / std::stoi(secondNum);
		}
		catch (...) 
		{
			std::cout << "ERROR!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid operation entered: " << operation << std::endl;
		return 1;
	}

	

	std::cout << "Result is: " << result << std::endl;

	// It needs to do all the basic operations - DONE
	// It needs to reject invalid values - MOSTLY done , some left...
	// It needs to repeat after doing a calculation // TODO
	// It needs to respect overflows // TODO
	// It needs to account for divide by zero // TODO
	// It needs to store a history of values // TODO

	// Refactor this into headers
	// Add some functions
	// Refactor operations into switch case
	// Add a namespace for functions
	// Chain 5 calculations up, and calculate all of their results at the end...
}