#include "AssignmentExpression.h"
#include "BooleanLiteral.h"
#include "IntegerLiteral.h"
#include "StackAndTable.h"
#include <iostream>

AssignmentExpression::AssignmentExpression()
	:mId(nullptr), mExprToAssign(nullptr)
{
}

AssignmentExpression::AssignmentExpression(IdentifierExpression* id, Expression* exprToAssign)
	: mId(id), mExprToAssign(exprToAssign)
{
}

AssignmentExpression::~AssignmentExpression()
{
	if (mExprToAssign != nullptr)
		delete mExprToAssign;
}

Literal* AssignmentExpression::eval(StackAndTable* stackAndTable)
{
	if (mExprToAssign != nullptr)
	{
		Literal* result = mExprToAssign->eval(stackAndTable);
		stackAndTable->stack.addNewItem(mId->getName(), result);
		return result;
	}
	return nullptr;
}

void AssignmentExpression::print(string& prepend)
{
	std::cout << prepend << "[Assignment expr]:" << std::endl;
	if (mId != nullptr) mId->print(string(prepend).append("\t"));
	if (mExprToAssign != nullptr) mExprToAssign->print(string(prepend).append("\t"));
}
