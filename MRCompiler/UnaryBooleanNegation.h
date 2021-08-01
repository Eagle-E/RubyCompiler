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

	Literal* execute(Literal* operand);
};


#endif // !UnaryBinaryNegation_h