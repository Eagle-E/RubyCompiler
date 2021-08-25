#include "Literal.h"
#include <typeinfo>
#include <string.h>
#include <iostream>


Literal::~Literal()
{
}

Literal::Type Literal::getType() const
{
	return Type::NIL;
}

Literal* Literal::copy() const
{
	return new Literal();
}

bool Literal::equals(Literal* other) const
{
	return other->getType() == Type::NIL;
}

string Literal::toString() const
{
	return string("nil");
}

void Literal::print(string prepend)
{
	std::cout << prepend << " [Literal (base)]" << std::endl;
}
