#include "Literal.h"
#include <typeinfo>
#include <string.h>
#include <iostream>


/*
* Returns true if both given literal objects are the same (subclass).
*/
bool Literal::sameType(Literal* l1, Literal* l2)
{
	//return strcmp(typeid(l1).name(), typeid(l2).name()) == 0;
	return l1->getType() == l2->getType();
}

Literal::~Literal()
{
}

Literal::Type Literal::getType() const
{
	return Type::NIL;
}

void Literal::print(string prepend)
{
	std::cout << prepend << " [Literal (base)]" << std::endl;
}
