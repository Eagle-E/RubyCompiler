#ifndef MUL_H
#define MUL_H

#include "BinOp.h"


class Mul : public BinOp
{
public:
	Mul();
	~Mul();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};

#endif