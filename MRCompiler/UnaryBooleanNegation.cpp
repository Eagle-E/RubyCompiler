#include "UnaryBooleanNegation.h"
#include "InvalidOperandType.h"
#include "BooleanLiteral.h"

UnaryBooleanNegation::UnaryBooleanNegation()
	: UnaryOperation()
{
}

UnaryBooleanNegation::~UnaryBooleanNegation()
{
}

/*
*   Returns negated version of given literal
*   @throws InvalidOperandType if given type is not bool
*/
Literal* UnaryBooleanNegation::execute(Literal* operand)
{
    // check number of operands
    if (operand->getType() != Literal::Type::BOOL)
        throw InvalidOperandType("Invalid number of operands for operator");

    // return negation
    BooleanLiteral* boolOperand = static_cast<BooleanLiteral*>(operand);
    return new BooleanLiteral(!boolOperand->val());
}

