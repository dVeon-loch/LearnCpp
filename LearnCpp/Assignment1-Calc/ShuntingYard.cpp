#include "RPNExpression.h"
#include <stdexcept>

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


