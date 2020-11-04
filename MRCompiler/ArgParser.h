#ifndef ARGPARSER_H
#define ARGPARSER_H

/*
	This class is responsible for parsing the arguments and returning the correct information
	so the program knows what to do.

	It takes the commandline arguments as parameter and returns a datastructure CompileTask that
	contains all the necessary information about what needs to be done.

	IDEAS (NOT YET IMPLEMENTED)
		- option to specify output file for logging errors
		- option to specify output file for general logging
*/

#include "CompileTask.h"

class ArgParser
{
public:
	static CompileTask parseArgs(int argc, char* argv[]);

private:
	static bool validRubyFileName(const string& fname);

};

#endif