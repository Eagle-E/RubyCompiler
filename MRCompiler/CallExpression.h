#ifndef CallExpression_H
#define CallExpression_H

#include "Expression.h"
#include <deque>


using std::deque;

class ExprList
{
public:
	~ExprList()
	{
		while (!mExpressions.empty())
		{
			delete mExpressions.at(0);
			mExpressions.pop_front();
		}
	}

	void prependExpr(Expression* arg) { mExpressions.push_front(arg); }
	void appendExpr(Expression* arg) { mExpressions.push_back(arg); }
	int numExprs() { return mExpressions.size(); }
	Expression* exprAt(int i) { return mExpressions.at(i); }

private:
	deque<Expression*> mExpressions;
};

class CallExpression: public Expression
{
public:
	CallExpression();
	CallExpression(const string & funcName, ExprList* funcArgs);
	~CallExpression();

	Literal* eval(StackAndTable* stackAndTable);
	void print(string& prepend);

private:
	string mFuncName;
	ExprList* mArgs;
};




#endif // !CallExpression_H