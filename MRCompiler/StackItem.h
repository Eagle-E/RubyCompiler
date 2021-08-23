#ifndef StackItem_H
#define StackItem_H

#include <string>
#include "Literal.h"

using std::string;


/*
* An item for the program stack, contains:
*	- scope depth
*	- identifier name
*	- type of value identifier is referring to
*	- value
*/
class StackItem
{
public:
	StackItem();
	StackItem(const StackItem& other);
	~StackItem();
	
	int getScope() const;
	string getName() const;
	Literal::Type getType() const;
	Literal* getValue() const;

	void setScope(int scope);
	void setName(string name);
	void setValue(Literal* val);

private:
	int mScope;
	string mIdName;
	Literal* mValue;
};


#endif // !StackItem_H
