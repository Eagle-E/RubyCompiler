#include "UntilStatement.h"
#include <exception>
#include <iostream>


UntilStatement::UntilStatement()
	: mCondition(nullptr), mBody(nullptr)
{
}

UntilStatement::UntilStatement(ConditionExpression* condition, CompoundStatement* body)
	: mCondition(condition), mBody(body)
{
}

UntilStatement::~UntilStatement()
{
}

void UntilStatement::execute(StackAndTable* stackAndTable)
{
	if (mCondition == nullptr)
		throw std::exception("Missing condition statement for \"until\" loop.");
	if (mBody == nullptr)
		throw std::exception("Missing body for \"until\" loop.");

	while (!mCondition->evalPasses(stackAndTable))
	{
		mBody->execute(stackAndTable);
	}
}

void UntilStatement::print(string& prepend)
{
	std::cout << prepend << "[UNTIL stm]:" << std::endl;
	string newprepend = prepend + "\t";
	if (mCondition != nullptr) mCondition->print(newprepend);
	if (mBody != nullptr) mBody->print(newprepend);
}
