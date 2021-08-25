#ifndef UnlessStatement_H
#define UnlessStatement_H

#include "Statement.h"
#include "CompoundStatement.h"
#include "ConditionExpression.h"

class UnlessStatement : public Statement
{
public:
	UnlessStatement();
	UnlessStatement(ConditionExpression* condition, CompoundStatement* body);
	~UnlessStatement();

	void setElseBody(CompoundStatement* body);

	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);
private:
	ConditionExpression* mCondition; // conditions for if statements, first one is if the rest else if
	CompoundStatement* mBody; // code blocks of if statements
	CompoundStatement* mElseBody;
};



#endif