#ifndef And_H
#define And_H

#include "BinOp.h"

class And : public BinOp
{
public:
	And();
	~And();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif