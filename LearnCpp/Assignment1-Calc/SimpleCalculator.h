#pragma once

#include "CalculatorBase.h"

class SimpleCalculator final : public CalculatorBase
{
private:
	// MEMBER VARIABLES GO HERE
public:

	explicit SimpleCalculator(const std::string &name) : CalculatorBase(name) {};

	void RequestInput() override;

	double CalculateResult() const override;

	virtual bool ValidateInput() const;

private:
	// UTILITY METHODS GO HERE
};

