#ifndef AssignmentExpression_H
#define AssignmentExpression_H

#include "Expression.h"
#include "IdentifierExpression.h"
#include <string>
#include "AssignOp.h"
using std::string;

class AssignmentExpression : public Expression
{
public:
	AssignmentExpression();
	AssignmentExpression(IdentifierExpression* id, Expression* exprToAssign, AssignOp* assignOp);
	~AssignmentExpression();

	Literal* eval(StackAndTable* stackAndTable);

	void print(string& prepend);

private:
	IdentifierExpression* mId;
	Expression* mExprToAssign;
	AssignOp* mAssignOp;
};


#endif // !AssignmentExpression_H
