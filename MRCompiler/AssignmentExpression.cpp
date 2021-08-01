#include "AssignmentExpression.h"
#include "BooleanLiteral.h"
#include "IntegerLiteral.h"
#include "StackAndTable.h"

AssignmentExpression::AssignmentExpression()
	:mId(nullptr), mExprToAssign(nullptr)
{
}

AssignmentExpression::AssignmentExpression(IdentifierExpression* id, Expression* exprToAssign)
	: mId(id), mExprToAssign(exprToAssign)
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
			stackAndTable->stack.addNewItem(mId->getName(), StackItem::SymbolType::BooleanLiteral, result);
		}
		else
		{
			IntegerLiteral* il = dynamic_cast<IntegerLiteral*>(result);
			if (il != nullptr)
			{
				stackAndTable->stack.addNewItem(mId->getName(), StackItem::SymbolType::IntegerLiteral, result);
			}
			else
			{
				stackAndTable->stack.addNewItem(mId->getName(), StackItem::SymbolType::OTHER, result);
			}
		}
		return result;
	}
	return nullptr;
}

void AssignmentExpression::print(string& prepend)
{
}
