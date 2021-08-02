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
	void print(string& prepend);

private:
};

	
#endif //UNARYNUMERICNEGATION_H