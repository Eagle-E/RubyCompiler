#include "CallExpression.h"
#include <iostream>
#include <exception>
#include "FunctionStatement.h"

using std::cout;	using std::endl;

CallExpression::CallExpression()
	: mArgs(nullptr)
{
}

CallExpression::CallExpression(const string& funcName, ExprList* funcArgs)
	: mFuncName(funcName), mArgs(funcArgs)
{
}

CallExpression::~CallExpression()
{
}

Literal* CallExpression::eval(StackAndTable* stackAndTable)
{
	int numArgs = 0;
	if (mArgs != nullptr) numArgs = mArgs->numExprs();

	// first check if function exists
	FunctionStatement* fStmt = stackAndTable->functionTable.getItem(mFuncName, numArgs);
	if (fStmt == nullptr)
	{
		string msg = "Undefined function with name \"" + mFuncName 
			+ "\" and " + std::to_string(numArgs) + " arguments.";
		throw std::exception(msg.c_str());
	}

	// function exists, push new scope to stack, init argument values and start function execution

	if (mArgs != nullptr)
	{
		// fist evaluate arguments, then push scope as the expressions in the arguments depend on 
		// the current scope, the new scope will be initially empty.
		deque<Literal*> argResults;	
		for (int i = 0; i < mArgs->numExprs(); i++)
			argResults.push_back(mArgs->exprAt(i)->eval(stackAndTable));

		stackAndTable->stack.pushScope();

		// now add the parameters of the function as variable to the new scope and set their values in the stack
		const ArgList& params = fStmt->getArgList();
		for (int i = 0; i < params.numArgs(); i++)
		{
			stackAndTable->stack.setVariableValue(params.argNameAt(i), argResults.at(i));
		}

		// execute function
		fStmt->execute(stackAndTable);

		// function terminated, remove its scope
		stackAndTable->stack.popScope();
	}
}

void CallExpression::print(string& prepend)
{
	string p2 = prepend + "\t";
	string p3 = prepend + "\t\t";
	cout << prepend << "[FUNCTION CALL expr]:" << endl
		<< p2 << "<name>: " << mFuncName << endl
		<< p2 << "<args>: " << endl;

	if (mArgs != nullptr)
	{
		for (int i = 0; i < mArgs->numExprs(); i++)
		{
			mArgs->exprAt(i)->print(p3);
		}
	}
}
