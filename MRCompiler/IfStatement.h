#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "Statement.h"
#include "Expression.h"
#include "CompoundStatement.h"
#include <deque>
#include "ConditionExpression.h"
#include "ElseIfStatementList.h"

using std::deque;

/*
* Note: every exception is evaluated as true except "false" and "nil"
*/

class IfStatement : public Statement
{
public:
	~IfStatement();

	void setIfStatement(ConditionExpression* condition, CompoundStatement* body);
	void setElseBody(CompoundStatement* body);
	void setElseIfs(ElseIfStatementList* elseIfStatements);

	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);

private:
	deque<ConditionExpression*> mConditions; // conditions for if statements, first one is if the rest else if
	deque<CompoundStatement*> mBodies; // code blocks of if statements
	CompoundStatement* mElseBody;
};


#endif