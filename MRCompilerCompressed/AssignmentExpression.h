#ifndef AssignmentExpression_H
#define AssignmentExpression_H

#include "Expression.h"
#include <string>
using std::string;

class AssignmentExpression : public Expression
{
public:
	AssignmentExpression();
	AssignmentExpression(string idName, Expression* exprToAssign);
	~AssignmentExpression();

	Literal* eval(StackAndTable* stackAndTable);

private:
	string mIdName;
	Expression* mExprToAssign;
};


#endif // !AssignmentExpression_H
