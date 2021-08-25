#ifndef UntilStatement_H
#define UntilStatement_H

#include "CompoundStatement.h"
#include "ConditionExpression.h"
#include "Statement.h"

class UntilStatement : public Statement
{
public:
	UntilStatement();
	UntilStatement(ConditionExpression* condition, CompoundStatement* body);
	~UntilStatement();

	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);

private:
	ConditionExpression* mCondition;
	CompoundStatement* mBody;
};

#endif