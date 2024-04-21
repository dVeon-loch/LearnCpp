#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <sstream>

class RPNExpression
{
	//https://daniweb.com/programming/software-development/code/427500/calculator-using-shunting-yard-algorithm

	using VariantType = std::variant<double, std::string>;
	using Expression = std::vector<VariantType>;

private:
	Expression _infix;
	Expression _expression;
	Expression _result;  //calulators can store previous results these days

	

	bool isNumber(const std::string& token);

	bool isOperator(const VariantType& token);

	bool hasHigherPrecedence(const VariantType& op1, const VariantType& op2);

	bool isOpenParenthesis(const VariantType& token);

	bool isCloseParenthesis(const VariantType& token);

	double performOperation(double operand1, double operand2, const std::string& op);

public:
	Expression _postfix;

	void stringToInfix(const std::string& str);

	void infixToPostfix(Expression infix);

	void evaluate(const Expression& expression);

	

	//add a token to the back of the expression
	void Push(const VariantType& token);

	//Get the next tocken from the front of the expression
	void Pop();

	bool Empty();
	
};

