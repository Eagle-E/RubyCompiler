#ifndef InvalidOperandType_H
#define InvalidOperandType_H

#include <exception>
#include <string>

using std::exception;	using std::string;

/*
* Exception used when an expression is given to an operation expression as operand and
* the operand evaluates to the wrong literal type.
* Used in operation expressions such as UnaryBooleanNegationExpression and the like.
*/
class InvalidOperandType : public exception
{
public:
	InvalidOperandType();
	InvalidOperandType(const string& reason);
	virtual const char* what() const;

private:
	string mExceptionReason;
};

#endif // !InvalidOperandType_H