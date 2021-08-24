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
