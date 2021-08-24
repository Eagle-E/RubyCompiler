#pragma once

#include "AssignOp.h"

class AssignPlus : public AssignOp
{
	Literal* assign(Literal* currentVarValue, Literal* valueToAssign);
};

