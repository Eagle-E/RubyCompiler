#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include "Statement.h"

class Expression;

class ExpressionStatement : public Statement
{
public:
	ExpressionStatement();
	ExpressionStatement(Expression* expr);
	~ExpressionStatement();

	void execute(StackAndTable* stackAndTable);
private:
	Expression* mExpression;
};

#endif // !EXPRESSIONSTATEMENT_H
