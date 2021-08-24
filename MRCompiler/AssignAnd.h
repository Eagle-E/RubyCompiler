#ifndef AssignAnd_H
#define AssignAnd_H
#include "AssignOp.h"

class AssignAnd : public AssignOp
{
public:
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};

#endif