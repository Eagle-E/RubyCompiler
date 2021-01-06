#ifndef UNARYNUMERICNEGATION_H
#define UNARYNUMERICNEGATION_H

#include "UnaryOperationExpression.h"

class UnaryNumericNegationExpression : public UnaryOperationExpression
{
public:
	UnaryNumericNegationExpression();
	UnaryNumericNegationExpression(Expression* operand);
	~UnaryNumericNegationExpression();

	Literal* eval();

private:
};

	
#endif //UNARYNUMERICNEGATION_H