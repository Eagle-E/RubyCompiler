#include "ArgParser.h"
#include <iostream>
#include "InvalidCommandLineArguments.h"
#include <regex>

/*
	Parses the given arguments and returns a CompilerTask object that
	contains all the relevant information about what needs to be done
	by the compiler.
*/
CompileTask ArgParser::parseArgs(int argc, char* argv[])
{
	CompileTask task;
	
	// if a file name is given and it is valid, then set it as input file
	// otherwise, if the name is invalid throw an exception.
	if (argc == 2)
	{
		string inputFileName(argv[1]);
		if (!validRubyFileName(inputFileName))
			throw InvalidCommandLineArguments("Invalid file name.");
		else
		{
			task.setInputType(InputType::FILE);
			task.setInputFilePath(inputFileName);
		}
	}
	
	// for debugging
	/*std::cout << argc << std::endl;
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}*/

	// return resulting task
	return task;
}

bool ArgParser::validRubyFileName(const string& fname)
{
	return std::regex_match(fname, std::regex(".*\.rb"));
}