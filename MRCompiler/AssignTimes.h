#ifndef AssignTimes_H
#define AssignTimes_H
#include "AssignOp.h"

class AssignTimes : public AssignOp
{
public:
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};


#endif