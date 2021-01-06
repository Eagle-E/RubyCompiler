#ifndef COMPOUNDSTATEMENT_H
#define COMPOUNDSTATEMENT_H

#include "Statement.h"
#include <vector>

using std::vector;

class CompoundStatement : public Statement
{
public:
	// CONSTRUCTORS & DESTRUCTOR
	CompoundStatement();
	CompoundStatement(vector<Statement*> & expressions);
	~CompoundStatement();

	// MANIPULATORS (for list of statements)
	void setSatements(vector<Statement*> & statements);
	void appendStatement(Statement* statement);
	void prependStatement(Statement* statement);
	
	// STATEMENT FUNCS
	void execute(StackAndTable* stackAndTable);

private:
	void deleteExpressions();
	vector<Statement*> mStatements;

};

#endif // !COMPOUNDSTATEMENT_H
