#ifndef  STATEMENT_H
#define STATEMENT_H

#include <string>
using std::string;

class StackAndTable;

class Statement
{
public:
	virtual ~Statement() = 0;
	virtual void execute(StackAndTable* stackAndTable) = 0;

private:
};

#endif // ! STATEMENT_H
