#include <iostream>
#include <exception>
#include <fstream>
#include <stdio.h>
#include <string> 

#include "lexer.h"
#include "parser.h"
#include "ArgParser.h"
#include "StackAndTable.h"
#include "Literal.h"
#include "LiteralExpression.h"
#include "Statement.h"
#include "CompoundStatement.h"
#include "OperationExpression.h"
#include "UnaryOperationExpression.h"
#include "UnaryNegationExpression.h"
#include "IntegerLiteral.h"
#include "BooleanLiteral.h"
#include "UnaryNumericNegation.h"
#include "UnaryBooleanNegation.h"
#include "UnaryBooleanNegationExpression.h"
#include "UnaryNumericNegationExpression.h"

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
			rootStatement->execute(&st);
			cout << "----------------------------------------" << endl;
			string s = "";
			rootStatement->print(s);
		}
		// TODO add other exceptions types to catch more specific interpreter errors
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

	}

	delete rootStatement;

	return 0;
}

void test()
{
	IntegerLiteral * intLiteral = new IntegerLiteral(17);
	BooleanLiteral * boolLiteral = new BooleanLiteral(false);
	LiteralExpression * intExpr = new LiteralExpression(intLiteral);
	LiteralExpression * boolExpr = new LiteralExpression(boolLiteral);
	
	UnaryNumericNegationExpression intNegExpr(intExpr);
	UnaryBooleanNegationExpression boolNegExpr(boolExpr);
	
	boolNegExpr.test();
	boolNegExpr.eval(nullptr);

	Literal* l1 = intNegExpr.eval(nullptr);
	Literal* l2 = boolNegExpr.eval(nullptr);
	//Literal* l1 = nullptr;
	//Literal* l2 = nullptr;

	IntegerLiteral* intRes = static_cast<IntegerLiteral*> (l1);
	BooleanLiteral* boolRes = static_cast<BooleanLiteral*>(l2);
	
	cout << "ints: " << intLiteral->val() << " , " << intRes->val() << endl;
	cout << "bools: " << boolLiteral->val() << " , " << boolRes->val() << endl;
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