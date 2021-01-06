#ifndef ProgramStack_h
#define ProgramStack_h

#include <vector>
#include "StackItem.h"

using std::vector;

class ProgramStack
{
public:
	enum class LookupType {GLOBAL, LOCAL}; // to search globally or locally
	
	ProgramStack();
	~ProgramStack();

	void addNewItem(const string& idName, StackItem::SymbolType type, Literal* value);
	void popScope(); // deletes all items of the highest scope depth and decrements scope counter
	void pushScope();// increment scope counter
	int getCurrentScopeDepth() const;

	StackItem& lookup(const string& idName, LookupType lookupType = LookupType::GLOBAL);

private:
	int mCurrentScopeDepth;
	vector<StackItem> mItems;
};

#endif ProgramStack_h