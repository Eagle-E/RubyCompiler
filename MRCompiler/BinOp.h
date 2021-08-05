#ifndef BINOP_H
#define BINOP_H

#include <string>
#include <iostream>

using std::string;
using std::cout;	using std::endl;

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
	virtual void print(std::string& prepend);
};

#endif
