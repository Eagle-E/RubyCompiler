#include "UnaryBooleanNegationExpression.h"
#include "BooleanLiteral.h"
#include "InvalidOperandType.h"
#include "InvalidAmountOfOperands.h"
#include "UnaryBooleanNegation.h"
#include <iostream>

UnaryBooleanNegationExpression::UnaryBooleanNegationExpression()
{
}

UnaryBooleanNegationExpression::UnaryBooleanNegationExpression(Expression* operand)
	: UnaryOperationExpression(operand)
{
}

UnaryBooleanNegationExpression::~UnaryBooleanNegationExpression()
{
}


/*
* @returns pointer to evaluated literal (boolean negation of the value of the operand)
* @throws an InvalidOperandType exception if the operand is of wrong type
* @throws an InvalidAmountOfOperands exception if the given amount of operands is wrong
*/
Literal* UnaryBooleanNegationExpression::eval(StackAndTable* stackAndTable)
{
	if (mOperand != nullptr)
	{
		// try executing the operation, if an exception is thrown then there is something
		// wrong with the operand.
		try
		{
			Literal* evalRes = mOperand->eval(stackAndTable);
			UnaryBooleanNegation op;
			Literal* res = op.execute(static_cast<BooleanLiteral*>(evalRes));
			return res;
		}
		catch (InvalidOperandType)
		{
			// TODO, include what type is expected and what type is given
			// TODO, include where the error occured
			throw InvalidOperandType("Wrong operand literal type passed to ! operation, expected bool");
		}
	}
	else
	{
		// TODO, include what the expected amount of operands is and how many are given
		// TODO, include where the error occured
		throw InvalidAmountOfOperands("Wrong amount of operands passed to Unary negation expression");
	}
}

void UnaryBooleanNegationExpression::print(string& prepend)
{
	std::cout << prepend << "[Bool Neg Expr !]:" << std::endl;
	mOperand->print(string(prepend).append("\t"));
}


void UnaryBooleanNegationExpression::test()
{
	std::cout << "heyyyyyyyy" << std::endl;
}

