#include "Statement.h"
#include <iostream>

Statement::~Statement()
{

}

void Statement::print(string& prepend)
{
	std::cout << "[Stm (base)]";
}
