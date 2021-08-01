#include "LiteralExpression.h"

LiteralExpression::LiteralExpression()
	: mLiteral(nullptr)
{
}

LiteralExpression::LiteralExpression(Literal * l)
	: mLiteral(l)
{
}

LiteralExpression::~LiteralExpression()
{
	if (mLiteral != nullptr)
		delete mLiteral;
}

Literal* LiteralExpression::getLiteral()
{
	return mLiteral;
}
Literal* LiteralExpression::eval(StackAndTable* stackAndTable)
{
	//return new Literal(*mLiteral);
	return mLiteral;
}

void LiteralExpression::print(string& prepend)
{
}
