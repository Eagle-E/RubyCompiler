#include "Add.h"
#include "Literal.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"

Add::Add()
	: BinOp()
{
}

Add::~Add()
{
}

Literal* Add::execute(Literal* operand1, Literal* operand2)
{
    // check number of operands
    if (operand1->getType() != Literal::Type::INT || operand2->getType() != Literal::Type::INT)
        throw InvalidOperandType("Invalid operand type for + binary operation, expected (int, int)");

    // TODO check if literals are not NULL, throw exception otherwise

    // return negation
    IntegerLiteral* iop1 = static_cast<IntegerLiteral*>(operand1);
    IntegerLiteral* iop2 = static_cast<IntegerLiteral*>(operand2);
    return new IntegerLiteral(iop1->val() + iop2->val());
}

void Add::print(std::string& prepend)
{
    std::cout << prepend << "[BinOp ADD +]" << std::endl;
}
