#ifndef AssignDivide_H
#define AssignDivide_H
#include "AssignOp.h"

class AssignDivide : public AssignOp
{
public:
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};

#endif