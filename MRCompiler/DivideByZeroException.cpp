#include "DivideByZeroException.h"

DivideByZeroException::DivideByZeroException()
	: mExceptionReason("")
{
}

DivideByZeroException::DivideByZeroException(const string& reason)
	: mExceptionReason(reason)
{
}

const char* DivideByZeroException::what() const
{
	return mExceptionReason.c_str();
}
