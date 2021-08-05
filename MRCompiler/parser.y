%code requires {
#include "lexer.h"
#include <iostream>
#include "Expression.h"
#include "LiteralExpression.h"
#include "Statement.h"
#include "ExpressionStatement.h"
#include "CompoundStatement.h"
#include "Literal.h"
#include "IntegerLiteral.h"
#include "BooleanLiteral.h"
#include "UnaryBooleanNegationExpression.h"
#include "UnaryNumericNegationExpression.h"
#include "IdentifierExpression.h"
#include "AssignmentExpression.h"
#include "BinOpExpression.h"
#include "BinOp.h"
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

// BEGIN TEST
#include <typeinfo>
// END TEST

using std::cout;	using std::endl;
using std::cerr;

void yyerror(const char* str);

// the abstract syntax tree
extern CompoundStatement* rootStatement;
}

%code{
CompoundStatement* rootStatement = new CompoundStatement();
}

%union
{
	int t_int;
	char* t_str;
	Expression* t_expression;
	Statement* t_statement;
	Literal* t_literal;
	BinOp * t_binop;
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

 // terminal types
%type <t_int> INTEGER
%type <t_int> BOOLEAN
%type <t_str> IDENTIFIER

 // non-terminal types
%nterm <t_literal> literal
%nterm <t_expression> expr
%nterm <t_statement> stmt
%nterm <t_binop> binop

%start program




%%








// vul aan met producties
program : compstmt ;

compstmt : stmt zeroOrMore_t_stmt zeroOrOne_t 
								{
									rootStatement->prependStatement($stmt);
									
								}
		 ;

zeroOrMore_t_stmt 
	: /* empty */ {}
	| zeroOrMore_t_stmt t stmt	{
									rootStatement->appendStatement($stmt); 
									//cout << "[LIST compstmt]" << endl;
								}
	;

zeroOrOne_t	
	:
	| t
	;

stmt    : UNDEF IDENTIFIER	{cout << "undef" << endl;}
		| DEF IDENTIFIER LPAREN zereOrOne_arglist RPAREN compstmt END {cout << "function def" << endl;}
		| RETURN expr		{cout << "return" << endl;}
		| IF expr then compstmt zeroOrMore_elseif zeroOrOne_else END {cout << "IF" << endl;}
		| UNLESS expr then compstmt zeroOrOne_else END {cout << "unless" << endl;}
		| WHILE expr do compstmt END {cout << "while" << endl;}
		| UNTIL expr do compstmt END {cout << "until" << endl;}
		| CASE expr WHEN expr then compstmt zeroOrMore_when zeroOrOne_else END {cout << "case" << endl;}
		| expr		{$$ = new ExpressionStatement($expr);}		
        ;

expr	: expr binop expr			{
										$$ = new BinOpExpression($1, $3, $2);
										cout << "\n[expr binop expr]" << endl;
									}
        | NOT expr					{
										$$ = new UnaryBooleanNegationExpression($2); 
										cout << "[NOT expr] " << endl;
									}
        | literal					{
										$$ = new LiteralExpression($literal);
										cout << "\n[expr] literal: ";
										$literal->print("");
										//cout << endl;
									}
        | IDENTIFIER				{
										cout << "whatever" << endl;
										cout << "IDENTIFIER: " << $<t_str>1 << endl;
										$$ = new IdentifierExpression($1);	
									}
		| IDENTIFIER assignop expr	{
										IdentifierExpression* idExpr = new IdentifierExpression($IDENTIFIER);
										$$ = new AssignmentExpression(idExpr, $3);
										cout << "[IDENTIFIER assignop expr]: " << idExpr->getName() << "=" << "<expr>" << endl;
									}
        | MINUS expr				{
										$$ = new UnaryNumericNegationExpression($2); 
										cout << "[MINUS expr] " << endl;
									}
		| IDENTIFIER LPAREN zereOrOne_expressions RPAREN 
									{
										/*cout << "function call" << endl;*/
									}
		| LPAREN expr RPAREN		{
										$$ = $2;
										/*cout << "LPAREN expr RPAREN" << endl;*/
									}
        ;

expressions
	: expr
	| expressions COMMA expr
	;

arglist 
	: IDENTIFIER
	| arglist COMMA IDENTIFIER
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

zeroOrMore_when 
	: 
	| zeroOrMore_when WHEN expr then compstmt
	;

zereOrOne_arglist   
	:   
	| arglist
	;

literal
	: INTEGER { $$ = new IntegerLiteral($INTEGER); /*cout << "literal int:" << $INTEGER << endl; */ }
	| BOOLEAN { $$ = new BooleanLiteral($BOOLEAN); /*cout << "literal bool:" << $BOOLEAN << endl;*/ }
	;

assignop
	: ASSIGN		{/*cout << "assign op: " << " = "   << endl;*/}
	| PLUSASSIGN 	{/*cout << "assign op: " << " += "  << endl;*/}
	| MINUSASSIGN 	{/*cout << "assign op: " << " -= "  << endl;*/}
	| MULASSIGN 	{/*cout << "assign op: " << " *= "  << endl;*/}
	| DIVASSIGN 	{/*cout << "assign op: " << " /= "  << endl;*/}
	| ANDASSIGN 	{/*cout << "assign op: " << " &&= " << endl;*/}
	| ORASSIGN 		{/*cout << "assign op: " << " ||= " << endl;*/}
	;

binop
	: PLUS	{ $$ = new Add(); /*cout << "binop: " << $<str>1 << endl;*/}
	| MINUS { $$ = new Sub(); /*cout << "binop: " << "-" << endl;*/}
	| MUL 	{ $$ = new Mul(); /*cout << "binop: " << "*" << endl;*/}
	| DIV 	{ $$ = new Div(); /*cout << "binop: " << "/" << endl;*/}
	| GT 	{ $$ = new GreaterThan(); /*cout << "binop: " << ">" << endl;*/}
	| GE 	{ $$ = new GreaterOrEqual(); /*cout << "binop: " << ">="<< endl;*/}
	| LT 	{ $$ = new LessThan(); /*cout << "binop: " << "<" << endl;*/}
	| LE 	{ $$ = new LessOrEqual(); /*cout << "binop: " << "<="<< endl;*/}
	| EQ 	{ $$ = new Equal(); /*cout << "binop: " << "=="<< endl;*/}
	| NE 	{ $$ = new NotEqual(); /*cout << "binop: " << "!="<< endl;*/}
	| AND 	{ $$ = new And(); /*cout << "binop: " << "&&"<< endl;*/}
	| OR 	{ $$ = new Or(); /*cout << "binop: " << "||"<< endl;*/}
	;

t : SEMICOLON | EOL ;

then : t | THEN | t THEN ;
do   : t | DO | t DO ;





%%





void yyerror (const char *s)
{
    cerr << s << endl;
}
