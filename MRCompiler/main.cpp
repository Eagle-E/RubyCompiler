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

#include "Literal.h"
#include "LiteralExpression.h"
#include "Statement.h"
#include "CompoundStatement.h"
#include "OperationExpression.h"
#include "IntegerLiteral.h"
#include "BooleanLiteral.h"
#include "BinOpExpression.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "Or.h"
#include "And.h"
#include "NotEqual.h"
#include "Equal.h"
#include "LessOrEqual.h"
#include "LessThan.h"
#include "GreaterOrEqual.h"
#include "GreaterThan.h"


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
	IntegerLiteral * intLiteral1 = new IntegerLiteral(17);
	IntegerLiteral * intLiteral2 = new IntegerLiteral(3);
	BooleanLiteral * boolLiteral1 = new BooleanLiteral(false);
	BooleanLiteral * boolLiteral2 = new BooleanLiteral(true);
	
	LiteralExpression * intExpr1 = new LiteralExpression(intLiteral1);
	LiteralExpression * intExpr2 = new LiteralExpression(intLiteral2);
	LiteralExpression * boolExpr = new LiteralExpression(boolLiteral1);
	


	BinOpExpression* addExpr = new BinOpExpression(intExpr1, intExpr2, new Add());
	BinOpExpression* subExpr = new BinOpExpression(intExpr1, intExpr2, new Sub());
	BinOpExpression* mulExpr = new BinOpExpression(intExpr1, intExpr2, new Mul());
	BinOpExpression* divExpr = new BinOpExpression(intExpr1, intExpr2, new Div());

	string s;
	addExpr->print(s);
	subExpr->print(s);
	mulExpr->print(s);
	divExpr->print(s);

	cout << "----------------------------------------" << endl;

	try
	{
		//IntegerLiteral* res1 = static_cast<IntegerLiteral*>(addExpr->eval(nullptr));
		//IntegerLiteral* res2 = static_cast<IntegerLiteral*>(subExpr->eval(nullptr));
		//IntegerLiteral* res3 = static_cast<IntegerLiteral*>(mulExpr->eval(nullptr));
		//IntegerLiteral* res4 = static_cast<IntegerLiteral*>(divExpr->eval(nullptr));

		Add addOp;
		Mul mulOp;
		Div divOp;
		Sub subOp;
		Or orOp;
		And andOp;
		NotEqual neqOp;
		Equal eqOp;
		LessOrEqual leqOp;
		LessThan ltOp;
		GreaterOrEqual geqOp;
		GreaterThan gtOp;
		
		IntegerLiteral* res1 = static_cast<IntegerLiteral*>(addOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res2 = static_cast<IntegerLiteral*>(subOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res3 = static_cast<IntegerLiteral*>(mulOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res4 = static_cast<IntegerLiteral*>(divOp.execute(intLiteral1, intLiteral2));
		BooleanLiteral* res5 = static_cast<BooleanLiteral*>(orOp.execute(boolLiteral1, boolLiteral2));
		BooleanLiteral* res6 = static_cast<BooleanLiteral*>(andOp.execute(boolLiteral1, boolLiteral2));
		BooleanLiteral* res7 = static_cast<BooleanLiteral*>(neqOp.execute(boolLiteral1, boolLiteral2));
		IntegerLiteral* res8 = static_cast<IntegerLiteral*>(neqOp.execute(intLiteral1, intLiteral2));
		BooleanLiteral* res9 = static_cast<BooleanLiteral*>(eqOp.execute(boolLiteral1, boolLiteral2));
		IntegerLiteral* res10 = static_cast<IntegerLiteral*>(eqOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res11 = static_cast<IntegerLiteral*>(leqOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res12 = static_cast<IntegerLiteral*>(ltOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res13 = static_cast<IntegerLiteral*>(geqOp.execute(intLiteral1, intLiteral2));
		IntegerLiteral* res14 = static_cast<IntegerLiteral*>(gtOp.execute(intLiteral1, intLiteral2));

		cout << intLiteral1->val() << " + " << intLiteral2->val() << " = " << res1->val() << endl;
		cout << intLiteral1->val() << " - " << intLiteral2->val() << " = " << res2->val() << endl;
		cout << intLiteral1->val() << " * " << intLiteral2->val() << " = " << res3->val() << endl;
		cout << intLiteral1->val() << " / " << intLiteral2->val() << " = " << res4->val() << endl;
		cout << boolLiteral1->val() << " || " << boolLiteral2->val() << " = " << res5->val() << endl;
		cout << boolLiteral1->val() << " && " << boolLiteral2->val() << " = " << res6->val() << endl;
		cout << boolLiteral1->val() << " != " << boolLiteral2->val() << " = " << res7->val() << endl;
		cout << intLiteral1->val() << " != " << intLiteral2->val() << " = " << res8->val() << endl;
		cout << boolLiteral1->val() << " == " << boolLiteral2->val() << " = " << res9->val() << endl;
		cout << intLiteral1->val() << " == " << intLiteral2->val() << " = " << res10->val() << endl;
		cout << intLiteral1->val() << " <= " << intLiteral2->val() << " = " << res11->val() << endl;
		cout << intLiteral1->val() << " < " << intLiteral2->val() << " = " << res12->val() << endl;
		cout << intLiteral1->val() << " >= " << intLiteral2->val() << " = " << res13->val() << endl;
		cout << intLiteral1->val() << " > " << intLiteral2->val() << " = " << res14->val() << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}


	
	//cout << "ints: " << intLiteral1->val() << " , " << intRes->val() << endl;
	//cout << "bools: " << boolLiteral->val() << " , " << boolRes->val() << endl;
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