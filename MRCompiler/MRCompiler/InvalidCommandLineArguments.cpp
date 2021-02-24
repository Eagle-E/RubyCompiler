#include "InvalidCommandLineArguments.h"

InvalidCommandLineArguments::InvalidCommandLineArguments()
	: mExceptionReason("")
{

}

InvalidCommandLineArguments::InvalidCommandLineArguments(const string& reason)
	: mExceptionReason(reason)
{

}

const char* InvalidCommandLineArguments::what() const
{
	return mExceptionReason.c_str();
}