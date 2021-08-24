#ifndef ConditionExpression_h
#define ConditionExpression_h

#include "Expression.h"

/*
* Expression used as condition on statements like: if statement, while loop, ...
*/
class ConditionExpression : public Expression
{
public:
	ConditionExpression();
	ConditionExpression(Expression* condition);
	~ConditionExpression();
	Literal* eval(StackAndTable* stackAndTable);
	bool evalPasses(StackAndTable* stackAndTable);
	void print(string& prepend);
private:
	Expression* mCondition;
};


#endif