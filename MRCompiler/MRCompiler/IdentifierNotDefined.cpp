#include "IdentifierNotDefined.h"

IdentifierNotDefined::IdentifierNotDefined()
	: mExceptionReason("") 
{
}

IdentifierNotDefined::IdentifierNotDefined(const string& reason)
	: mExceptionReason(reason)
{
}

const char* IdentifierNotDefined::what() const
{
	return mExceptionReason.c_str();
}
