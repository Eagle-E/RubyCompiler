#ifndef IdentifierNotDefined_H
#define IdentifierNotDefined_H

#include <exception>
#include <string>

using std::exception;	using std::string;

/*
* Exception used when a wrong number of operands are given to an operation expressions
* such as UnaryBooleanNegationExpression and the like.
*/
class IdentifierNotDefined : public exception
{
public:
	IdentifierNotDefined();
	IdentifierNotDefined(const string& reason);
	virtual const char* what() const;

private:
	string mExceptionReason;
};

#endif // !IdentifierNotDefined