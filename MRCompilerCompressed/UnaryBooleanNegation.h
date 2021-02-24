#ifndef UnaryBinaryNegation_h
#define UnaryBinaryNegation_h

#include "UnaryOperation.h"

/**
	the '!' sign in code
*/

class UnaryBooleanNegation : public UnaryOperation
{
public:
	UnaryBooleanNegation();
	~UnaryBooleanNegation();

	LiteralExpression execute(vector<Expression*>& operands);
};


#endif // !UnaryBinaryNegation_h