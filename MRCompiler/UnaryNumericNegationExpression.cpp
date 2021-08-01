#include "UnaryNumericNegationExpression.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"
#include "InvalidAmountOfOperands.h"
#include "UnaryNumericNegation.h"

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
		// check if operand is of BooleanLiteral or IntegerLiteral type
		Literal* evalRes = mOperand->eval(stackAndTable);

		if (evalRes->getType() == Literal::Type::INT)
		{
			// dynamic cast succeeded, result of eval was a boolean literal
			//IntegerLiteral* res = UnaryNumericNegation; static_cast<IntegerLiteral*>(evalRes)
			
			delete evalRes;
			return res;
		}
		else
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
