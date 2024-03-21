#pragma once
#include <variant>
#include <vector>
#include <string>
class ShuntingYard
{
	using VariantType = std::variant<double, std::string>;
	using Expression = std::vector<VariantType>;
	
private:
	Expression _expression;

    Expression _expression;

    bool isNumber(const variantType& token) {

    }

    bool isOperator(const variantType& token) {

    }

    bool hasHigherPrecedence(const variantType& op1, const variantType& op2) {

    }

    bool isOpenParenthesis(const variantType& token) {

    }

    bool isCloseParenthesis(const variantType& token) {

    }

public:
	//add a token to the back of the expression
	void Push(const VariantType& token);
	void Pop();
	bool Empty();
};

