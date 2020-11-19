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

	void setExpressions(vector<Statement*> & expressions);
	void execute();

private:
	void deleteExpressions();

	vector<Statement*> mExpressions;

};

#endif // !COMPOUNDEXPRESSION_H
