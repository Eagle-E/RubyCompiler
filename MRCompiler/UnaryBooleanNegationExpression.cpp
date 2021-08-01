#include "UnaryBooleanNegationExpression.h"
#include "BooleanLiteral.h"
#include "InvalidOperandType.h"
#include "InvalidAmountOfOperands.h"

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
		// check if operand is of BooleanLiteral or IntegerLiteral type
		Literal* evalRes = mOperand->eval(stackAndTable);

		if (evalRes->getType() == Literal::Type::BOOL)
		{
			// dynamic cast succeeded, result of eval was a boolean literal
			BooleanLiteral* res = static_cast<BooleanLiteral*>(evalRes);
			delete evalRes;
			return res;
		}
		else
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
