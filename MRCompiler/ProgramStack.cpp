#include "ProgramStack.h"

ProgramStack::ProgramStack()
	: mCurrentScopeDepth(0)
{
}

ProgramStack::~ProgramStack()
{
	while (!mItems.empty())
		mItems.pop();
}

void ProgramStack::addNewItem(const string& idName, StackItem::SymbolType type, Literal* value)
{
	StackItem newItem;
	newItem.setScope(mCurrentScopeDepth);
	newItem.setName(idName);
	newItem.setType(type);
	newItem.setValue(value);
}

void ProgramStack::popScope()
{
	// remove all stack items of current scope then decrement scope
	while (mItems.top().getScope() == mCurrentScopeDepth)
		mItems.pop();

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
