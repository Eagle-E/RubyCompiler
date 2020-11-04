%{
#include "lexer.h"
#include <iostream>

using std::cout;	using std::endl;
using std::cerr;

void yyerror(const char* str);

%}

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

%start program

// vul aan met voorrangdeclaraties

%%

// vul aan met producties
program : compstmt {cout << "program : DEF EOL" << endl;}
		;

compstmt    : stmt zeroOrMore_t_stmt zereOrOne_t

zeroOrMore_t_stmt   :
                    | t stmt zeroOrMore_t_stmt
                    ;
zereOrOne_t :   
            | t
            ;

zereOrOne_arglist   :   
                    | arglist
                    ;

zereOrOne_expressions   :   
                        | expressions
                        ;

zeroOrMore_elseif   :
                    | ELSIF expr then compstmt zeroOrMore_elseif
                    ;

zeroOrMore_when : 
                | WHEN expr then compstmt zeroOrMore_when
                ;

zeroOrOne_else  :
                | ELSE compstmt
                ;

literal : INTEGER | BOOLEAN
        ;

stmt    : UNDEF IDENTIFIER
        | DEF IDENTIFIER LPAREN zereOrOne_arglist RPAREN compstmt END
        | RETURN expr
        | IF expr then compstmt zeroOrMore_elseif zeroOrOne_else END
        | UNLESS expr then compstmt zeroOrOne_else END
        | WHILE expr do compstmt END
        | UNTIL expr do compstmt END
        | CASE expr WHEN expr then compstmt zeroOrMore_when zeroOrOne_else END
        | expr
        ;

expr    : IDENTIFIER assignop expr 
        | expr binop expr
        | NOT expr
        | literal
        | IDENTIFIER {cout << "expr : IDENTIFIER" << endl;}
        | MINUS expr
        | IDENTIFIER LPAREN zereOrOne_expressions RPAREN
        | LPAREN expr RPAREN
        ;

expressions : expr
            | expr COMMA expressions
            ;

arglist : IDENTIFIER
        | IDENTIFIER COMMA arglist
        ;

then    : t | THEN | t THEN
        ;

do  : t | DO | t DO
    ;

t   : SEMICOLON | EOL
    ;

assignop    : ASSIGN | PLUSASSIGN | MINUSASSIGN | MULASSIGN | DIVASSIGN | ANDASSIGN | ORASSIGN
            ;

binop	: PLUS | MINUS | MUL | DIV | GT | GE | LT | LE | EQ | NE |AND | OR
        ;
%%

void yyerror (const char *s)
{
    cerr << s << endl;
}
