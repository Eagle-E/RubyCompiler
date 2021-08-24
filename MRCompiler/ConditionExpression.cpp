#include "ConditionExpression.h"
#include "BooleanLiteral.h"
#include <iostream>

ConditionExpression::ConditionExpression()
	: mCondition(nullptr)
{
}

ConditionExpression::ConditionExpression(Expression* condition)
	: mCondition(condition)
{
}

ConditionExpression::~ConditionExpression()
{
	delete mCondition;
}

Literal* ConditionExpression::eval(StackAndTable* stackAndTable)
{
	if (mCondition == nullptr)
		return new Literal();
	else
		return mCondition->eval(stackAndTable);
}

/*
* Evaluates this expression and returns a bool whether a condition is a success or a failure
*	- ex. if a condition is a success and is used for an if statement, then the if statement
*			block would be executed.
*/
bool ConditionExpression::evalPasses(StackAndTable* stackAndTable)
{
	Literal * conditionResult = eval(stackAndTable);
	if (conditionResult == nullptr)
		return false;
	else if (conditionResult->getType() == Literal::Type::NIL)
		return false;
	else if (conditionResult->getType() == Literal::Type::BOOL)
		return static_cast<BooleanLiteral*>(conditionResult)->val();
	else
		return true; // all other cases such as ints
}

void ConditionExpression::print(string& prepend)
{
	if (mCondition != nullptr)
	{
		std::cout << prepend << "[Condition expr]" << std::endl;
		mCondition->print(prepend.append("\t"));
	}
}
