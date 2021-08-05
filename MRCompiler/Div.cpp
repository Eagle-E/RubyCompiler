#include "Div.h"
#include "Literal.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"

Div::Div()
	:BinOp()
{
}

Div::~Div()
{
}

Literal* Div::execute(Literal* operand1, Literal* operand2)
{
    // check number of operands
    if (operand1->getType() != Literal::Type::INT || operand2->getType() != Literal::Type::INT)
        throw InvalidOperandType("Invalid operand type for / binary operation, expected (int, int)");

    // return negation
    IntegerLiteral* iop1 = static_cast<IntegerLiteral*>(operand1);
    IntegerLiteral* iop2 = static_cast<IntegerLiteral*>(operand2);
    return new IntegerLiteral(iop1->val() / iop2->val());
}

void Div::print(std::string& prepend)
{
    std::cout << prepend << "[BinOp DIV /]" << std::endl;
}
