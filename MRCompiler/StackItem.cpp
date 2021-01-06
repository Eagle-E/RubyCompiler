#include "StackItem.h"
#include "Literal.h"


StackItem::StackItem()
	: mScope(0), mIdName(""), mType(SymbolType::NONE), mValue(nullptr)
{
}

StackItem::StackItem(const StackItem& other)
{
	this->mScope = other.mScope;
	this->mIdName = other.mIdName;
	this->mType = other.mType;
	this->mValue = other.mValue;
}

StackItem::~StackItem()
{
}

int StackItem::getScope() const
{
	return 0;
}

string StackItem::getName() const
{
	return string();
}

StackItem::SymbolType StackItem::getType() const
{
	return SymbolType();
}

Literal StackItem::getValue() const
{
	if (mValue != nullptr)
		return *mValue;
	else
		return Literal();
}

void StackItem::setScope(int scope)
{
	mScope = scope;
}

void StackItem::setName(string name)
{
	mIdName = name;
}

void StackItem::setType(SymbolType type)
{
	mType = type;
}

void StackItem::setValue(Literal* val)
{
	mValue = val;
}
