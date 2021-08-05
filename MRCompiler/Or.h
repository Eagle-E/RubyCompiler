#ifndef Or_H
#define Or_H

#include "BinOp.h"

class Or : public BinOp
{
public:
	Or();
	~Or();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif