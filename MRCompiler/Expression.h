#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Literal.h"
#include <string>
using std::string;

class StackAndTable;

class Expression
{
public:
	virtual ~Expression() = 0;
	virtual Literal* eval(StackAndTable* stackAndTable) = 0;
	virtual void print(string& prepend);
};


#endif // !EXPRESSION_H