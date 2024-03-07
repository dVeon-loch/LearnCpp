#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <variant>

class Display
{
public:
	using variantType = std::variant<double, std::string>;

	std::vector<std::variant<variantType>> _expression;

	Display() = default;
	
	void AddElement(std::vector<variantType>& _vector, const variantType& element);
	void RemoveElement();
	void BuildExpression();

	void PrintExpression(const std::vector<variantType>& _vector);

};

//•Operands
//•Operators
//•Parentheses
//•Functions
//•Statements