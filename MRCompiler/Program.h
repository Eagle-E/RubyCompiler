#ifndef PROGRAM_H
#define PROGRAM_H

#include "CompoundStatement.h"
#include "StackAndTable.h"

class Program
{
public:
	Program();
	~Program();

	CompoundStatement* getRootStatement();
	void execute();
	

private:
	CompoundStatement mRootStatement;
	StackAndTable mStackAndTable;
};



#endif //PROGRAM_H