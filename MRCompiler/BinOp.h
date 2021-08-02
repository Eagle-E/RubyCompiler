#ifndef BINOP_H
#define BINOP_H

class Literal;

/*
* Base class for binary operations like add, subtract, 
* mult, divide, greater than, less than, ...
*/
class BinOp
{
public:
	// executes the binary operation, each bin op has a left and right operand
	virtual Literal* execute(Literal* operand1, Literal* operand2) = 0;

};

#endif
