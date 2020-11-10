#ifndef OPERATION_H
#define OPERATION_H

#include "Literal.h"

/*
	Abstract class (or interface) for operations 
*/

class Operation
{
	/*
		Executes an operation on the operands of the 
		operator and returns the resulting literal.
	*/
	virtual Literal execute() const = 0;
};


#endif // !OPERATION_H