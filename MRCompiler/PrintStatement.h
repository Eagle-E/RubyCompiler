#ifndef PrintStatement_H
#define PrintStatement_H


#include "FunctionStatement.h"

class PrintStatement: public FunctionStatement
{
public:
	PrintStatement();
	void execute(StackAndTable* stackAndTable);
	void print(string& prepend);
private:
	string mParamName;
};


#endif // !#define PrintStatement_H