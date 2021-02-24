#ifndef AssignmentOperation_h
#define AssignmentOperation_h

#include <string>
using std::string;

class Literal;
class Expression;
class StackAndTable;

class AssignmentOperation
{
	virtual Literal* assign(const string& idName, Expression* exprToAssign, StackAndTable* stackAndTable) = 0;
};


#endif // !AssignmentOperation_h
