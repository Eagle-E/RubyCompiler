#ifndef ADD_H
#define ADD_H

#include "BinOp.h"

class Add: public BinOp
{
public:
	Add();
	~Add();
	Literal* execute(Literal* operand1, Literal* operand2);
};


#endif