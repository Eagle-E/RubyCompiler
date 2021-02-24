#include "FunctionTable.h"

FunctionTable::FunctionTable()
{
}

FunctionTable::~FunctionTable()
{
	mItems.clear();
}

void FunctionTable::addNewItem(const string& funcName, int numArgs, FunctionStatement* funcStatement)
{
	if (!contains(funcName, numArgs))
		mItems.push_back(FunctionTableItem(funcName, numArgs, funcStatement));
	// TODO throw exception if the function is already defined.
}

void FunctionTable::removeItem(const string& funcName, int numArgs)
{
	vector<FunctionTableItem>::const_iterator cIter = mItems.cbegin();
	for (cIter; cIter != mItems.cend(); cIter++)
	{
		if ((cIter->functionName.compare(funcName) == 0) && (cIter->numArgs == numArgs))
		{
			mItems.erase(cIter);
			return;
		}
	}
}

FunctionStatement* FunctionTable::getItem(const string& funcName, int numArgs)
{
	vector<FunctionTableItem>::const_iterator cIter = mItems.cbegin();
	for (cIter; cIter != mItems.cend(); cIter++)
	{
		if ((cIter->functionName.compare(funcName) == 0) && (cIter->numArgs == numArgs))
		{
			return cIter->funcStatement;
		}
	}
	
	return nullptr;
}

bool FunctionTable::contains(const string& funcName, int numArgs)
{
	for (FunctionTableItem item : mItems)
	{
		if (item.functionName.compare(funcName) == 0 && item.numArgs == numArgs)
		{
			return true;
		}
	}

	return false;
}
