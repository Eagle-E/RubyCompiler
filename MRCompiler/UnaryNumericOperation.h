#ifndef UNARYNUMERICOPERATION_H
#define UNARYNUMERICOPERATION_H

#include "UnaryOperation.h"

class UnaryNumericOperation : protected UnaryOperation
{
public:
	UnaryNumericOperation();
	UnaryNumericOperation(Literal l);

	virtual Literal execute() const = 0;

private:
	
};


#endif // !UNARYNUMERICOPERATION_H