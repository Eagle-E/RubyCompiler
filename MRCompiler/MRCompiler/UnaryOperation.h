#ifndef UNARYOPERATION_H
#define UNARYOPERATION_H

#include "Operation.h"
#include "Expression.h"

/*
	Represents any unary operation (with one operand
*/
class UnaryOperation : public Operation
{
public:
	UnaryOperation();
	virtual LiteralExpression execute(vector<Expression*>& operands) = 0;
};


#endif // !UNARYOPERATION_H