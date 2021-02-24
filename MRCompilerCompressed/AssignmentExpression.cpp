#include "AssignmentExpression.h"
#include "BooleanLiteral.h"
#include "IntegerLiteral.h"
#include "StackAndTable.h"

AssignmentExpression::AssignmentExpression()
	:mIdName(""), mExprToAssign(nullptr)
{
}

AssignmentExpression::AssignmentExpression(string idName, Expression* exprToAssign)
	: mIdName(idName), mExprToAssign(exprToAssign)
{
}

AssignmentExpression::~AssignmentExpression()
{
	if (mExprToAssign != nullptr)
		delete mExprToAssign;
}

Literal* AssignmentExpression::eval(StackAndTable* stackAndTable)
{
	if (mExprToAssign != nullptr)
	{
		Literal* result = mExprToAssign->eval(stackAndTable);
		// check what type of literal it is
		BooleanLiteral* bl = dynamic_cast<BooleanLiteral*>(result);
		if (bl != nullptr)
		{
			stackAndTable->stack.addNewItem(mIdName, StackItem::SymbolType::BooleanLiteral, result);
		}
		else
		{
			IntegerLiteral* il = dynamic_cast<IntegerLiteral*>(result);
			if (il != nullptr)
			{
				stackAndTable->stack.addNewItem(mIdName, StackItem::SymbolType::IntegerLiteral, result);
			}
			else
			{
				stackAndTable->stack.addNewItem(mIdName, StackItem::SymbolType::OTHER, result);
			}
		}
		return result;
	}
	return nullptr;
}
