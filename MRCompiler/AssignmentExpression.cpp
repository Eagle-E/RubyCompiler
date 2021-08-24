#include "AssignmentExpression.h"
#include "BooleanLiteral.h"
#include "IntegerLiteral.h"
#include "StackAndTable.h"
#include <iostream>
#include "IdentifierNotDefined.h"

AssignmentExpression::AssignmentExpression()
	:mId(nullptr), mExprToAssign(nullptr), mAssignOp(new AssignOp())
{
}

AssignmentExpression::AssignmentExpression(IdentifierExpression* id, Expression* exprToAssign, AssignOp* assignOp)
	: mId(id), mExprToAssign(exprToAssign), mAssignOp(assignOp)
{
}

AssignmentExpression::~AssignmentExpression()
{
	if (mExprToAssign != nullptr)
		delete mExprToAssign;
}

/*
* 1. check if variable is registered in stack
* 2. check if there is a valid expression on the right side of the assignment
* 3. evaluate expression on right side
* 4. pass Literal values to the assign operation
* 5. update value of variable in stack to returned value from assign operation
*/
Literal* AssignmentExpression::eval(StackAndTable* stackAndTable)
{
	if (mId != nullptr && mExprToAssign != nullptr && mAssignOp != nullptr)
	{
		Literal* varVal = nullptr;
		Literal* valToAssign = mExprToAssign->eval(stackAndTable);
		
		try {
			varVal = &stackAndTable->stack.getVariableValue(mId->getName());
		}
		catch (IdentifierNotDefined e) {}

		Literal* result = mAssignOp->assign(varVal, valToAssign);
		stackAndTable->stack.setVariableValue(mId->getName(), result);
		return result;
	}
	else
		return nullptr;
}

void AssignmentExpression::print(string& prepend)
{
	std::cout << prepend << "[Assignment expr]:" << std::endl;
	if (mId != nullptr) mId->print(string(prepend).append("\t"));
	if (mExprToAssign != nullptr) mExprToAssign->print(string(prepend).append("\t"));
}
