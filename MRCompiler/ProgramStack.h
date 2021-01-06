#ifndef ProgramStack_h
#define ProgramStack_h

#include <stack>
#include "StackItem.h"

using std::stack;

class ProgramStack
{
public:
	ProgramStack();
	~ProgramStack();

	void addNewItem(const string& idName, StackItem::SymbolType type, Literal* value);
	void popScope();
	void pushScope();
	int getCurrentScopeDepth() const;

private:
	int mCurrentScopeDepth;
	stack<StackItem> mItems;
};

#endif ProgramStack_h