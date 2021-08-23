#include "ProgramStack.h"
#include "IdentifierNotDefined.h"

ProgramStack::ProgramStack()
	: mCurrentScopeDepth(0)
{
}

ProgramStack::~ProgramStack()
{
	while (!mItems.empty())
		mItems.pop_back();
}

void ProgramStack::addNewItem(const string& idName, Literal* value)
{
	StackItem newItem;
	newItem.setScope(mCurrentScopeDepth);
	newItem.setName(idName);
	newItem.setValue(value);
	mItems.push_back(newItem);
}

void ProgramStack::popScope()
{
	// remove all stack items of current scope then decrement scope
	while (mItems.at(mItems.size()-1).getScope() == mCurrentScopeDepth)
		mItems.pop_back();

	mCurrentScopeDepth--;
}

void ProgramStack::pushScope()
{
	// increment scope counter
	mCurrentScopeDepth++;
}

int ProgramStack::getCurrentScopeDepth() const
{
	return mCurrentScopeDepth;
}

/*
	@returns stack item with given id name
	@throws IdentifierNotDefined if the given name is not found in the stack
*/
StackItem& ProgramStack::lookup(const string& idName, LookupType lookupType)
{
	// check if stack is empty
	if (mItems.size() == 0)
		throw IdentifierNotDefined("Identifier \"" + idName + "\" is not defined");

	vector<StackItem>::iterator iter = --mItems.end();
	bool exit = false;

	// iterate from back to front (local scope to parent scopes)
	while (!exit)
	{
		// if we're doing a local lookup break loop if the current item is outside scope
		if (lookupType == LookupType::LOCAL && iter->getScope() < mCurrentScopeDepth)
			break;

		// check if item matches with the needed id
		if (iter->getName().compare(idName) == 0)
		{
			return *iter;
		}

		// if we're at the first item in the stack, means we checked them all, quit
		if (iter == mItems.begin())
			exit = true;
		else
			iter--;
	}

	// item not found, we say it is undefined
	throw IdentifierNotDefined("Identifier \"" + idName + "\" is not defined");
}

