#ifndef IDENTIFIEREXPRESSION_H
#define IDENTIFIEREXPRESSION_H

#include "Expression.h"
#include <string>

using std::string;

class IdentifierExpression : public Expression
{
public:
	IdentifierExpression();
	IdentifierExpression(char* idNameW);
	~IdentifierExpression();
	Literal* eval(StackAndTable* stackAndTable);

	const string & getName() const;
	void setName(const string& idName);

	void print(string& prepend);

private:
	string mName;
};


#endif // !IDENTIFIEREXPRESSION_H
