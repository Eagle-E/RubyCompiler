#include "CompileTask.h"

/****** CONSTRUCTOS & DESTRUCTOR **************************************************************/
// Default constructor
CompileTask::CompileTask()
	: mInputType(InputType::STDIN), mInputFileName("")
{
	
}

// Copy constructor
CompileTask::CompileTask(const CompileTask& other)
{
	this->mInputFileName = other.mInputFileName;
	this->mInputType = other.mInputType;
}

// Destructor
CompileTask::~CompileTask()
{

}

/****** SETTERS & GETTERS *********************************************************************/
void CompileTask::setInputType(InputType itype)
{
	mInputType = itype;
}

void CompileTask::setInputFilePath(const string& fileName)
{
	mInputFileName = fileName;
}

InputType CompileTask::inputType() const
{
	return mInputType;
}

const string& CompileTask::inputFilePath() const
{
	return mInputFileName;
}

/****** OTHER FUNCTIONS ***********************************************************************/