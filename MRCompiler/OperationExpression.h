#ifndef OperationExpression_H
#define OperationExpression_H

#include "Expression.h"
#include "Operation.h"
#include <vector>

using std::vector;

class OperationExpression : public Expression
{
public:
	OperationExpression();
	~OperationExpression();
	virtual Literal* eval(StackAndTable* stackAndTable) = 0;


	//void setOperation(Operation* op);
	//void setOperands(vector<Expression*>* operands);

private:
	//Operation* mOperation;
	//vector<Expression*>* mOperands;
};


#endif // !OperationExpression_H