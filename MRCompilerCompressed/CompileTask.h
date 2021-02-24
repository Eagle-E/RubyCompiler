#ifndef COMPILETASK_H
#define COMPILETASK_H

#include <string>
using std::string;

enum class InputType {STDIN, FILE};

class CompileTask
{
public:
	// CONSTRUCTORS & DESTRUCTOR
	CompileTask();
	CompileTask(const CompileTask & other);
	~CompileTask();

	// SETTERS & GETTERS
	void setInputType(InputType itype);
	void setInputFilePath(const string & fileName);
	InputType inputType() const;			// getter input type
	const string& inputFilePath() const;	// getter file path

	// MANIPULATORS (changes internal object state)



private:
	InputType mInputType;
	string mInputFileName;
};

#endif