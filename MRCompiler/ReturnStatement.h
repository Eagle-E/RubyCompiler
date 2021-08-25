#ifndef ReturnStatement_H
#define ReturnStatement_H


#include "Statement.h"
#include "Expression.h"

class ReturnStatement : public Statement
{
public:
	ReturnStatement(Expression* returnExpr);
	~ReturnStatement();
	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);
private:
	Expression* mReturnExpr;
};

#endif