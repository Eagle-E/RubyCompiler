#include "UnaryNegationExpression.h"
#include "BooleanLiteral.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"
#include "InvalidAmountOfOperands.h"

UnaryNegationExpression::UnaryNegationExpression()
{
}

UnaryNegationExpression::UnaryNegationExpression(Expression* operand)
	: UnaryOperationExpression(operand)
{
}

UnaryNegationExpression::~UnaryNegationExpression()
{
}

/*
* @returns pointer to evaluated literal, evaluates depending on the type of literal (bool or int)
* @throws an InvalidOperandType exception if the operand is not a bool or int
* @throws an InvalidAmountOfOperands exception if the given amount of operands is wrong
*/
Literal* UnaryNegationExpression::eval(StackAndTable* stackAndTable)
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
		else if (evalRes->getType() == Literal::Type::INT)
		{
			// dynamic cast succeeded, result of eval was a boolean literal
			IntegerLiteral* res = static_cast<IntegerLiteral*>(evalRes);
			delete evalRes;
			return res;
		}
		else
		{
			// TODO, include what type is expected and what type is given
			// TODO, include where the error occured
			throw InvalidOperandType("Wrong operand literal type passed to Unary negation operation (expected int or bool)");
		}
	}
	else
	{
		// TODO, include what the expected amount of operands is and how many are given
		// TODO, include where the error occured
		throw InvalidAmountOfOperands("Wrong amount of operands passed to Unary negation expression");
	}
}