#ifndef UnaryOperationExpression_H
#define UnaryOperationExpression_H

#include "OperationExpression.h"

class UnaryOperationExpression : public OperationExpression
{
public:
	UnaryOperationExpression();
	UnaryOperationExpression(Expression* operand);
	~UnaryOperationExpression();

	virtual Literal* eval(StackAndTable* stackAndTable) = 0;

	void setOperand(Expression* operand);

	virtual void print(string& prepend);

protected:
	Expression* mOperand;
};


#endif // !UnaryOperationExpression_H