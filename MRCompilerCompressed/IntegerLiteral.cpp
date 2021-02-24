#include "IntegerLiteral.h"

IntegerLiteral::IntegerLiteral()
	: mVal(0)
{
}

IntegerLiteral::IntegerLiteral(int val)
	: mVal(val)
{
}

IntegerLiteral::~IntegerLiteral()
{
}

void IntegerLiteral::set(int val)
{
	mVal = val;
}

int IntegerLiteral::val() const
{
	return mVal;
}
