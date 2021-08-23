#include "StackItem.h"
#include "Literal.h"


StackItem::StackItem()
	: mScope(0), mIdName(""), mValue(nullptr)
{
}

StackItem::StackItem(const StackItem& other)
{
	this->mScope = other.mScope;
	this->mIdName = other.mIdName;
	this->mValue = other.mValue;
}

StackItem::~StackItem()
{
}

int StackItem::getScope() const
{
	return mScope;
}

string StackItem::getName() const
{
	return mIdName;
}

Literal::Type StackItem::getType() const
{
	if (mValue == nullptr)
		return Literal::Type::NIL;
	else
		return mValue->getType();
}

Literal* StackItem::getValue() const
{
	return mValue;
}

void StackItem::setScope(int scope)
{
	mScope = scope;
}

void StackItem::setName(string name)
{
	mIdName = name;
}


void StackItem::setValue(Literal* val)
{
	mValue = val;
}
