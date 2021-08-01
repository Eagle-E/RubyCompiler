#ifndef AssignmentExpression_H
#define AssignmentExpression_H

#include "Expression.h"
#include "IdentifierExpression.h"
#include <string>
using std::string;

class AssignmentExpression : public Expression
{
public:
	AssignmentExpression();
	AssignmentExpression(IdentifierExpression* id, Expression* exprToAssign);
	~AssignmentExpression();

	Literal* eval(StackAndTable* stackAndTable);

	void print(string& prepend);

private:
	IdentifierExpression* mId;
	Expression* mExprToAssign;
};


#endif // !AssignmentExpression_H
