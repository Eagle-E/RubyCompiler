#include <iostream>
#include <exception>
#include <fstream>
#include <stdio.h>
#include <string> 

#include "lexer.h"
#include "parser.h"
#include "ArgParser.h"
#include "StackAndTable.h"
#include "Program.h"

#include "StackItem.h"
#include "ProgramStack.h"
#include "IdentifierNotDefined.h"
#include "IntegerLiteral.h"
#include "BooleanLiteral.h"

using std::cout;		using std::endl;
using std::cin;			using std::exception;
using std::ofstream;	using std::ifstream;
using std::cerr;		using std::string;

//Array with tokens such that index = tokenid - 250
const char *tokens[] = {
	"SEMICOLON", "UNDEF", "DEF", "LPAREN", "RPAREN", "END", "RETURN",
	"INTEGER", "IDENTIFIER", "IF", "THEN", "ELSIF", "ELSE", "UNLESS",
	"WHILE", "DO", "UNTIL", "CASE", "WHEN", "COMMA", "ASSIGN",
	"PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
	"ANDASSIGN", "ORASSIGN", "PLUS", "MINUS", "MUL", "DIV", "GT",
	"GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT", "BOOLEAN"
}; 

int compile(int argc, char* argv[])
{
	CompileTask compilerTask;

	// parse aguments to get the task to be done
	try
	{
		compilerTask = ArgParser::parseArgs(argc, argv);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	// do task
	if (compilerTask.inputType() == InputType::STDIN)
	{

		// keep reading lines until Ctrl+c
		string line;
		//CompoundStatement program;

		// EXPERIMENTAL
		while (true)
		{
			//std::getline(cin, line);
			//cout << "\t>>> " << line << endl;

			cout << "#" << yyparse() << "#" << endl;
		}

	}
	else if (compilerTask.inputType() == InputType::FILE)
	{
		// TODO: read code from input file and do stuff
		FILE* pCodeFile = fopen(compilerTask.inputFilePath().c_str(), "rb");
		if (!pCodeFile)
		{
			cerr << "Cannot open file \"" << compilerTask.inputFilePath() << "\"" << endl;
			return -1;
		}

		yyin = pCodeFile;

		// parse untill there is nothing leftwd
		do
		{
			yyparse();
			//int code = yylex();
			//cout << "[!] " << code << endl;
		} while (!feof(pCodeFile));

		StackAndTable st;

		try
		{
			cout << "----------------------------------------" << endl;
			string s = "";
			program->getRootStatement()->print(s);
			cout << "----------------------------------------" << endl;
			program->execute();
		}
		// TODO add other exceptions types to catch more specific interpreter errors
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

	}

	delete program;

	return 0;
}

void test()
{
	ProgramStack stack;
	IntegerLiteral* i1 = new IntegerLiteral(2);
	IntegerLiteral* i2 = new IntegerLiteral(-7);
	IntegerLiteral* i3 = new IntegerLiteral(99797);
	BooleanLiteral* b1 = new BooleanLiteral(true);
	BooleanLiteral* b2 = new BooleanLiteral(false);

	try
	{
		stack.setVariableValue("a", i1);
		stack.setVariableValue("b", i2);
		stack.setVariableValue("c", i3);
		stack.setVariableValue("d", b1);
		stack.setVariableValue("e", b2);
		cout << "a: "; stack.getVariableValue("a").print(""); cout << endl;
		cout << "b: "; stack.getVariableValue("b").print(""); cout << endl;
		cout << "c: "; stack.getVariableValue("c").print(""); cout << endl;
		cout << "d: "; stack.getVariableValue("d").print(""); cout << endl;
		cout << "e: "; stack.getVariableValue("e").print(""); cout << endl;
		stack.pushScope();
		stack.setVariableValue("a", new BooleanLiteral(false));
		cout << "a: "; stack.getVariableValue("a").print(""); cout << endl;
		stack.popScope();
		stack.popScope();
		stack.popScope();
		stack.popScope();
		stack.popScope();
		cout << "a: "; stack.getVariableValue("a").print(""); cout << endl;
	}
	catch (IdentifierNotDefined& e)
	{
		cout << e.what() << endl;
	}
}

/*
	The main function

	Command line structure: MRCompiler inputFile.rb
*/
int main(int argc, char* argv[])
{
	//return compile(argc, argv);
	test();
}


/*
	int tokenid;

	// If we de not explicitly bind yyin to a file, stdin is assumed.
	while (tokenid=yylex())
	{
		// Token codes start from 250
		cout << " " << tokens[tokenid - 250];

		// Append value
		if ( (tokenid == IDENTIFIER) || (tokenid == INTEGER) || (tokenid == BOOLEAN) )
			printf("=\"%s\"\n", yytext);
	}
*/