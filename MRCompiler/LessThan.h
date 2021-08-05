#ifndef LessThan_H
#define LessThan_H

#include "BinOp.h"

class LessThan : public BinOp
{
public:
	LessThan();
	~LessThan();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif