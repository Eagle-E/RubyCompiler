#ifndef Equal_H
#define Equal_H

#include "BinOp.h"

class Equal : public BinOp
{
public:
	Equal();
	~Equal();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif