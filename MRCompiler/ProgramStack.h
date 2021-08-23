#ifndef ProgramStack_h
#define ProgramStack_h

#include <vector>
#include "Literal.h"
#include "StackItem.h"

using std::vector;

/// <summary>
/// Program stack implemented with a vector. This stack is responsible for keeping track of the
/// scope of the various identifiers.
/// 
/// Internal working:
/// The different scopes are discerned by an integer, going to a higher scope (for ex. function call)
/// is just done by incrementing the scope depth counter. Entries belonging to the same scope are 
/// stored sequentially in the vector. The lowest scope - which is global - starts from the front of
/// the vector (i.e. is at the bottom of the program stack). From there the scope depths only increase, 
/// thus the entries of the local scope (which is the current deepest scope) are always at the back of
/// the vector.
/// </summary>

class ProgramStack
{
public:
	enum class LookupType {GLOBAL, LOCAL}; // to search globally or locally
	
	ProgramStack();
	~ProgramStack();

	void popScope(); // deletes all items of the highest scope depth and decrements scope counter
	void pushScope();// increment scope counter
	int getCurrentScopeDepth() const;

	void setVariableValue(const string& idName, Literal* value);
	Literal& getVariableValue(const string& idName, LookupType lookupType = LookupType::LOCAL);

private:
	StackItem* getTopScope();
	vector<StackItem*> mItems;
};

#endif ProgramStack_h