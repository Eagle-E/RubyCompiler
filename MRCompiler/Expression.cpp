#include "Expression.h"
#include <iostream> 

Expression::~Expression()
{

}

void Expression::print(string& prepend)
{
	std::cout << prepend << "[Expr (base)]" << std::endl;
}
