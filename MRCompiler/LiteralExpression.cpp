#include "LiteralExpression.h"
#include <iostream>

LiteralExpression::LiteralExpression()
	: mLiteral(nullptr)
{
}

LiteralExpression::LiteralExpression(Literal * l)
	: mLiteral(l->copy())
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
	std::cout << prepend << "[Lit Expr]: ";
	string s;
	mLiteral->print(s);
	std::cout << std::endl;
	//mLiteral->print(string(prepend).append("\t"));
}
