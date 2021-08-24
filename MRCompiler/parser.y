%code requires {
#include "lexer.h"
#include <iostream>
#include "Program.h"
#include "CompoundStatement.h"

#include "Expression.h"
#include "LiteralExpression.h"
#include "Statement.h"
#include "ExpressionStatement.h"
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
#include "AssignOp.h"
#include "AssignPlus.h"
#include "AssignMinus.h"
#include "AssignTimes.h"
#include "AssignDivide.h"
#include "AssignOr.h"
#include "AssignAnd.h"
#include "IfStatement.h"
#include "ConditionExpression.h"


using std::cout;	using std::endl;
using std::cerr;

void yyerror(const char* str);

// the abstract syntax tree
extern Program* program;
//extern CompoundStatement* rootStatement;
}

%code{
Program* program = new Program();
 // CompoundStatement* rootStatement = program->getRootStatement(); //new CompoundStatement();
CompoundStatement* rootStatement = new CompoundStatement();
int i = 0;
}

%union
{
	int t_int;
	char* t_str;
	Expression* t_expression;
	Statement* t_statement;
	CompoundStatement* t_cmp_statement;
	Literal* t_literal;
	AssignOp* t_assignop;
	//BinOp * t_binop;
	//Program* t_program;
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
 //%nterm <t_program> program
%nterm <t_cmp_statement> compstmt zeroOrMore_stmt
%nterm <t_statement> stmt
%nterm <t_expression> expr
%nterm <t_literal> literal
%nterm <t_assignop> assignop
 //%nterm <t_binop> binop

%start program

%right PREC_ASSIGN
%left GT GE LT LE EQ NE
%left OR
%left AND
%left PLUS MINUS
%left MUL DIV
%left UMINUS NOT


%%








// vul aan met producties
program : 
		|
		compstmt	{
						//program->setRootStatement(rootStatement);
						program->setRootStatement($1);
					} 
		;

compstmt : stmt zeroOrMore_stmt zeroOrMore_t 
								{
									cout << "@@@ + " << i << endl;
									string s("\t\t");
									$stmt->print(s);
									i++;
									//rootStatement->prependStatement($stmt);
									cout << "<before>" << endl;
									$2->prependStatement($stmt);
									$$ = $2;
									cout << "<after>" << endl;
									
								}
		 ;

zeroOrMore_stmt 
	: /* empty */	{ 
						cout << "@@@ * " << i << endl; i++; 
						$$ = new CompoundStatement();
					}
	| zeroOrMore_stmt zeroOrMore_t stmt	
								{
									cout << "@@@ - " << i << endl;
									string s("\t\t");
									$stmt->print(s);
									i++;
									//rootStatement->appendStatement($stmt);
									$$->appendStatement($stmt);
								}
	;

zeroOrMore_t	
	:
	| zeroOrMore_t t
	;

zeroOrOne_t	
:
| t
;

t : SEMICOLON { cout <<"[t]: " << ";" <<  endl;}
  | EOL		  { cout <<"[t]: " << "EOL" <<  endl;}
  ;

then: t			{ cout <<"[then]: " << "<t>" <<  endl;}
	| THEN		{ cout <<"[then]: " << "then" <<  endl;}
	| t THEN	{ cout <<"[then]: " << "<t> then" <<  endl;}
	;
do   : t | DO | t DO ;

stmt    : UNDEF IDENTIFIER	{cout << "undef" << endl;}
		| DEF IDENTIFIER LPAREN zereOrOne_arglist RPAREN compstmt END {cout << "function def" << endl;}
		| RETURN expr		{cout << "return" << endl;}

		| IF expr then zeroOrOne_t compstmt zeroOrMore_elseif zeroOrOne_else END
			{
				cout << "IF STMT" << endl;
				IfStatement * ifStm = new IfStatement();
				ifStm->setIfStatement(new ConditionExpression($expr), $compstmt);
				$$ = ifStm;
			}

		| UNLESS expr then compstmt zeroOrOne_else END {cout << "unless" << endl;}
		| WHILE expr do compstmt END {cout << "while" << endl;}
		| UNTIL expr do compstmt END {cout << "until" << endl;}
		| CASE expr WHEN expr then compstmt zeroOrMore_when zeroOrOne_else END {cout << "case" << endl;}
		| expr		{$$ = new ExpressionStatement($expr);}		
        ;



expr	: expr PLUS expr			{$$ = new BinOpExpression($1, $3, new Add());}
		| expr MINUS expr			{$$ = new BinOpExpression($1, $3, new Sub());}
		| expr MUL expr				{$$ = new BinOpExpression($1, $3, new Mul());}
		| expr DIV expr				{$$ = new BinOpExpression($1, $3, new Div());}
		| expr GT expr				{$$ = new BinOpExpression($1, $3, new GreaterThan());}
		| expr GE expr				{$$ = new BinOpExpression($1, $3, new GreaterOrEqual());}
		| expr LT expr				{$$ = new BinOpExpression($1, $3, new LessThan());}
		| expr LE expr				{$$ = new BinOpExpression($1, $3, new LessOrEqual());}
		| expr EQ expr				{$$ = new BinOpExpression($1, $3, new Equal());}
		| expr NE expr				{$$ = new BinOpExpression($1, $3, new NotEqual());}
		| expr AND expr				{$$ = new BinOpExpression($1, $3, new And());}
		| expr OR expr				{$$ = new BinOpExpression($1, $3, new Or());}

        | NOT expr					{$$ = new UnaryBooleanNegationExpression($2); }
        | MINUS expr %prec UMINUS	{$$ = new UnaryNumericNegationExpression($2); }

        | literal					{$$ = new LiteralExpression($literal); }
        | IDENTIFIER				{$$ = new IdentifierExpression($1);	}
		| IDENTIFIER assignop expr %prec PREC_ASSIGN 
									{
										$$ = new AssignmentExpression(new IdentifierExpression($1), $3, $2);
									}
		| IDENTIFIER LPAREN zereOrOne_expressions RPAREN 
									{
										/*cout << "function call" << endl;*/
									}
		| LPAREN expr RPAREN		{$$ = $2; }
        ;

expressions
	: expr
	| expressions COMMA expr
	;

zereOrOne_expressions
	:   
	| expressions
	;

arglist 
	: IDENTIFIER
	| arglist COMMA IDENTIFIER
	;

zereOrOne_arglist   
	:   
	| arglist
	;

zeroOrMore_elseif
	:
	| zeroOrMore_elseif ELSIF expr then compstmt
		{
			
		}
	;

zeroOrOne_else
	:
	| ELSE compstmt {/*$$ = $2;*/ }
	;

zeroOrMore_when 
	: 
	| zeroOrMore_when WHEN expr then compstmt
	;

literal
	: INTEGER { $$ = new IntegerLiteral($INTEGER); }
	| BOOLEAN { $$ = new BooleanLiteral($BOOLEAN); }
	;

assignop
	: ASSIGN		{$$ = new AssignOp(); }
	| PLUSASSIGN 	{$$ = new AssignPlus(); }
	| MINUSASSIGN 	{$$ = new AssignMinus(); }
	| MULASSIGN 	{$$ = new AssignTimes(); }
	| DIVASSIGN 	{$$ = new AssignDivide(); }
	| ANDASSIGN 	{$$ = new AssignAnd(); }
	| ORASSIGN 		{$$ = new AssignOr(); }
	;









%%





void yyerror (const char *s)
{
    cerr << s << endl;
}
