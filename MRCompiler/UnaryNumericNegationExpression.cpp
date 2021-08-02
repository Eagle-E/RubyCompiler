#include "UnaryNumericNegationExpression.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"
#include "InvalidAmountOfOperands.h"
#include "UnaryNumericNegation.h"
#include "UnaryBooleanNegation.h"
#include <iostream>

UnaryNumericNegationExpression::UnaryNumericNegationExpression()
{
}

UnaryNumericNegationExpression::UnaryNumericNegationExpression(Expression* operand)
	: UnaryOperationExpression(operand)
{
}

UnaryNumericNegationExpression::~UnaryNumericNegationExpression()
{
}

/*
* @returns pointer to evaluated literal (numeric negation of the value of the operand)
* @throws an InvalidOperandType exception if the operand is of wrong type
* @throws an InvalidAmountOfOperands exception if the given amount of operands is wrong
*/
Literal* UnaryNumericNegationExpression::eval(StackAndTable* stackAndTable)
{
	if (mOperand != nullptr)
	{
		// try executing the operation, if an exception is thrown then there is something
		// wrong with the operand.
		try
		{
			Literal* evalRes = mOperand->eval(stackAndTable);
			UnaryNumericNegation op;
			Literal* res = op.execute(static_cast<IntegerLiteral*>(evalRes));
			return res;
		}
		catch (InvalidOperandType)
		{
			// TODO, include what type is expected and what type is given
			// TODO, include where the error occured
			throw InvalidOperandType("Wrong operand literal type passed to - (unary) operation, expected int");
		}
	}
	else
	{
		// TODO, include what the expected amount of operands is and how many are given
		// TODO, include where the error occured
		throw InvalidAmountOfOperands("Wrong amount of operands passed to Unary negation expression");
	}
}

void UnaryNumericNegationExpression::print(string& prepend)
{
	std::cout << prepend << "[Num Neg Expr -]:" << std::endl;
	mOperand->print(string(prepend).append("\t"));
}
