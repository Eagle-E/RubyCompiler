#include "BooleanLiteral.h"

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
