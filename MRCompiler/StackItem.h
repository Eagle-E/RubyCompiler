#ifndef StackItem_H
#define StackItem_H

#include <string>
using std::string;

class Literal;

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
	enum class SymbolType { IntegerLiteral, BooleanLiteral, NONE };
	StackItem();
	StackItem(const StackItem& other);
	~StackItem();
	
	int getScope() const;
	string getName() const;
	SymbolType getType() const;
	Literal getValue() const;

	void setScope(int scope);
	void setName(string name);
	void setType(SymbolType type);
	void setValue(Literal* val);

private:
	int mScope;
	string mIdName;
	SymbolType mType;
	Literal* mValue;
};


#endif // !StackItem_H
