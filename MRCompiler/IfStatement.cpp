#include "IfStatement.h"
#include "Literal.h"
#include "BooleanLiteral.h"
#include <stdexcept>
#include <iostream>

IfStatement::~IfStatement()
{
	// delete all objects on heap in both deque's and clear all their elems
	while (!mConditions.empty())
	{
		delete mConditions.at(0);
		mConditions.pop_front();
	}

	while (!mBodies.empty())
	{
		delete mBodies.at(0);
		mBodies.pop_front();
	}
}

void IfStatement::setIfStatement(ConditionExpression* condition, CompoundStatement* body)
{
	mConditions.push_back(condition);
	mBodies.push_back(body);
}

void IfStatement::execute(StackAndTable* stackAndTable)
{
	if (mConditions.empty())
		throw std::exception("Missing condition expression on if statement.");

	// evaluate conditions, if one passes execute body and exit if statement.
	try 
	{
		int i = 0;
		for (ConditionExpression* condition : mConditions)
		{
			if (condition->evalPasses(stackAndTable))
			{
				mBodies[i]->execute(stackAndTable);
				return;
			}
			i++;
		}
	}
	catch (std::out_of_range& e)
	{
		throw std::exception("Missing body for if/else if statement.");
	}


	// TODO: throw custom expressions
}

void IfStatement::print(string& prepend)
{
	std::cout << prepend << "[IF stm]:" << std::endl;
	try
	{
		for (int i = 0; i < mConditions.size(); i++)
		{
			mConditions[i]->print(string(prepend).append("\t"));
			mBodies[i]->print(string(prepend).append("\t"));
		}
	}
	catch (std::out_of_range e)
	{
		std::cout << std::endl << "!ERROR WHILE PRINTING: if statement missing condition(s) or bodie(s)."
			<< std::endl;
	}
}
