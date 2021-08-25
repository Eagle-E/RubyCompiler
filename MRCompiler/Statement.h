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


	// FOR DEBUGGING
	virtual void print(string& prepend);

	// STATIC
	static bool returning();
	static void setReturn();
	static void stopReturn();

private:
	static bool sReturning;

};

#endif // ! STATEMENT_H
