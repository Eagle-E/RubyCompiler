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
#include "ConditionExpression.h"
#include "IfStatement.h"

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

		try
		{
			string s = "";
			program->getStackAndTable().functionTable.print();
			cout << "----------------------------------------" << endl;
			program->print();
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
	Program program;
	CompoundStatement * rootStm = program.getRootStatement();
	StackAndTable* stack = new StackAndTable();
	IntegerLiteral* i1 = new IntegerLiteral(2);
	IntegerLiteral* i2 = new IntegerLiteral(-7);
	IntegerLiteral* i3 = new IntegerLiteral(99797);
	BooleanLiteral* b1 = new BooleanLiteral(true);
	BooleanLiteral* b2 = new BooleanLiteral(false);

	try
	{
		LiteralExpression* blExpr1 = new LiteralExpression(b1);
		LiteralExpression* blExpr2 = new LiteralExpression(b2);
		ConditionExpression * cexpr1 = new ConditionExpression(blExpr1);
		ConditionExpression * cexpr2 = new ConditionExpression(blExpr2);

		CompoundStatement* ifBody = new CompoundStatement();
		IdentifierExpression * idA1 = new IdentifierExpression();
		IdentifierExpression * idA2 = new IdentifierExpression();
		idA1->setName("a");
		idA2->setName("a");
		
		ifBody->appendStatement(new ExpressionStatement(new AssignmentExpression(
			idA1, new LiteralExpression(i3), new AssignOp()
		)));
		ifBody->appendStatement(new ExpressionStatement(idA2));
		string s("");

		IfStatement* ifStm = new IfStatement();
		ifStm->setIfStatement(cexpr2, ifBody);
		ifStm->print(s);
		ifStm->execute(stack);

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
	return compile(argc, argv);
	//test();
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