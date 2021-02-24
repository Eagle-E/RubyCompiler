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
program : compstmt ;

compstmt	: stmt zeroOrMore_t_stmt zeroOrOne_t
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
        | IDENTIFIER {cout << $1 << endl;}
        | MINUS expr
		| IDENTIFIER LPAREN zereOrOne_expressions RPAREN
		| LPAREN expr RPAREN
        ;

expressions : expr
            | expressions COMMA expr
            ;

arglist : IDENTIFIER
        | arglist COMMA IDENTIFIER
        ;

literal : INTEGER {cout << $1 << endl;} | BOOLEAN {cout << $1 << endl;};
assignop : ASSIGN | PLUSASSIGN | MINUSASSIGN | MULASSIGN | DIVASSIGN | ANDASSIGN | ORASSIGN ;
binop : PLUS | MINUS | MUL | DIV | GT | GE | LT | LE | EQ | NE |AND | OR ;
t : SEMICOLON | EOL ;
do  : t | DO | t DO ;
then : t | THEN | t THEN ;


zeroOrMore_t_stmt : 
				  | zeroOrMore_t_stmt t stmt 
				  ;

zeroOrOne_t	:
			| t
			;

zereOrOne_expressions   :   
                        | expressions
                        ;

zeroOrOne_else  :
                | ELSE compstmt
                ;

zeroOrMore_elseif   :
                    | zeroOrMore_elseif ELSIF expr then compstmt
                    ;

zeroOrMore_when : 
                | zeroOrMore_when WHEN expr then compstmt
                ;

zereOrOne_arglist   :   
                    | arglist
                    ;

%%

void yyerror (const char *s)
{
    cerr << s << endl;
}
