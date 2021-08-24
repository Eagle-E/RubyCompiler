#ifndef AssignOr_H
#define AssignOr_H
#include "AssignOp.h"

class AssignOr : public AssignOp
{
public:
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};

#endif