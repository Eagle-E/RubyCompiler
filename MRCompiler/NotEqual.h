#ifndef NotEqual_H
#define NotEqual_H

#include "BinOp.h"

class NotEqual : public BinOp
{
public:
	NotEqual();
	~NotEqual();
	Literal* execute(Literal* operand1, Literal* operand2);
	void print(std::string& prepend);
};


#endif