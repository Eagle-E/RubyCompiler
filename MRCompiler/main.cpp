#include <iostream>
#include <exception>
#include <fstream>
#include <stdio.h>

#include "lexer.h"
#include "parser.h"
#include "ArgParser.h"
#include "Literal.h"
#include "LiteralExpression.h"
#include "Statement.h"
#include "CompoundStatement.h"
#include "OperationExpression.h"
#include "UnaryOperationExpression.h"
#include "UnaryBooleanNegationExpression.h"
#include "UnaryNumericNegationExpression.h"

#include "IntegerLiteral.h"
#include "BooleanLiteral.h"

using std::cout;		using std::endl;
using std::cin;			using std::exception;
using std::ofstream;	using std::ifstream;
using std::cerr;

//Array with tokens such that index = tokenid - 250
const char *tokens[] = {
	"SEMICOLON", "UNDEF", "DEF", "LPAREN", "RPAREN", "END", "RETURN",
	"INTEGER", "IDENTIFIER", "IF", "THEN", "ELSIF", "ELSE", "UNLESS",
	"WHILE", "DO", "UNTIL", "CASE", "WHEN", "COMMA", "ASSIGN",
	"PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
	"ANDASSIGN", "ORASSIGN", "PLUS", "MINUS", "MUL", "DIV", "GT",
	"GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT", "BOOLEAN"
}; 

/*
	The main function

	Command line structure: MRCompiler inputFile.rb
*/
int main(int argc, char* argv[])
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

			cout << "#" << yyparse()  << "#" << endl;
		}
		
	}
	else if (compilerTask.inputType() == InputType::FILE)
	{
		// TODO: read code from input file and do stuff
		FILE* pCodeFile = fopen(compilerTask.inputFilePath().c_str(), "rb");
		if( !pCodeFile )
		{
			cerr << "Cannot open file \"" << compilerTask.inputFilePath() << "\"" << endl;
			return -1;
		}

		yyin = pCodeFile;

		// parse untill there is nothing leftwd
		do
		{
			yyparse();
			int code = yylex();
			cout << "[!] " << code << endl;
		} while( !feof(pCodeFile) );

		
		rootStatement->execute();

		/*
		try
		{
			CompoundStatement cs;

			UnaryNumericNegation nn;
			LiteralExpression * le = new LiteralExpression(Literal(17));
			vector<Expression*> operands;
			operands.push_back(le);
			nn.execute(operands);
			delete le;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}*/

	}

	
	delete rootStatement;

	//cout << "--------TESTING----------" << endl;
	//IntegerLiteral l1(17);
	//BooleanLiteral l2(true);
	//IntegerLiteral l3(18);
	//IntegerLiteral l4(17);
	//
	//cout << "type of l1 and l2 equeal? " << Literal::sameType(l1, l2) << endl;
	//cout << "type of l1 and l3 equeal? " << Literal::sameType(l1, l3) << endl;
	//cout << false << endl;

	return 0;
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