#include "CompoundStatement.h"

// TEST
#include <iostream>
using std::cout;	using std::endl;
// END TEST

CompoundStatement::CompoundStatement()
{
}

CompoundStatement::CompoundStatement(const char* s)
{
	ms = s;
}

CompoundStatement::CompoundStatement(vector<Statement*>& expressions)
{
}

CompoundStatement::~CompoundStatement()
{
	deleteExpressions();
}

void CompoundStatement::setSatements(vector<Statement*>& statements)
{
	deleteExpressions();
	mStatements.assign(statements.begin(), statements.end());
}

void CompoundStatement::addStatement(Statement* statement)
{
	mStatements.push_back(statement);
}

void CompoundStatement::execute()
{
	for (Statement* expr : mStatements)
	{
		expr->execute();
	}

	cout << "test compound stm: " << ms << endl;
}

/*
* Deletes Expression* objects from memory if there are any in vecor 
* expressions.
*/
void CompoundStatement::deleteExpressions()
{
	int c = mStatements.size();
	for (int i = 0; i < c; i++) delete mStatements.at(i);
	mStatements.clear();
}
