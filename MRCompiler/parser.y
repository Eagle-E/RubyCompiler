%{
#include "lexer.h"
#include <iostream>

using std::cout;	using std::endl;
using std::cerr;

void yyerror(const char* str);

%}

%union
{
	int integer;
	char* str;
};

// vul aan met tokendeclaraties
%token
	SEMICOLON COMMA LPAREN RPAREN
	INTEGER IDENTIFIER BOOLEAN
	UNDEF DEF END RETURN		
	IF THEN	ELSIF ELSE UNLESS		
	WHILE DO UNTIL CASE	WHEN		
	ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN ANDASSIGN ORASSIGN	
	PLUS MINUS MUL DIV			
	GT GE LT LE EQ NE
	AND OR NOT 
	EOL

%type <integer> INTEGER
%type <integer> BOOLEAN
%type <str> IDENTIFIER

%start program

// vul aan met voorrangdeclaraties







%%








// vul aan met producties
program : compstmt ;

compstmt : stmt zeroOrMore_t_stmt zeroOrOne_t ;

zeroOrMore_t_stmt 
	: 
	| zeroOrMore_t_stmt t stmt 
	;

zeroOrOne_t	
	:
	| t
	;

stmt    : expr
		| IF expr then compstmt zeroOrMore_elseif zeroOrOne_else END {cout << "IF expr" << endl;}
        ;

expr	: IDENTIFIER assignop expr	{cout << "IDENTIFIER assignop expr: " << $<str>1 << endl;}
        | expr binop expr			{cout << "expr binop expr" << endl;}
        | NOT expr					{cout << "NOT expr" << endl;}
        | literal					{cout << "literal: " << $<integer>1 << endl;}
        | IDENTIFIER				{cout << "IDENTIFIER: " << $<str>1 << endl;}
        | MINUS expr				{cout << "MINUS expr" << endl;}
		| IDENTIFIER LPAREN zereOrOne_expressions RPAREN {cout << "function call" << endl;}
		| LPAREN expr RPAREN		{cout << "LPAREN expr RPAREN" << endl;}
        ;

expressions
	: expr
	| expressions COMMA expr
	;

zereOrOne_expressions
	:   
	| expressions
	;

zeroOrMore_elseif
	:
	| zeroOrMore_elseif ELSIF expr then compstmt
	;

zeroOrOne_else
	:
	| ELSE compstmt
	;

literal
	: INTEGER
	| BOOLEAN
	;

assignop
	: ASSIGN		{cout << "assign op: " << " = "   << endl;}
	| PLUSASSIGN 	{cout << "assign op: " << " += "  << endl;}
	| MINUSASSIGN 	{cout << "assign op: " << " -= "  << endl;}
	| MULASSIGN 	{cout << "assign op: " << " *= "  << endl;}
	| DIVASSIGN 	{cout << "assign op: " << " /= "  << endl;}
	| ANDASSIGN 	{cout << "assign op: " << " &&= " << endl;}
	| ORASSIGN 		{cout << "assign op: " << " ||= " << endl;}
	;

binop
	: PLUS	{cout << "binop: " << $<str>1 << endl;}
	| MINUS {cout << "binop: " << "-" << endl;}
	| MUL 	{cout << "binop: " << "*" << endl;}
	| DIV 	{cout << "binop: " << "/" << endl;}
	| GT 	{cout << "binop: " << ">" << endl;}
	| GE 	{cout << "binop: " << ">="<< endl;}
	| LT 	{cout << "binop: " << "<" << endl;}
	| LE 	{cout << "binop: " << "<="<< endl;}
	| EQ 	{cout << "binop: " << "=="<< endl;}
	| NE 	{cout << "binop: " << "!="<< endl;}
	| AND 	{cout << "binop: " << "&&"<< endl;}
	| OR 	{cout << "binop: " << "||"<< endl;}
	;

t : SEMICOLON | EOL ;

then : t | THEN | t THEN ;






%%








void yyerror (const char *s)
{
    cerr << s << endl;
}
