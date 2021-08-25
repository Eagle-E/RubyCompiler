#ifndef FunctionStatement_H
#define FunctionStatement_H


#include "Statement.h"
#include "IdentifierExpression.h"
#include "CompoundStatement.h"
#include <deque>
using std::deque;

class ArgList
{
public:
	~ArgList()
	{
		while (!mArgs.empty())
		{
			delete mArgs.at(0);
			mArgs.pop_front();
		}
	}

	void prependArg(IdentifierExpression* arg) { mArgs.push_front(arg); }
	void appendArg(IdentifierExpression* arg) { mArgs.push_back(arg); }
	int numArgs() const { return mArgs.size(); }
	const string& argNameAt(int i) const { return mArgs.at(i)->getName(); }

private:
	deque<IdentifierExpression*> mArgs;
};

class FunctionStatement: public Statement
{
public:
	FunctionStatement();
	FunctionStatement(const string& name, ArgList* args, CompoundStatement* body);
	~FunctionStatement();
	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);
	const ArgList& getArgList();
	void setArgList(ArgList* args);
	string getName();
	int getNumArgs();

protected:
	string mName;
	ArgList* mArgs;
	CompoundStatement* mBody;
};


#endif // !#define FunctionStatement_H