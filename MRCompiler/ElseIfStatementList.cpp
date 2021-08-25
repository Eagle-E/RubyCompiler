#include "ElseIfStatementList.h"

void ElseIfStatementList::prependElseIfStm(ConditionExpression* condition, CompoundStatement* body)
{
	mElseStatements.push_front(ElseStm(condition, body));
}

void ElseIfStatementList::appendElseIfStm(ConditionExpression* condition, CompoundStatement* body)
{
	mElseStatements.push_back(ElseStm(condition, body));
}

ElseStm ElseIfStatementList::popFrontElseIfStm()
{
	ElseStm estm = mElseStatements.front();
	mElseStatements.pop_front();
	return estm;
}

bool ElseIfStatementList::empty()
{
	return mElseStatements.empty();
}
