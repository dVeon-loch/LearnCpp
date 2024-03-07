#include "VariantVector.h"

void VariantVector::AddElement(const variantType& element)
{
	elements.push_back(element);
}

void VariantVector::RemoveElement()
{
	elements.pop_back();
}

void VariantVector::PrintElements()
{
	for (const auto& element : elements)
	{
		std::visit([](const auto& value) {std::cout << value << std::endl; }, element);
	}
}
