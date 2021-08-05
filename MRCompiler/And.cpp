#include "And.h"
#include "Literal.h"
#include "BooleanLiteral.h"
#include "InvalidOperandType.h"

And::And() : BinOp()
{
}

And::~And()
{
}

Literal* And::execute(Literal* operand1, Literal* operand2)
{
    // check number of operands
    if (operand1->getType() != Literal::Type::BOOL || operand2->getType() != Literal::Type::BOOL)
        throw InvalidOperandType("Invalid operand type for binary operation &&, expected (bool, bool)");

    // TODO check if literals are not NULL, throw exception otherwise

    // return negation
    BooleanLiteral* iop1 = static_cast<BooleanLiteral*>(operand1);
    BooleanLiteral* iop2 = static_cast<BooleanLiteral*>(operand2);
    return new BooleanLiteral(iop1->val() && iop2->val());
}

void And::print(std::string& prepend)
{
    std::cout << prepend << "[BinOp And &&]" << std::endl;
}
