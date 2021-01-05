#ifndef COMPOUNDSTATEMENT_H
#define COMPOUNDSTATEMENT_H

#include "Statement.h"
#include <vector>

using std::vector;

class CompoundStatement : public Statement
{
public:
	CompoundStatement();
	CompoundStatement(const char*); // for test
	CompoundStatement(vector<Statement*> & expressions);
	~CompoundStatement();

	void setSatements(vector<Statement*> & statements);
	void addStatement(Statement* statement);
	void execute();

private:
	void deleteExpressions();
	const char* ms;
	vector<Statement*> mStatements;

};

#endif // !COMPOUNDSTATEMENT_H
