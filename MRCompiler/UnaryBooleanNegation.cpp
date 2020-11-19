#include "UnaryBooleanNegation.h"

UnaryBooleanNegation::UnaryBooleanNegation()
	: UnaryOperation()
{
}

UnaryBooleanNegation::~UnaryBooleanNegation()
{
}

LiteralExpression UnaryBooleanNegation::execute(vector<Expression*>& mOperands)
{
	return LiteralExpression();
}