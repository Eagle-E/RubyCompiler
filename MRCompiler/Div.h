#ifndef DIV_H
#define DIV_H

#include "BinOp.h"

class Div : public BinOp
{
public:
	Div();
	~Div();
	Literal* execute(Literal* operand1, Literal* operand2);
};

#endif