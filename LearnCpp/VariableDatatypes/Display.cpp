#include "display.h"
#include <iostream>


void Display::AddElement(std::vector<variantType>& _vector, const variantType& element)
{
	_vector.push_back(element);
}

//remove the last placed item
void Display::RemoveElement()
{
}

void Display::PrintExpression(const std::vector<variantType>& _vector)
{
	//const auto&  avoid copy
	for (const auto& element : _vector) {
		//std::cout << element << std::endl;
	}
}

void Display::BuildExpression()
{
	std::cout << "Enter Q to stop " << "\n";

	std::string exit = "";

	while (exit != "q")
	{


		double num1;
		std::cout << "Enter number 1: " << "\n";
		std::cin >> num1;

		AddElement(num1);

		double num2;
		std::cout << "Enter number 2: " << "\n";
		std::cin >> num2;

		char operation;
		std::cout << "Enter an operation: " << "\n";
		std::cin >> operation;

		std::cout << "OPERATION " << operation << "\n";
	}

	PrintExpression(_expression);

	return;


	
}
