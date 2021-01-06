#include "UnaryNumericNegation.h"
#include <iostream>
#include "InvalidNumberOfOperands.h"
using std::cout; using std::endl;

UnaryNumericNegation::UnaryNumericNegation()
    : UnaryOperation()
{

}

UnaryNumericNegation::~UnaryNumericNegation()
{
}

/*
*   Negates given number and returns a literalExpression containing the resulting literal
*   @pre operands contains 1 member, the number right of the '-' symbol
*   @throws InvalidNumberOfOperands if other than 1 operands are passed
*/
LiteralExpression UnaryNumericNegation::execute(vector<Expression*>& operands)
{
    // check number of operands
    if (operands.size() != 1)
        throw InvalidNumberOfOperands("Invalid number of operands for operator");

    // there is exaclty one arg, take negation and return
    //Literal operandLiteral = operands.at(0)->eval();
    //LiteralExpression le(Literal(*(-operandLiteral.value())));
    //cout << le.getLiteral().value() << endl;
    return LiteralExpression();
}

