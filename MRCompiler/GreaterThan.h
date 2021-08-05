#ifndef GreaterThan_H
#define GreaterThan_H

#include "BinOp.h"

class GreaterThan : public BinOp
{
public:
	GreaterThan();
	~GreaterThan();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif