#ifndef  STATEMENT_H
#define STATEMENT_H

#include <string>
using std::string;

class Statement
{
public:
	virtual ~Statement() = 0;
	virtual void execute() = 0;

private:
};

#endif // ! STATEMENT_H
