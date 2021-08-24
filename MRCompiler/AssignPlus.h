#ifndef AssignPlus_H
#define AssignPlus_H

#include "AssignOp.h"

class AssignPlus : public AssignOp
{
public:
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};


#endif