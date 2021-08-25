#ifndef CaseStatement_H
#define CaseStatement_H


#include "Statement.h"
#include "Expression.h"
#include "CompoundStatement.h"
#include <deque>

using std::deque;

struct WhenExpr
{
	WhenExpr(Expression* case_when, CompoundStatement* case_body)
	{
		whenCase = case_when;
		body = case_body;
	}
	Expression* whenCase;
	CompoundStatement* body;
};

class CaseStatement : public Statement
{
public:
	CaseStatement();
	~CaseStatement();
	void prependCase(Expression* when_case, CompoundStatement* body);
	void appendCase(Expression* when_case, CompoundStatement* body);
	void setCaseExpression(Expression* caseExpr);
	void setElseBody(CompoundStatement* body);
	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);

private:
	Expression* mCaseExpression;
	deque<WhenExpr*> mWhenCases;
	CompoundStatement* mElseBody;
};


#endif // !CaseStatement_H