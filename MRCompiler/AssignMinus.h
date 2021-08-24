#ifndef AssignMinus_H
#define AssignMinus_H

#include "AssignOp.h"

class AssignMinus : public AssignOp
{
public:
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};

#endif