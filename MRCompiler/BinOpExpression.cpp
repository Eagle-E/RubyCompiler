#include "BinOpExpression.h"
#include "InvalidAmountOfOperands.h"
#include "InvalidOperandType.h"
#include <iostream>
#include "BinOp.h"

BinOpExpression::BinOpExpression()
    : mOperand1(nullptr), mOperand2(nullptr), mOperation(nullptr)
{
}

BinOpExpression::BinOpExpression(Expression* operand1, Expression* operand2, BinOp* operation)
    : mOperand1(operand1), mOperand2(operand2), mOperation(operation)
{
}

BinOpExpression::~BinOpExpression()
{
    delete mOperand1;
    delete mOperand2;
    delete mOperation;
}

Literal* BinOpExpression::eval(StackAndTable* stackAndTable)
{
    if (mOperand1 == nullptr || mOperand2 == nullptr || mOperation == nullptr)
    {
        throw InvalidAmountOfOperands("Wrong amount of operands passed to Unary negation expression");
    }
    else
    {
        return mOperation->execute(mOperand1->eval(stackAndTable), mOperand2->eval(stackAndTable));
    }
}

void BinOpExpression::print(string& prepend)
{
    std::cout << prepend << "[Binary Op Expr]:" << std::endl;
    string newPrepend = string(prepend).append("\t");
    if (mOperation != nullptr) mOperation->print(newPrepend);
    if (mOperand1 != nullptr) mOperand1->print(newPrepend);
    if (mOperand2 != nullptr) mOperand2->print(newPrepend);
}
