#include "IdentifierExpression.h"

IdentifierExpression::IdentifierExpression()
{
}

IdentifierExpression::IdentifierExpression(char* idName)
	: mName(idName)
{
}

IdentifierExpression::~IdentifierExpression()
{
}

Literal* IdentifierExpression::eval(StackAndTable* stackAndTable)
{
	//TODO
	return nullptr;
}

const string & IdentifierExpression::getName() const
{
	return mName;
}

void IdentifierExpression::setName(const string& idName)
{
	mName = idName;
}
