#include "AssignMinus.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"
#include "IdentifierNotDefined.h"

Literal* AssignMinus::assign(Literal* currentVarValue, Literal* valueToAssign)
{
	if (currentVarValue == nullptr)
		throw IdentifierNotDefined();
	if (valueToAssign == nullptr)
		throw InvalidOperandType();

	// get value of variable, and check if left and right side of += assignment of type int
	if (currentVarValue->getType() != Literal::Type::INT || valueToAssign->getType() != Literal::Type::INT)
		throw InvalidOperandType();

	IntegerLiteral* ival1 = static_cast<IntegerLiteral*>(currentVarValue);
	IntegerLiteral* ival2 = static_cast<IntegerLiteral*>(valueToAssign);
	return new IntegerLiteral(ival1->val() - ival2->val());
}
