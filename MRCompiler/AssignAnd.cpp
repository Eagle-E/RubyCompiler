#include "AssignAnd.h"
#include "BooleanLiteral.h"
#include "InvalidOperandType.h"
#include "IdentifierNotDefined.h"

Literal* AssignAnd::assign(Literal* currentVarValue, Literal* valueToAssign)
{
	if (currentVarValue == nullptr)
		throw IdentifierNotDefined();
	if (valueToAssign == nullptr)
		throw InvalidOperandType();

	// get value of variable, and check if left and right side of += assignment of type int
	if (currentVarValue->getType() != Literal::Type::BOOL || valueToAssign->getType() != Literal::Type::BOOL)
		throw InvalidOperandType();

	BooleanLiteral* val1 = static_cast<BooleanLiteral*>(currentVarValue);
	BooleanLiteral* val2 = static_cast<BooleanLiteral*>(valueToAssign);
	return new BooleanLiteral(val1->val() && val2->val());
}
