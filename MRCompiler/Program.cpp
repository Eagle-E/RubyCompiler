#include "Program.h"
#include <iostream>

Program::Program()
	:mRootStatement(new CompoundStatement())
{
}

Program::~Program()
{
}

CompoundStatement* Program::getRootStatement()
{
	return mRootStatement;
}

StackAndTable& Program::getStackAndTable()
{
	return mStackAndTable;
}

void Program::execute()
{
	// TODO: move function declaration statements to function stack
	// TODO: add all variable names to stack with value NIL (= new Literal())
	if (mRootStatement != nullptr)
		mRootStatement->execute(&mStackAndTable);
}

void Program::setRootStatement(CompoundStatement* rootStmt)
{
	mRootStatement = rootStmt;
}

void Program::print()
{
	if (mRootStatement != nullptr)
	{
		string s;
		mRootStatement->print(s);
	}
}
