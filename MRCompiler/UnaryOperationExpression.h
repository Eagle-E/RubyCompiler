#ifndef UnaryOperationExpression_H
#define UnaryOperationExpression_H

#include "OperationExpression.h"

class UnaryOperationExpression : public OperationExpression
{
public:
	UnaryOperationExpression();
	UnaryOperationExpression(Expression* operand);
	~UnaryOperationExpression();
	virtual Literal* eval() = 0;

	void setOperand(Expression* operand);

protected:
	Expression* mOperand;
};


#endif // !UnaryOperationExpression_H