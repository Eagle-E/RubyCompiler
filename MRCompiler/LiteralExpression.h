#ifndef LITERALEXPRESSION_H
#define LITERALEXPRESSION_H

#include "Expression.h"
#include "Literal.h"

class LiteralExpression : public Expression
{
public:
	LiteralExpression();
	LiteralExpression(Literal * l);
	~LiteralExpression();

	Literal* getLiteral();
	Literal* eval();

private:
	Literal* mLiteral;
};


#endif	