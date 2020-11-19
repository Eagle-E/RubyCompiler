#include "CompoundStatement.h"

CompoundStatement::CompoundStatement()
{
}

CompoundStatement::CompoundStatement(vector<Statement*>& expressions)
{
}

CompoundStatement::~CompoundStatement()
{
	deleteExpressions();
}

void CompoundStatement::setExpressions(vector<Statement*>& expressions)
{
	deleteExpressions();
	mExpressions.assign(expressions.begin(), expressions.end());
}

void CompoundStatement::execute()
{
	for (Statement* expr : mExpressions)
	{
		expr->execute();
	}
}

/*
* Deletes Expression* objects from memory if there are any in vecor 
* expressions.
*/
void CompoundStatement::deleteExpressions()
{
	int c = mExpressions.size();
	for (int i = 0; i < c; i++) delete mExpressions.at(i);
	mExpressions.clear();
}
