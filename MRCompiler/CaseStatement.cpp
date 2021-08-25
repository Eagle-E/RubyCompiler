#include "CaseStatement.h"
#include <iostream>
#include "Literal.h"

CaseStatement::CaseStatement()
{
	mCaseExpression = nullptr;
	mElseBody = nullptr;
}

CaseStatement::~CaseStatement()
{
	if (mCaseExpression != nullptr) delete mCaseExpression;
	if (mElseBody != nullptr) delete mElseBody;
	while (!mWhenCases.empty())
	{
		delete mWhenCases.at(0);
		mWhenCases.pop_front();
	}
}

void CaseStatement::prependCase(Expression* when_case, CompoundStatement* body)
{
	mWhenCases.push_front(new WhenExpr(when_case, body));
}

void CaseStatement::appendCase(Expression* when_case, CompoundStatement* body)
{
	mWhenCases.push_back(new WhenExpr(when_case, body));
}

void CaseStatement::setCaseExpression(Expression* caseExpr)
{
	mCaseExpression = caseExpr;
}

void CaseStatement::setElseBody(CompoundStatement* body)
{
	mElseBody = body;
}

void CaseStatement::execute(StackAndTable* stackAndTable)
{
	// eval case expr
	// eval cases one by one, execute block of matching case, if one executed then quit
	Literal* switchVal = mCaseExpression->eval(stackAndTable);
	for (WhenExpr* whenExpr : mWhenCases)
	{
		Literal* caseVal = whenExpr->whenCase->eval(stackAndTable);
		if (switchVal->equals(caseVal))
		{
			whenExpr->body->execute(stackAndTable);
			return;
		}
	}

	// no cases succeeded, execute else block if there is one
	if (mElseBody != nullptr)
		mElseBody->execute(stackAndTable);
}

void CaseStatement::print(string& prepend)
{
	std::cout << prepend << "[CASE stm]:" << std::endl;
	string newprepend = string(prepend).append("\t");
	string newprepend2 = string(prepend).append("\t\t");
	if (mCaseExpression != nullptr)
	{
		std::cout << newprepend << "<case expr>" << std::endl;
		mCaseExpression->print(newprepend2);
	}
	for (auto e : mWhenCases)
	{
		std::cout << newprepend << "<when>:" << std::endl;
		e->whenCase->print(newprepend2);
		e->body->print(newprepend2);
	}
	if (mElseBody != nullptr)
	{
		std::cout << newprepend << "<case else>" << std::endl;
		mElseBody->print(newprepend2);
	}
}
