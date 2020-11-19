#ifndef UNARYNUMERICNEGATION_H
#define UNARYNUMERICNEGATION_H

#include "UnaryOperation.h"
#include "Expression.h"

class UnaryNumericNegation : public UnaryOperation
{
public:
	UnaryNumericNegation();
	~UnaryNumericNegation();

	LiteralExpression execute(vector<Expression*>& operands);

private:
};


#endif // !UNARYNUMERICNEGATION_H