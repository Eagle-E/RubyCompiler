#include "PrintStatement.h"
#include <iostream>

PrintStatement::PrintStatement()
	: FunctionStatement("print", nullptr, new CompoundStatement()), mParamName("txt")
{
	ArgList* args = new ArgList();
	args->appendArg(new IdentifierExpression(mParamName));
	this->setArgList(args);
}

void PrintStatement::print(string& prepend)
{
	std::cout << prepend << "[Print stmt]" << std::endl;
}


void PrintStatement::execute(StackAndTable* stackAndTable)
{
	// check if parameter has value
	Literal& paramLit = stackAndTable->stack.getVariableValue(mParamName);
	std::cout << paramLit.toString() << std::endl;
}