#include "ExpressionStatement.h"
#include "Expression.h"

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

void ExpressionStatement::execute()
{
	if (mExpression != nullptr)
		mExpression->eval();
}
