#include "CompoundStatement.h"

// TEST
#include <iostream>
using std::cout;	using std::endl;
// END TEST

/*
*******************************************************************************
**************************** CONSTRUCTORS & DESTRUCTOR ************************
*******************************************************************************
*/
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

/*
*******************************************************************************
******************* MANIPULATORS (for list of statements) *********************
*******************************************************************************
*/
void CompoundStatement::setSatements(vector<Statement*>& statements)
{
	deleteExpressions();
	mStatements.assign(statements.begin(), statements.end());
}

void CompoundStatement::appendStatement(Statement* statement)
{
	mStatements.push_back(statement);
}

void CompoundStatement::prependStatement(Statement* statement)
{
	mStatements.insert(mStatements.begin(), statement);
}

/*
*******************************************************************************
*******************          STATEMENT FUNCTIONS          *********************
*******************************************************************************
*/

void CompoundStatement::execute()
{
	for (Statement* expr : mStatements)
	{
		expr->execute();
	}
}

/*
*******************************************************************************
*******************           PRIVATE FUNCTIONS           *********************
*******************************************************************************
*/

/*
* Deletes Expression* objects from memory if there are any in list of expressions.
* Deletes all list elements, making list empty.
*/
void CompoundStatement::deleteExpressions()
{
	int c = mStatements.size();
	for (int i = 0; i < c; i++) delete mStatements.at(i);
	mStatements.clear();
}
