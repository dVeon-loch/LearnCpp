#pragma once

#include <iostream>

class CalculatorBase
{
private:
	std::string _name;

	std::string _rawInputString = "";

public:
	explicit CalculatorBase(const std::string &name) : _name(name) {}

	virtual ~CalculatorBase() = default;

	// PURE VIRTUALS, MUST OVERRIDE
	virtual void RequestInput() = 0; 

	virtual bool ValidateInput() const = 0;

	virtual double CalculateResult() const = 0; // TAKE NOTE OF	const USAGE HERE. WHY SHOULD THIS BE CONST?


	// NON-PURE VIRTUALS, OVERRIDE AS NEEDED
	virtual void PrintWelcomeMessage() const 
	{
		std::cout << "Welcome to CalculatorSimulator 2024\n";
	}

	// NON-OVERRIDABLES
	std::string GetName() const { return _name; };

protected:
	virtual void SetInputString(const std::string &inputString) { _rawInputString = inputString; }
};

