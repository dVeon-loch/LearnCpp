#include "VariantVector.h"

void VariantVector::addElement(const VariantType& element)
{
	elements.push_back(element);
}

void VariantVector::printElements()
{
	for (const auto& elem : elements) 
	{
		std::visit([](const auto& val) { std::cout << val << std::endl; }, elem);
	}
}
