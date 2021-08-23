#include "Equal.h"
#include "Literal.h"
#include "BooleanLiteral.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"

Equal::Equal() : BinOp()
{
}

Equal::~Equal()
{
}

Literal* Equal::execute(Literal* operand1, Literal* operand2)
{
    // TODO check if literals are not NULL, throw exception otherwise
// check number of operands
    if (operand1->getType() == Literal::Type::BOOL && operand2->getType() == Literal::Type::BOOL)
    {
        // return negation
        BooleanLiteral* iop1 = static_cast<BooleanLiteral*>(operand1);
        BooleanLiteral* iop2 = static_cast<BooleanLiteral*>(operand2);
        return new BooleanLiteral(iop1->val() == iop2->val());
    }
    else if (operand1->getType() == Literal::Type::INT && operand2->getType() == Literal::Type::INT)
    {
        BooleanLiteral* iop1 = static_cast<BooleanLiteral*>(operand1);
        BooleanLiteral* iop2 = static_cast<BooleanLiteral*>(operand2);
        return new BooleanLiteral(iop1->val() == iop2->val());
    }
    else
        throw InvalidOperandType("Invalid operand type for binary operation ==, expected (bool, bool) or (int, int)");
}

void Equal::print(std::string& prepend)
{
    std::cout << prepend << "[BinOp Equal ==]" << std::endl;
}
