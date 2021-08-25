#ifndef WhileStatement_H
#define WhileStatement_H

#include "CompoundStatement.h"
#include "ConditionExpression.h"
#include "Statement.h"

class WhileStatement : public Statement
{
public:
	WhileStatement();
	WhileStatement(ConditionExpression* condition, CompoundStatement* body);
	~WhileStatement();

	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);

private:
	ConditionExpression* mCondition;
	CompoundStatement* mBody;
};

#endif