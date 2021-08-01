#ifndef UnaryBooleanNegation_h
#define UnaryBooleanNegation_h

#include "UnaryOperation.h"

/**
	the '!' sign in code
*/

class UnaryBooleanNegation : public UnaryOperation
{
public:
	UnaryBooleanNegation();
	~UnaryBooleanNegation();

	Literal* execute(Literal* operand);
};


#endif // !UnaryBooleanNegation_h