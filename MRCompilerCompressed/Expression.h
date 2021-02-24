#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Literal.h"

class StackAndTable;

class Expression
{
public:
	virtual ~Expression() = 0;
	virtual Literal* eval(StackAndTable* stackAndTable) = 0;
};


#endif // !EXPRESSION_H