#ifndef ElseIfStatementList_H
#define ElseIfStatementList_H

#include <deque>
#include "ConditionExpression.h"
#include "CompoundStatement.h"

using std::deque;

struct ElseStm
{
	ElseStm(ConditionExpression* con, CompoundStatement* b)
	{
		condition = con;
		body = b;
	}
	ConditionExpression* condition;
	CompoundStatement* body;
};

class ElseIfStatementList
{
public:
	void prependElseIfStm(ConditionExpression* condition, CompoundStatement* body);
	void appendElseIfStm(ConditionExpression* condition, CompoundStatement* body);
	ElseStm popFrontElseIfStm();
	bool empty();

private:
	deque<ElseStm> mElseStatements;
};

#endif