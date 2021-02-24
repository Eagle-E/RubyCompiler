#include "InvalidOperandType.h"

InvalidOperandType::InvalidOperandType()
	: mExceptionReason("")
{
}

InvalidOperandType::InvalidOperandType(const string& reason)
	: mExceptionReason(reason)
{
}

const char* InvalidOperandType::what() const
{
	return mExceptionReason.c_str();
}
