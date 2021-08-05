#ifndef GreaterOrEqual_H
#define GreaterOrEqual_H

#include "BinOp.h"

class GreaterOrEqual : public BinOp
{
public:
	GreaterOrEqual();
	~GreaterOrEqual();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif