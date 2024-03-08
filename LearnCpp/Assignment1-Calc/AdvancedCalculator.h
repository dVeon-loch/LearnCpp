#pragma once
#include "CalculatorBase.h"

class AdvancedCalculator final : public CalculatorBase
{
private:
	// MEMBER VARIABLES GO HERE
public:

	explicit AdvancedCalculator(const std::string &name) : CalculatorBase(name) {};

	void RequestInput() override;

	double CalculateResult() const override;

	bool ValidateInput() const override;

private:
	// UTILITY METHODS GO HERE
};

