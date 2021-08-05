#ifndef BinOpExpression_H
#define BinOpExpression_H

#include "Expression.h"

class BinOp;

class BinOpExpression : public Expression
{
public:
	BinOpExpression();
	BinOpExpression(Expression* operand1, Expression* operand2, BinOp* operation);
	~BinOpExpression();

	Literal* eval(StackAndTable* stackAndTable);
	void print(string& prepend);

private:
	Expression* mOperand1;
	Expression* mOperand2;
	BinOp* mOperation;
};

#endif //BinOpExpression_H