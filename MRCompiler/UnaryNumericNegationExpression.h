#ifndef UnaryNumericNegationExpression_h
#define UnaryNumericNegationExpression_h

#include "UnaryOperationExpression.h"

class UnaryNumericNegationExpression : public UnaryOperationExpression
{
public:
	UnaryNumericNegationExpression();
	UnaryNumericNegationExpression(Expression* operand);
	~UnaryNumericNegationExpression();

	Literal* eval(StackAndTable* stackAndTable);

private:
};

	
#endif //UNARYNUMERICNEGATION_H