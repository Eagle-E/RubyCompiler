#include "IdentifierExpression.h"
#include <iostream>
IdentifierExpression::IdentifierExpression()
{
}

IdentifierExpression::IdentifierExpression(char* idName)
	: mName(idName)
{
	std::cout << "new identifier: " << idName << std::endl;
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

void IdentifierExpression::print(string& prepend)
{
}
