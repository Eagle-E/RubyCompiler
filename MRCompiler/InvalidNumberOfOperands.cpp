#include "InvalidNumberOfOperands.h"

InvalidNumberOfOperands::InvalidNumberOfOperands()
	: mExceptionReason("")
{

}

InvalidNumberOfOperands::InvalidNumberOfOperands(const string& reason)
	: mExceptionReason(reason)
{

}

const char* InvalidNumberOfOperands::what() const
{
	return mExceptionReason.c_str();
}