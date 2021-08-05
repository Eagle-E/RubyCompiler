#ifndef SUB_H
#define SUB_H

#include "BinOp.h"


class Sub : public BinOp
{
public:
	Sub();
	~Sub();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};

#endif