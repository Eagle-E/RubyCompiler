#include "Statement.h"
#include <iostream>

bool Statement::sReturning = false;

Statement::~Statement()
{

}

void Statement::print(string& prepend)
{
	std::cout << "[Stm (base)]";
}

bool Statement::returning()
{
	return sReturning;
}

void Statement::setReturn()
{
	sReturning = true;
}

void Statement::stopReturn()
{
	sReturning = false;
}
