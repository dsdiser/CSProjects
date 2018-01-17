/* 

A scanner for a toy Pascal-like language. Outputs lines like
"token: lexeme (representation)", for example "integer: 0012 (12)"

*/

%{
#include <math.h> /* needed for calls to atoi() and atof() */
%}

DIGIT    [0-9]
ALPHA    [a-zA-Z]
ALPHANUM [a-zA-Z0-9]

%%

{DIGIT}+                  printf("Integer: %s (%d)\n", yytext, atoi(yytext));

{DIGIT}+"."{DIGIT}*       printf("Float: %s (%g)\n", yytext, atof(yytext));

if|then|begin|end|return  printf("Keyword: %s\n",yytext);

{ALPHA}{ALPHANUM}*        printf("Identifier: %s\n",yytext);

"+"|"-"|"*"|>|=|"/"       printf("Operator: %s\n",yytext);

"{"[^}\n]*"}"             printf("Comment: %s\n", yytext);

[ \t\n]+                  /* skip space, tab and newline */

.                         printf("Unrecognized: %s\n",yytext);

%%

main(argc,argv)
  int argc; char **argv;
  {
    if (argc>1) yyin=fopen(argv[1],"r"); else yyin=stdin;
    yylex();
  }
