#include <stdexcept>
#include "ShuntingYard.h"
#include "RPNExpression.h"


RPNExpression::Expression RPNExpression::stringToInfix(const std::string& str)
{
	Expression infix;
	std::istringstream iss(str);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			infix.push_back(std::stod(token));
		}
		else {
			infix.push_back(token);
		}
	}
	return infix;
}

bool RPNExpression::isNumber(const VariantType& token)
{
	//Checks if the variant tocken holds the alternative double
	return std::holds_alternative<double>(token);
}

bool RPNExpression::isOperator(const VariantType& token)
{
	if (std::holds_alternative<std::string>(token))
	{
		const std::string& op = std::get<std::string>(token);

		return op == "+" || op == "-" || op == "*" || op == "/";
	}
	return false;
}

bool RPNExpression::hasHigherPrecedence(const VariantType& op1, const VariantType& op2)
{
	auto precedence = [](const std::string& op)
		{
			if (op == "*" || op == "/") return 2;
			if (op == "+" || op == "-") return 1;
			return 0;
		};

	if (std::holds_alternative<std::string>(op1) && std::holds_alternative<std::string>(op2))
	{
		return precedence(std::get<std::string>(op1)) >= precedence(std::get<std::string>(op2));
	}
	return false;
}

bool RPNExpression::isOpenParenthesis(const VariantType& token)
{
	return std::holds_alternative<std::string>(token) && std::get<std::string>(token) == "(";
}

bool RPNExpression::isCloseParenthesis(const VariantType& token)
{
	return std::holds_alternative<std::string>(token) && std::get<std::string>(token) == ")";
}

void RPNExpression::Push(const VariantType& token)
{
	_expression.push_back(token);
}

void RPNExpression::Pop()
{
	if (!_expression.empty()) {
		_expression.pop_back();
	}
	else {
		throw std::runtime_error("attempted an empty expression");
	}
}

bool RPNExpression::Empty()
{
	return _expression.empty();
}


