#include "UnaryNumericNegationExpression.h"
#include "IntegerLiteral.h"
#include "InvalidOperandType.h"
#include "InvalidAmountOfOperands.h"

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
* returns pointer to evaluated literal (numeric negation of the value of the operand)
* @throws an InvalidOperandType exception if the operand is of wrong type
* @throws an InvalidAmountOfOperands exception if the given amount of operands is wrong
*/
Literal* UnaryNumericNegationExpression::eval()
{
	if (mOperand != nullptr)
	{
		// check if operand is of BooleanLiteral type
		IntegerLiteral* evalResInt = dynamic_cast<IntegerLiteral*>(mOperand->eval());
		if (evalResInt != nullptr)
		{
			// dynamic cast succeeded, result of eval was a boolean literal
			int resInt = -evalResInt->val();
			delete evalResInt;
			return new IntegerLiteral(resInt);
		}
		else
		{
			// TODO, include what type is expected and what type is given
			// TODO, include where the error occured
			throw InvalidOperandType("Unary numeric negation expression has an operand that evaluates to a non-boolean literal");
		}
	}
	else
	{
		// TODO, include what the expected amount of operands is and how many are given
		// TODO, include where the error occured
		throw InvalidAmountOfOperands("Unary integer negation expression has the wrong amount of operands");
	}
}
