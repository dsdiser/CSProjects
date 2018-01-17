/*
 A scanner for a Anaconda integers. Outputs lines like
 "token: lexeme", for example "decimal_integer: +12".
*/
%option noyywrap

%{
%}

SIGN         [+|-]
DECIMAL      [0-9]
DECIMALBEGIN [1-9]
OCTAL        [0-7]
OCTALBEGIN   [1-7]
HEX          [0-9a-f]
HEXBEGIN     [1-9a-f]
X            [X|x]

%%

{SIGN}?(0|{X})(0|{HEXBEGIN}{HEX}*)        printf("HEX");
{SIGN}?(0|{OCTALBEGIN}{OCTAL}*)            printf("OCTAL");
{SIGN}?(0|{DECIMALBEGIN}{DECIMAL}*)        printf("DECIMAL");
"#".*\n                                   printf("COMMENT: %s", yytext);
[ \t\n]+                                  /* skip space, tab and newline */
.                                         printf("ignore: %s\n", yytext);

%%

main(argc, argv)
  int argc; char **argv;
  { 
    if (argc>1) yyin=fopen(argv[1],"r"); else yyin=stdin;
    yylex();
  }

