#ifndef LessOrEqual_H
#define LessOrEqual_H

#include "BinOp.h"

class LessOrEqual : public BinOp
{
public:
	LessOrEqual();
	~LessOrEqual();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif