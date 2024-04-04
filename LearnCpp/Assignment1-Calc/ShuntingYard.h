#pragma once
#include <variant>
#include <vector>
#include <string>
#include "RPNExpression.h"

//https://daniweb.com/programming/software-development/code/427500/calculator-using-shunting-yard-algorithm

class ShuntingYard
{
	using VariantType = std::variant<double, std::string>;
	using Expression = std::vector<VariantType>;
	
	/* Reset precedence to allow for new scope */
	void handle_left_paren();

	/* Consume operators with precedence >= than op then add op */
	void handle_op(char op);

	/* Convert infix to RPN via shunting-yard algorithm */
	RPNExpression convert(const std::string& infix);

private:
	Expression _expression;

   

public:

};

