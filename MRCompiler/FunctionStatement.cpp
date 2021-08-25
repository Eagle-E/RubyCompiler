#include "FunctionStatement.h"
#include <iostream>
#include <exception>
using std::cout;	using std::endl;

FunctionStatement::FunctionStatement()
	: mName(""), mArgs(nullptr), mBody(nullptr)
{
}

FunctionStatement::FunctionStatement(const string& name, ArgList* args, CompoundStatement* body)
	: mName(name), mArgs(args), mBody(body)
{
}

FunctionStatement::~FunctionStatement()
{
	if(mArgs != nullptr) delete mArgs;
	if(mBody != nullptr) delete mBody;
}



void FunctionStatement::execute(StackAndTable* stackAndTable)
{
	// a new scope should have been added and the values of the parameters 
	// should have been set by the CallExpression object,
	// execute body
	if (mBody != nullptr)
	{
		mBody->execute(stackAndTable);
	}
	else
		throw std::exception("function without body");
}

void FunctionStatement::print(string& prepend)
{
	string p2 = prepend + "\t";
	cout << prepend << "[FUNCTION stmt]:" << endl
		<< p2 << "<name>: " << mName << endl
		<< p2 << "<args>: ";

	if (mArgs != nullptr)
	{
		for (int i = 0; i < mArgs->numArgs(); i++)
		{
			if (i < mArgs->numArgs() - 1)
				cout << mArgs->argNameAt(i) << ", ";
			else
				cout << mArgs->argNameAt(i) << endl;
		}
	}

	if (mBody != nullptr)
	{
		mBody->print(p2);
	}
}

const ArgList& FunctionStatement::getArgList()
{
	return *mArgs;
}
