#include <stdexcept>
#include "ShuntingYard.h"
#include "RPNExpression.h"
#include <stack>


void RPNExpression::stringToInfix(const std::string& str)
{
	std::istringstream iss(str);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			_infix.push_back(std::stod(token));
		}
		else 
		{
			_infix.push_back(token);
		}
	}

	infixToPostfix(_infix);
	return ;
}

void RPNExpression::infixToPostfix(Expression infix)
{
	Expression postfix;
	std::stack<VariantType> opStack;
	

	for (const auto& token : _infix) 
	{
		if (std::holds_alternative<double>(token)) 
		{
			_postfix.push_back(token);
		}
		else
		{
			if (isOpenParenthesis(token))
			{
				opStack.push(token);
			}
			else if (isCloseParenthesis(token)) 
			{
				while (!opStack.empty() && std::get<std::string>(opStack.top()) != "(") {
					_postfix.push_back(opStack.top());
					opStack.pop();
				}
				opStack.pop(); // Pop the "("
			}
			else {
				while (!opStack.empty() && hasHigherPrecedence(std::get<std::string>(opStack.top()), token)) {
					_postfix.push_back(opStack.top());
					opStack.pop();
				}
				opStack.push(token);
			}
		}
	}
	
	while (!opStack.empty()) 
	{
		_postfix.push_back(opStack.top());
		opStack.pop();
	}

	return ;

	
}

double RPNExpression::evaluate(const Expression& expression)
{
	std::stack<double> stack;

	for (const auto& token : expression) {
		if (std::holds_alternative<double>(token)) {
			stack.push(std::get<double>(token));
		}
		else {
			double operand2 = stack.top(); stack.pop();
			double operand1 = stack.top(); stack.pop();

			double result = performOperation(operand1, operand2, std::get<std::string>(token));
			stack.push(result);
		}
	}

	return stack.top();
}

bool RPNExpression::isNumber(const std::string& token)
{
	//https://stackoverflow.com/questions/19349112/how-to-check-if-a-string-can-be-converted-to-double-in-c
	std::istringstream iss(token);
	double num;
	iss >> num;
	return iss.eof() && !iss.fail();
	
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

double RPNExpression::performOperation(double operand1, double operand2, const std::string& op)
{
	if (op == "+") return operand1 + operand2;
	else if (op == "-") return operand1 - operand2;
	else if (op == "*") return operand1 * operand2;
	else if (op == "/") 
	{
		if (operand2 == 0) throw std::runtime_error("Division by zero");
		return operand1 / operand2;
	}
	//else if (op == "^") return std::pow(operand1, operand2);
	else throw std::invalid_argument("Invalid operator");
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


