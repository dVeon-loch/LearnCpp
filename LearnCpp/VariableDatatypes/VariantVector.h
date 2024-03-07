#pragma once
#include <variant>
#include <string>
#include <vector>
#include <iostream>
class VariantVector
{
public:
	
	VariantVector() = default;

	using variantType = std::variant<double, std::string>;

	std::vector<std::variant<variantType>> _expression;

	

	void AddElement(const variantType& element);
	void RemoveElement();
	void BuildExpression();

	void PrintElements();

private:

	std::vector<variantType> elements;
};

