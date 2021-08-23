#ifndef ASSIGN_H
#define ASSIGN_H



#include "ProgramStack.h"
#include "IdentifierExpression.h"
#include "Literal.h"

class Assign
{
public:
	virtual void assign(ProgramStack& stack, IdentifierExpression& identifier, Literal& value);
private:
};




#endif // !ASSIGN_H