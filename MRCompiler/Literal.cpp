#include "Literal.h"

Literal::Literal()
	: mVal(0)
{
}

Literal::Literal(int val)
	: mVal(val)
{
}

Literal::Literal(const Literal& val)
{
	mVal = val.mVal;
}

void Literal::set(int val)
{
	mVal = val;
}

int Literal::value() const
{
	return mVal;
}
