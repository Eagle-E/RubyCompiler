#ifndef UNARYOPERATION_H
#define UNARYOPERATION_H

class Literal;

/*
	Represents any unary operation (with one operand
*/
class UnaryOperation
{
public:
	UnaryOperation();
	virtual Literal* execute(Literal* operand) = 0;
};


#endif // !UNARYOPERATION_H