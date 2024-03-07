#include <iostream>
#include <limits>
#include "VariantVector.h"
#include "Display.h"
// CALCULATOR
// user input "Enter Number 1:"
// user input "Enter number 2:"
// "Enter operation:"
// +
// - 
// *
// /
// %
// Result: 
// Enter multiple numbers:
// Sum of numbers:
// lowest number:
// Highest number:
// Average:

int main()
{
	//todo: only accept integers and not characters
	//modify the calculator to use vectors, multiple numbers on a line etc
	//make use of funtions and possibly classes
	//make calculator a class 

	VariantVector expression;

	//expression.BuildExpression();

	char exit = 'b';

	while (exit != 'q')
	{
		double num1;
		std::cout << "Enter number 1: " << "\n";
		std::cin >> num1;
		expression.AddElement(num1);

		double num2;
		std::cout << "Enter number 2: " << "\n";
		std::cin >> num2;
		expression.AddElement(num2);


		std::string operation;
		std::cout << "Enter an operation: " << "\n";
		std::cin >> operation;
		expression.AddElement(operation);

		std::cout << "OPERATION " << operation << "\n";

		int result;

		bool isValid = true;

		switch (operation) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
		{
			if (num2 == 0)
			{
				result = -1;
				isValid = false;
			}
			else {
				result = num1 / num2;
			}
		}
		break;
		case '%':
			result = num1 % num2;
			break;
		default:
			result = -1;
		}
		if (isValid)
		{
			std::cout << "RESULT of : " << num1 << " " << operation << " " << num2 << " = " << result << "\n";
		}
		else {
			std::cout << "INVALID" << "\n";
		}

		std::cout << "Do you want to continue? Press q to quit, else any key to continue" << "\n";

		std::cin >> exit;


	}
	


	

	return 0;
}