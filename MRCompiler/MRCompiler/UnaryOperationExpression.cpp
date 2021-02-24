#include "UnaryOperationExpression.h"

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
