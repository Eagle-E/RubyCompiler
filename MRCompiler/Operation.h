#ifndef OPERATION_H
#define OPERATION_H

#include "LiteralExpression.h"
#include <vector>

using std::vector;

class Expression;

/*
	Abstract class (or interface) for operations 
*/

class Operation
{
public:
	/*
		Executes an operation on the given operands and returns the 
		resulting literal.
		@pre elements of operands cannot be nullptr
	*/
	virtual LiteralExpression execute(vector<Expression*>& operands) = 0;
};


#endif // !OPERATION_H