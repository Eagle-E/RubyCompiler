#include "Program.h"

Program::Program()
{
}

Program::~Program()
{
}

CompoundStatement* Program::getRootStatement()
{
	return &mRootStatement;
}

void Program::execute()
{
	// TODO: move function declaration statements to function stack
	// TODO: add all variable names to stack with value NIL (= new Literal())
	mRootStatement.execute(&mStackAndTable);
}
