#include "Or.h"
#include "Literal.h"
#include "BooleanLiteral.h"
#include "InvalidOperandType.h"

Or::Or()
	:BinOp()
{
}

Or::~Or()
{
}

Literal* Or::execute(Literal* operand1, Literal* operand2)
{
    // check number of operands
    if (operand1->getType() != Literal::Type::BOOL || operand2->getType() != Literal::Type::BOOL)
        throw InvalidOperandType("Invalid operand type for binary operation ||, expected (bool, bool)");

    // TODO check if literals are not NULL, throw exception otherwise

    // return negation
    BooleanLiteral* iop1 = static_cast<BooleanLiteral*>(operand1);
    BooleanLiteral* iop2 = static_cast<BooleanLiteral*>(operand2);
    return new BooleanLiteral(iop1->val() || iop2->val());
}

void Or::print(std::string& prepend)
{
    std::cout << prepend << "[BinOp Or ||]" << std::endl;
}
