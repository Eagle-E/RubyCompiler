#ifndef INVALIDCOMMANDLINEARGUMENTS_H
#define INVALIDCOMMANDLINEARGUMENTS_H

#include <exception>
#include <string>

using std::exception;	using std::string;

class InvalidCommandLineArguments : public exception
{
public:
	InvalidCommandLineArguments();
	InvalidCommandLineArguments(const string & reason);
	virtual const char* what() const;

private:
	string mExceptionReason;
};

#endif // !INVALIDCOMMANDLINEARGUMENTS_H