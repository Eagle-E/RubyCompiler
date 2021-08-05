#include "BooleanLiteral.h"
#include <iostream>

BooleanLiteral::BooleanLiteral()
	: mVal(false)
{
}

BooleanLiteral::BooleanLiteral(bool val)
	: mVal(val)
{
}

BooleanLiteral::~BooleanLiteral()
{
}

void BooleanLiteral::set(bool val)
{
	mVal = val;
}

bool BooleanLiteral::val() const
{
	return mVal;
}

void BooleanLiteral::print()
{
	std::cout << mVal;
}

Literal::Type BooleanLiteral::getType() const
{
	return Type::BOOL;
}

void BooleanLiteral::print(string prepend)
{
	//std::cout << prepend << "[Bool Literal]: ";
	string s;
	//mVal ? s = "true" : s = "false";
	//std::cout << s << std::endl;
	mVal ? s = "true" : s = "false";
	std::cout << s;
}
