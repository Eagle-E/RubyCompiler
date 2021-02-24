#ifndef UNARYBOOLEANNEGATION_H
#define UNARYBOOLEANNEGATION_H

#include "UnaryOperationExpression.h"

class UnaryBooleanNegationExpression : public UnaryOperationExpression
{
public:
	UnaryBooleanNegationExpression();
	UnaryBooleanNegationExpression(Expression* operand);
	~UnaryBooleanNegationExpression();

	Literal* eval(StackAndTable* stackAndTable);

private:
};


#endif //UNARYBOOLEANNEGATION_H