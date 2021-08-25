#include <iostream>
#include "IdentifierExpression.h"
#include "IdentifierNotDefined.h"

IdentifierExpression::IdentifierExpression()
{
}

IdentifierExpression::IdentifierExpression(char* idName)
{
	mName = string(idName);
}

IdentifierExpression::IdentifierExpression(const string& idNameW)
	: mName(idNameW)
{
}

IdentifierExpression::~IdentifierExpression()
{
}

Literal* IdentifierExpression::eval(StackAndTable* stackAndTable)
{
	Literal& result = stackAndTable->stack.getVariableValue(mName);
	//std::cout << "-> [ID expr]: " << mName << " = ";
	//result.print("");
	//std::cout << std::endl;
	return result.copy();
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
	std::cout << prepend << "[ID expr]: " << mName << std::endl;
}
