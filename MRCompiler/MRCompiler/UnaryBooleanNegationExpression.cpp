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
		// check if operand is of BooleanLiteral type
		BooleanLiteral* evalResBoolean = dynamic_cast<BooleanLiteral*>(mOperand->eval(stackAndTable));
		if (evalResBoolean != nullptr)
		{
			// dynamic cast succeeded, result of eval was a boolean literal
			bool resBool = !evalResBoolean->val();
			delete evalResBoolean;
			return new BooleanLiteral(resBool);
		}
		else
		{
			// TODO, include what type is expected and what type is given
			// TODO, include where the error occured
			throw InvalidOperandType("Unary boolean negation expression has an operand that evaluates to a non-boolean literal");
		}
	}
	else
	{
		// TODO, include what the expected amount of operands is and how many are given
		// TODO, include where the error occured
		throw InvalidAmountOfOperands("Unary boolean negation expression has the wrong amount of operands");
	}
}
