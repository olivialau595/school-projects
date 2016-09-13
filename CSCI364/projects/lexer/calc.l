%{
// Olivia Lau
// September 10, 2016
// Compilers: Lex Warm Up
// calc.l or Lex.yy.c or calc.c
// Purpose: This is a lexical analyzer using lex to convert simple 
// arithmetic expressions into tokens and outputs them
%}

%%
[(]                              {printf("<l_paren> ");}
[)]                              {printf("<r_paren> ");}
[+]                              {printf("<plus> ");}
[-]                              {printf("<minus> ");}
[*]                              {printf("<mult> ");}
[/]                              {printf("<division> ");}
[a-zA-Z]+                        {printf("<var> ");}
[0-9]+"\."[0-9]+                 {printf("<number> ");}
"\."[0-9]+                       {printf("<number> ");}
[0-9]+                           {printf("<number> ");}
[ \t]                            {;}
.                                {printf("%s ", yytext);}
%%
main()
{
    yylex();
}