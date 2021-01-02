#ifndef COMPOUNDEXPRESSION_H
#define COMPOUNDEXPRESSION_H

#include "Statement.h"
#include <vector>

using std::vector;

class CompoundStatement : public Statement
{
public:
	CompoundStatement();
	CompoundStatement(vector<Statement*> & expressions);
	~CompoundStatement();

	void setSatements(vector<Statement*> & statements);
	void addStatement(Statement* statement);
	void execute();

private:
	void deleteExpressions();

	vector<Statement*> mStatements;

};

#endif // !COMPOUNDEXPRESSION_H
