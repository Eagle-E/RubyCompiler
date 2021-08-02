#ifndef UnaryBooleanNegationExpression_h
#define UnaryBooleanNegationExpression_h

#include "UnaryOperationExpression.h"

class UnaryBooleanNegationExpression : public UnaryOperationExpression
{
public:
	UnaryBooleanNegationExpression();
	UnaryBooleanNegationExpression(Expression* operand);
	~UnaryBooleanNegationExpression();

	Literal* eval(StackAndTable* stackAndTable);
	void print(string& prepend);
	void test();
private:
};


#endif //UnaryBooleanNegationExpression_h