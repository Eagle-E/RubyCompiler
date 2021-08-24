#include "AssignOp.h"

Literal* AssignOp::assign(Literal* currentVarValue, Literal* valueToAssign)
{
	return valueToAssign->copy();
}
