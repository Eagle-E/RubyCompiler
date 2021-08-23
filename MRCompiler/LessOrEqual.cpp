#include "LessOrEqual.h"
#include "Literal.h"
#include "BooleanLiteral.h"
#include "InvalidOperandType.h"

LessOrEqual::LessOrEqual() : BinOp()
{
}

LessOrEqual::~LessOrEqual()
{
}

Literal* LessOrEqual::execute(Literal* operand1, Literal* operand2)
{
    // check number of operands
    if (operand1->getType() != Literal::Type::INT || operand2->getType() != Literal::Type::INT)
        throw InvalidOperandType("Invalid operand type for + binary operation, expected (int, int)");

    // TODO check if literals are not NULL, throw exception otherwise

    // return negation
    BooleanLiteral* iop1 = static_cast<BooleanLiteral*>(operand1);
    BooleanLiteral* iop2 = static_cast<BooleanLiteral*>(operand2);
    return new BooleanLiteral(iop1->val() <= iop2->val());
}

void LessOrEqual::print(std::string& prepend)
{
    std::cout << prepend << "[BinOp Less Or Equal <=]" << std::endl;
}
