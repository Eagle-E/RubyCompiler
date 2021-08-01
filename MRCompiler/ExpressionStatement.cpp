#include "ExpressionStatement.h"
#include "Expression.h"
#include "StackAndTable.h"
#include <iostream>

ExpressionStatement::ExpressionStatement()
	: mExpression(nullptr)
{
}

ExpressionStatement::ExpressionStatement(Expression* expr)
	: mExpression(expr)
{
}

ExpressionStatement::~ExpressionStatement()
{
	if (mExpression != nullptr)
		delete mExpression;
}

void ExpressionStatement::execute(StackAndTable* stackAndTable)
{
	if (mExpression != nullptr)
		mExpression->eval(stackAndTable);
}

void ExpressionStatement::print(string& prepend)
{
	std::cout << prepend << "[Expr Stm]:" << std::endl;
	mExpression->print(string(prepend).append("\t"));
	
}
