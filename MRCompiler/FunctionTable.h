#ifndef FunctionTable_h
#define FunctionTable_h

#include <string>
#include <vector>

using std::string;
using std::vector;

class FunctionStatement;

struct FunctionTableItem
{
	FunctionTableItem(const string & name, int numAOfArgs, FunctionStatement* functionStatement)
		: functionName(name), numArgs(numAOfArgs), funcStatement(functionStatement)
	{}

	string functionName;
	int numArgs;
	FunctionStatement* funcStatement;
};

/*
* Hashtable containing the defined functions, functions are unique by their name and # of arguments.
* Kind of like a symbol table, but only for functions
*/
class FunctionTable
{
public:
	FunctionTable();
	~FunctionTable();

	void addNewItem(const string& funcName, int numArgs, FunctionStatement* funcStatement);
	void removeItem(const string& funcName, int numArgs);
	FunctionStatement* getItem(const string& funcName, int numArgs);

private:
	bool contains(const string& funcName, int numArgs);
	vector<FunctionTableItem> mItems;
};

#endif FunctionTable_h