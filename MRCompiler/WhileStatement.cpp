#include "WhileStatement.h"
#include <exception>
#include <iostream>


WhileStatement::WhileStatement()
	: mCondition(nullptr), mBody(nullptr)
{
}

WhileStatement::WhileStatement(ConditionExpression* condition, CompoundStatement* body)
	: mCondition(condition), mBody(body)
{
}

WhileStatement::~WhileStatement()
{
}

void WhileStatement::execute(StackAndTable* stackAndTable)
{
	if (mCondition == nullptr)
		throw std::exception("Missing condition statement for while loop.");
	if (mBody == nullptr)
		throw std::exception("Missing body for while loop.");

	while (mCondition->evalPasses(stackAndTable))
	{
		mBody->execute(stackAndTable);
	}
}

void WhileStatement::print(string& prepend)
{
	std::cout << prepend << "[WHILE stm]:" << std::endl;
	string newprepend = prepend + "\t";
	if (mCondition != nullptr) mCondition->print(newprepend);
	if (mBody != nullptr) mBody->print(newprepend);
}
