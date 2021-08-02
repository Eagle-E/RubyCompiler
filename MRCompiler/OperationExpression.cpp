#include "OperationExpression.h"
#include <iostream>

OperationExpression::OperationExpression()
	//: mOperation(nullptr), mOperands(nullptr)
{
}

OperationExpression::~OperationExpression()
{
	/*
	if (mOperands != nullptr)
	{
		int c = mOperands->size();
		for (int i = 0; i < c; i++) delete mOperands->at(i);
		mOperands->clear();
		delete mOperands;
	}
	if (mOperation != nullptr)
		delete mOperation;
		*/
}

void OperationExpression::print(string& prepend)
{
	std::cout << prepend << "[Oper Expr]" << std::endl;
}

/*
void OperationExpression::setOperation(Operation* op)
{
	mOperation = op;
}

void OperationExpression::setOperands(vector<Expression*>* operands)
{
	mOperands = operands;
}

Literal OperationExpression::eval()
{
	if (mOperation == nullptr)
		return Literal();
	else
	{
		return *mOperation->execute(*mOperands).getLiteral();
	}
}
*/