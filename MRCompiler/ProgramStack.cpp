#include "ProgramStack.h"
#include "IdentifierNotDefined.h"

ProgramStack::ProgramStack()
{
	mItems.push_back(new StackItem());
	mLastReturnedVal = nullptr;
}

ProgramStack::~ProgramStack()
{
	while (!mItems.empty())
	{
		delete mItems.at(mItems.size()-1);
		mItems.pop_back();
	}
}



void ProgramStack::popScope()
{
	// remove top scope, root scope cannot be removed
	if (mItems.size() >= 2)
	{
		delete mItems.at(mItems.size() - 1);
		mItems.pop_back();
	}
}

void ProgramStack::pushScope()
{
	// add new scope to stack
	mItems.push_back(new StackItem());
}

int ProgramStack::getCurrentScopeDepth() const
{
	// scope depth is the rank (index+1) of the scope in the stack
	return mItems.size();
}

/*
* Adds new variable to the stack on the current scope.
*	- if variable already exists, value is updated
*	- otherwise a new element is added.
*/
void ProgramStack::setVariableValue(const string& idName, Literal* value)
{
	// set value of variable
	mItems.at(mItems.size() - 1)->setValue(idName, value);
}

/*
	@returns stack item with given id name
	@throws IdentifierNotDefined if the given name is not found in the stack
*/
Literal& ProgramStack::getVariableValue(const string& idName, LookupType lookupType)
{
	// check if stack is empty
	if (mItems.size() == 0)
		throw IdentifierNotDefined("Identifier \"" + idName + "\" is not defined");

	int scopeIndex = mItems.size() - 1;
	while (scopeIndex >= 0)
	{
		StackItem* scope = mItems.at(scopeIndex);

		try
		{
			return scope->getValue(idName);
		}
		catch (IdentifierNotDefined e)
		{
			// variable not defined in current scope, throw exception again to quit
			if (lookupType == LookupType::LOCAL)
				throw e;
			else if (lookupType == LookupType::GLOBAL)
				scopeIndex--;
		}
	}

	// item not found, we say it is undefined
	throw IdentifierNotDefined("Identifier \"" + idName + "\" is not defined");
}

void ProgramStack::setReturnedValue(Literal* val)
{
	mLastReturnedVal = val;
}

Literal* ProgramStack::getAndRemoveLastReturnedValue()
{
	Literal* temp = mLastReturnedVal;
	mLastReturnedVal = nullptr;
	return temp;
}

StackItem* ProgramStack::getTopScope()
{
	return mItems.at(mItems.size() - 1);
}

