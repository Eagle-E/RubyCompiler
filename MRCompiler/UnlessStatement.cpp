#include "UnlessStatement.h"
#include <iostream>

UnlessStatement::UnlessStatement()
	: mCondition(nullptr), mBody(nullptr), mElseBody(nullptr)
{
}

UnlessStatement::UnlessStatement(ConditionExpression* condition, CompoundStatement* body)
	: mCondition(condition), mBody(body), mElseBody(nullptr)
{
}

UnlessStatement::~UnlessStatement()
{
	if (mCondition != nullptr) delete mCondition;
	if (mBody != nullptr) delete mBody;
	if (mElseBody != nullptr) delete mElseBody;
}

void UnlessStatement::setElseBody(CompoundStatement* body)
{
	mElseBody = body;
}

void UnlessStatement::execute(StackAndTable* stackAndTable)
{
	if (mCondition == nullptr)
		throw std::exception("Missing condition expression on unless statement.");
	if (mBody == nullptr)
		throw std::exception("Missing bodyon unless statement.");

	if (!mCondition->evalPasses(stackAndTable))
		mBody->execute(stackAndTable);
	else if (mElseBody != nullptr)
		mElseBody->execute(stackAndTable);
}

void UnlessStatement::print(string& prepend)
{
	std::cout << prepend << "[UNLESS stm]:" << std::endl;
	string newprepend = prepend + "\t";
	if (mCondition != nullptr) mCondition->print(newprepend);
	if (mBody != nullptr) mBody->print(newprepend);
	if (mElseBody != nullptr) mElseBody->print(newprepend);
}
