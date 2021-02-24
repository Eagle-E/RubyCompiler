#include "InvalidAmountOfOperands.h"

InvalidAmountOfOperands::InvalidAmountOfOperands()
	: mExceptionReason("")
{
}

InvalidAmountOfOperands::InvalidAmountOfOperands(const string& reason)
	: mExceptionReason(reason)
{
}

const char* InvalidAmountOfOperands::what() const
{
	return mExceptionReason.c_str();
}
