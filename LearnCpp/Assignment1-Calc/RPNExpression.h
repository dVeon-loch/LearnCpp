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
	Expression _postfix;
	Expression _expression;

	

	bool isNumber(const std::string& token);

	bool isOperator(const VariantType& token);

	bool hasHigherPrecedence(const VariantType& op1, const VariantType& op2);

	bool isOpenParenthesis(const VariantType& token);

	bool isCloseParenthesis(const VariantType& token);

public:

	void stringToInfix(const std::string& str);

	void infixToPostfix(Expression infix);

	//add a token to the back of the expression
	void Push(const VariantType& token);

	//Get the next tocken from the front of the expression
	void Pop();

	bool Empty();
	
};

