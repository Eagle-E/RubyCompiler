#include "UnaryOperationExpression.h"
#include <iostream>

UnaryOperationExpression::UnaryOperationExpression()
{
}

UnaryOperationExpression::UnaryOperationExpression(Expression* operand)
	:mOperand(operand)
{
}

UnaryOperationExpression::~UnaryOperationExpression()
{
	if (mOperand != nullptr)
		delete mOperand;
}

void UnaryOperationExpression::setOperand(Expression* operand)
{
	mOperand = operand;
}

void UnaryOperationExpression::print(string& prepend)
{
	std::cout << prepend << "[Unary Op Expr (base)]:" << std::endl;
	mOperand->print(string(prepend).append("\t"));
}
