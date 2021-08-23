#ifndef StackItem_H
#define StackItem_H

#include <string>
#include <unordered_map>
#include "Literal.h"
using std::string;
using std::unordered_map;

/*
* An item for the program stack that represents a scope
*/
class StackItem
{
public:
	StackItem();
	~StackItem();
	
	void setValue(const string& idName, Literal* value);
	Literal& getValue(const string& idName);

private:

	unordered_map<string, Literal*> mScope;
};


#endif // !StackItem_H
