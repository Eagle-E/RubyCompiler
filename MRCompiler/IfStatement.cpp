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

void IfStatement::setElseBody(CompoundStatement* body)
{
	mElseBody = body;
}

void IfStatement::setElseIfs(ElseIfStatementList* elseIfStatements)
{
	while (! elseIfStatements->empty())
	{
		ElseStm estm = elseIfStatements->popFrontElseIfStm();
		mConditions.push_back(estm.condition);
		mBodies.push_back(estm.body);
	}
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

	// no condition passed, check if there is an "else" statement
	if (mElseBody != nullptr)
		mElseBody->execute(stackAndTable);

	// TODO: throw custom expressions
}

void IfStatement::print(string& prepend)
{
	std::cout << prepend << "[IF stm]:" << std::endl;
	string newprepend = string(prepend).append("\t");
	try
	{
		for (int i = 0; i < mConditions.size(); i++)
		{
			std::cout << prepend << "\t[elsif]: " << std::endl;
			mConditions[i]->print(newprepend);
			mBodies[i]->print(newprepend);
		}
		if (mElseBody != nullptr)
		{
			std::cout << prepend << "\t[else]: " << std::endl;
			mElseBody->print(newprepend);
		}
	}
	catch (std::out_of_range e)
	{
		std::cout << std::endl << "!ERROR WHILE PRINTING: if statement missing condition(s) or bodie(s)."
			<< std::endl;
	}
}
