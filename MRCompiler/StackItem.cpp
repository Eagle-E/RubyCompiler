#include "StackItem.h"
#include "Literal.h"
#include "IdentifierNotDefined.h"


StackItem::StackItem()
{
}


StackItem::~StackItem()
{
	for (auto i = mScope.begin(); i != mScope.end(); i++)
	{
		delete i->second;
	}
	mScope.clear();
}

/*
* - sets corresponding value of given variable
* - if variable does not exist adds new record along with given Literal* value
*/
void StackItem::setValue(const string& idName, Literal* value)
{
	unordered_map<string, Literal*>::iterator i = mScope.find(idName);
	if (i != mScope.end())
	{
		// variable exists
		delete i->second; // delete current literal value
		i->second = value;
	}
	else
	{
		// variable does not exist in current scope yet, add it
		mScope[idName] = value;
	}
}

/*
* Returns value of given variable in current scope. 
* Throws exception if variable does not exist.
*/
Literal& StackItem::getValue(const string& idName)
{
	unordered_map<string, Literal*>::iterator i = mScope.find(idName);
	if (i == mScope.end())
	{
		string msg = "ID \"" + idName + "\" not defined in current scope";
		throw IdentifierNotDefined(msg);
	}
	else
	{
		return *i->second;
	}
}
