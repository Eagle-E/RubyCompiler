#include "LiteralExpression.h"

LiteralExpression::LiteralExpression()
	: mLiteral()
{
}

LiteralExpression::LiteralExpression(Literal l)
	: mLiteral(l)
{
}

LiteralExpression::~LiteralExpression()
{
}

Literal LiteralExpression::getLiteral()
{
	return mLiteral;
}

Literal LiteralExpression::eval()
{
	return mLiteral;
}
