#include "IntegerLiteral.h"
#include <iostream>

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

void IntegerLiteral::print()
{
	std::cout << mVal;
}

Literal::Type IntegerLiteral::getType() const
{
	return Type::INT;
}

Literal* IntegerLiteral::copy() const
{
	return new IntegerLiteral(mVal);
}

void IntegerLiteral::print(string prepend)
{
	//std::cout << prepend << "[Int Literal]: " << std::to_string(mVal) << std::endl;
	std::cout << std::to_string(mVal);
}

bool IntegerLiteral::equals(Literal* other) const
{
	if (other->getType() != Type::INT)
		return false;
	else
	{
		IntegerLiteral* ival = static_cast<IntegerLiteral*>(other);
		return ival->val() == mVal;
	}
}

string IntegerLiteral::toString() const
{
	return std::to_string(mVal);
}
