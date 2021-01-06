#ifndef NumericAssignment_h
#define NumericAssignment_h

#include "AssignmentOperation.h"


class NumericAssignment: public AssignmentOperation
{
	virtual ~NumericAssignment() = 0;
	virtual Literal* assign(const string& idName, Expression* exprToAssign, StackAndTable* stackAndTable) = 0;
};

#endif NumericAssignment_h