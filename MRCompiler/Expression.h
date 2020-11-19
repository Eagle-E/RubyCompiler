#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Literal.h"

class Expression
{
public:
	virtual ~Expression() = 0;
	virtual Literal eval() = 0;
};


#endif // !EXPRESSION_H