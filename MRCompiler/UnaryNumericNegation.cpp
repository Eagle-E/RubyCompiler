#include "UnaryNumericNegation.h"
#include "InvalidOperandType.h"
#include "IntegerLiteral.h"

UnaryNumericNegation::UnaryNumericNegation()
    : UnaryOperation()
{

}

UnaryNumericNegation::~UnaryNumericNegation()
{
}

/*
*   Returns negated version of given literal
*   @throws InvalidOperandType if given type is not int
*/
Literal* UnaryNumericNegation::execute(Literal* operand)
{
    // check number of operands
    if (operand->getType() != Literal::Type::INT)
        throw InvalidOperandType("Invalid operand type for - operation (negation), expected int");

    // return negation
    IntegerLiteral* intOperand = static_cast<IntegerLiteral*>(operand);
    return new IntegerLiteral(intOperand->val()*-1);
}

