#ifndef StackAndTable_H
#define StackAndTable_H

#include "ProgramStack.h"
#include "FunctionTable.h"

// struct containing both the stack used by the interpreter and the functiontable
// that is going to serve kind of like a symbol table
struct StackAndTable
{
	ProgramStack stack;
	FunctionTable functionTable;
};


#endif // !StackAndTable_H
