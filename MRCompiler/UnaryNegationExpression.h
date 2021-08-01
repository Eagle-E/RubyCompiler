#ifndef UNARYNEGATIONEXPRESSION_H
#define UNARYNEGATIONEXPRESSION_H

#include "UnaryOperationExpression.h"
#include "StackAndTable.h"

class UnaryNegationExpression: public UnaryOperationExpression
{
public:
	UnaryNegationExpression();
	UnaryNegationExpression(Expression* operand);
	~UnaryNegationExpression();

	Literal* eval(StackAndTable* stackAndTable);

private:
};

#endif //UNARYNEGATIONEXPRESSION_H