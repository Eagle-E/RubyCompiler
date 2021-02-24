#ifndef INVALIDNUMBEROFOPERANDS_H
#define INVALIDNUMBEROFOPERANDS_H

#include <exception>
#include <string>

using std::exception;	using std::string;

class InvalidNumberOfOperands : public exception
{
public:
	InvalidNumberOfOperands();
	InvalidNumberOfOperands(const string& reason);
	virtual const char* what() const;

private:
	string mExceptionReason;
};

#endif // !INVALIDCOMMANDLINEARGUMENTS_H