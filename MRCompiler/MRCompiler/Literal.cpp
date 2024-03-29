#include "Literal.h"
#include <typeinfo>
#include <string.h>



/*
* Returns true if both given literal objects are the same (subclass).
*/
bool Literal::sameType(Literal& l1, Literal& l2)
{
	return strcmp(typeid(l1).name(), typeid(l2).name()) == 0;
}

Literal::~Literal()
{
}
