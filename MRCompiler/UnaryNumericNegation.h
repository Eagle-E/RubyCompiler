#ifndef UNARYNUMERICNEGATION_H
#define UNARYNUMERICNEGATION_H

#include "UnaryNumericOperation.h"
#include "Literal.h"

class UnaryNumericNegation : public UnaryNumericOperation
{
public:
	UnaryNumericNegation();
	UnaryNumericNegation(Literal l);

	Literal execute() const
	{
		return Literal(-mLiteral.value());
	}

private:
};


#endif // !UNARYNUMERICNEGATION_H