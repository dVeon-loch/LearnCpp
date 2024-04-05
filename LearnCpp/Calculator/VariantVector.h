#pragma once
#include <variant>
#include <vector>
#include <string>
#include <iostream>
#include <variant>

//need to use c++ 17



class VariantVector
{

public:
	
	using VariantType = std::variant<double, std::string>;

	void addElement(const VariantType& element);
	void printElements();

private:

	std::vector<VariantType> elements;
	

};

