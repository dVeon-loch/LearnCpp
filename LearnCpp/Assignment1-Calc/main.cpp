#include "SimpleCalculator.h"
#include "AdvancedCalculator.h"

#include <iostream>
#include <memory>
#include <vector>
#include <format>

static void PrintHorizontalRule()
{
	std::cout << "--------------------------------------------\n\n";
}

int main()
{
	char userInput = 'a';

	std::vector<std::unique_ptr<CalculatorBase>> calculators; // See usage of pointers for Polymorphic behaviour

	calculators.emplace_back(std::make_unique<SimpleCalculator>("Simple Calculator"));
	//calculators.emplace_back(std::make_unique<AdvancedCalculator>("Advanced Calculator"));


	while (userInput != 'q')
	{
		std::cout << "Choose a calculator:\n";
		for (size_t i = 0; i < calculators.size(); i++)
		{
			std::cout << std::format("\t{}. {}\n", i, calculators[i]->GetName());
		}
		PrintHorizontalRule();

		size_t choice;
		std::cin >> choice;

		const bool validChoice = choice >= 0 && choice < calculators.size();

		if (!validChoice) continue;
		std::string expression = "";
		calculators[choice]->RequestInput();

 		std::cout << std::format("Calculated Result: {}\n", calculators[choice]->CalculateResult());
		
		PrintHorizontalRule();

		userInput = 'q';
	}
}