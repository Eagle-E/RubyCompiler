#ifndef DivideByZeroException_H
#define DivideByZeroException_H

#include <exception>
#include <string>

using std::exception;	using std::string;



class DivideByZeroException : public exception
{
public:
	DivideByZeroException();
	DivideByZeroException(const string& reason);
	virtual const char* what() const;

private:
	string mExceptionReason;
};


#endif // !DivideByZeroException_H