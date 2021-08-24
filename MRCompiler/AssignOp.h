#ifndef ASSIGNOP_H
#define ASSIGNOP_H


#include "ProgramStack.h"
#include "Literal.h"
#include "IdentifierExpression.h"

class AssignOp
{
public:
	virtual Literal* assign(Literal* currentVarValue, Literal* valueToAssign);

private:
};


#endif