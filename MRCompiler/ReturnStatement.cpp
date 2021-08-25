#include "ReturnStatement.h"
#include <iostream>
#include "StackAndTable.h"

ReturnStatement::ReturnStatement(Expression* returnExpr)
	:mReturnExpr(returnExpr)
{
}

ReturnStatement::~ReturnStatement()
{
	if (mReturnExpr != nullptr) delete mReturnExpr;
}

void ReturnStatement::execute(StackAndTable* stackAndTable)
{
	if (mReturnExpr == nullptr)
		stackAndTable->stack.setReturnedValue(nullptr);
	else
		stackAndTable->stack.setReturnedValue(mReturnExpr->eval(stackAndTable));
	Statement::setReturn();
}

void ReturnStatement::print(string& prepend)
{
	std::cout << prepend << "[RETURN stmt]: " << std::endl;
	if (mReturnExpr != nullptr) mReturnExpr->print(string(prepend).append("\t"));
}
