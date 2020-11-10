#ifndef UNARYOPERATION_H
#define UNARYOPERATION_H

#include "Operation.h"
#include "Literal.h"

/*
	Represents any unary operation (with one operand
*/
class UnaryOperation : public Operation
{
public:
	UnaryOperation();
	UnaryOperation(Literal l);

	virtual Literal execute() const = 0;

protected:
	Literal mLiteral;
};


#endif // !UNARYOPERATION_H