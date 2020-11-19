%{
  /* 
    ruby.lex: lex-file for ruby
  */

#include "parser.h"

  /* 
    Keep track of current position of lex for error messages, i.e. 
    the position just *after* the last token read 
  */
int line_nr = 1;
int col_nr = 1; 

%}

DIGIT       [0-9]
UCHAR       [A-Z]
LCHAR       [a-z]
ALPHA       {UCHAR}|{LCHAR}
ALPHANUM    {ALPHA}|{DIGIT}
IDENTIFIER  [[:alpha:]_]([[:alnum:]_])*
INTEGER     [[:digit:]]+
LINEEND     (\r\n|\r|\n)

%%

undef        {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return UNDEF;}
def          {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return DEF;}
end          {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return END;}
return       {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return RETURN;}
if           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return IF;}
then         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return THEN;}
elsif        {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return ELSIF;}
else         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return ELSE;}
unless       {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return UNLESS;} 
while        {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return WHILE;}
do           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return DO;}
until        {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return UNTIL;}
case         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return CASE;}
when         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "keyword");      */ return WHEN;}
true         {col_nr += yyleng;      yylval.integer = 1;            /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "bool true");    */ return BOOLEAN;}
false        {col_nr += yyleng;      yylval.integer = 0;            /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "bool false");   */ return BOOLEAN;}                          
;            {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "semicol");      */ return SEMICOLON;}
\(           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "parenth");      */ return LPAREN;}
\)           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "parenth");      */ return RPAREN;}
,            {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comma");        */ return COMMA;}             
[+]=         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return PLUSASSIGN;}
[-]=         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return MINUSASSIGN;}
[*]=         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return MULASSIGN;}
[/]=         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return DIVASSIGN;}
&&=          {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return ANDASSIGN;}
\|\|=        {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return ORASSIGN;}
\+           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "operator");     */ return PLUS;}
-            {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "operator");     */ return MINUS;}
\*           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "operator");     */ return MUL;}
[/]          {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "operator");     */ return DIV;}                                                   
==           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comparison");   */ return EQ;}
!=           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comparison");   */ return NE;}
(>=)         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comparison");   */ return GE;}
(>)          {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comparison");   */ return GT;}
(<=)         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comparison");   */ return LE;}
(<)          {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "comparison");   */ return LT;}                                       
=            {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "assign");       */ return ASSIGN;}                                          
&&           {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "boolean oper"); */ return AND;}
\|\|         {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "boolean oper"); */ return OR;}
!            {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "boolean oper"); */ return NOT;}                                                                      
{LINEEND}    {col_nr = 0; line_nr++;                                /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, "\\n", "new line");      */ return EOL;}
{INTEGER}    {col_nr += yyleng;      yylval.integer=atoi(yytext);   /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "int");          */ return INTEGER;}
[[:blank:]]* {col_nr += yyleng;                                     /*printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "tab/space");    */ }
{IDENTIFIER} {
        col_nr += yyleng; 
        yylval.str = new char[strlen(yytext+1)]; // copy yytext to yyval.str
        strcpy(yylval.str, yytext);             
            
        //printf("col %d, line %d, token %s, info: %s\n", col_nr, line_nr, yytext, "id");        
        return IDENTIFIER;
}

.      {
            if (yytext[0] < ' ') /* non-printable char */
            { 
                /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@'); 
            }
            else 
            {
                if (yytext[0] > '~') 
                {
                    /* non-printable char printed as octal int padded with zeros, eg \012*/
                    /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
                }
                else 
                {
                    /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
                }
            }
            /* lex read exactly one char; the illegal one */
            fprintf(stderr," at line %d column %d\n", line_nr, (col_nr-1));
        }
%%

/* 
    Function called by (f)lex when EOF is read. If yywrap returns a
    true (non-zero) (f)lex will terminate and continue otherwise.
*/
int yywrap(){
  return (1);
}

