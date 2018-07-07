%{
#include <bits/stdc++.h>
#include "program.h"
#include "decaf.tab.hpp"
#define YY_DECL extern "C" int yylex()
	extern union Node yylval;
	using namespace std;
	int line_num = 1;
%}
digit [0-9]
letter [a-zA-Z]
alpha [0-9a-zA-Z]
delim [ \t]+
char [ -~]
character   \'{char}\'
string (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])
hex_digit {digit}|[a-fA-F]
%%
"class" { return CLASS;}
"void" { yylval.value = strdup(yytext);return VOID; }
"callout" { return CALLOUT; }
"int" { yylval.value = strdup(yytext); return TYPE; }
"boolean" { yylval.value = strdup(yytext); return TYPE; }
"break" { return BREAK; }
"continue" { return CONTINUE; }
"return" { return RETURN; }
"for" { return FOR; }
"if" { return IF; }
"else" { return ELSE; }
"true"|"false" { yylval.value = strdup(yytext);return BOOLEAN; }
"0x"{hex_digit}+|{digit}+ { yylval.number = atoi(yytext);return INTEGER; }
"+" { yylval.value = strdup(yytext);return ADD; }
"-" { yylval.value = strdup(yytext);return SUB; }
"/" { yylval.value = strdup(yytext);return DIV; }
"*" { yylval.value = strdup(yytext);return MUL; }
"%" { yylval.value = strdup(yytext);return MOD; }
"<" { yylval.value = strdup(yytext);return LT; }
">" { yylval.value = strdup(yytext);return GT; }
"<=" { yylval.value = strdup(yytext);return LE; }
">=" {yylval.value = strdup(yytext);return GE; }
"==" { yylval.value = strdup(yytext);return EQUAL; }
"!=" { yylval.value = strdup(yytext);return NOT_EQUAL; }
"=" { yylval.value = strdup(yytext);return EQ; }
"+=" { yylval.value = strdup(yytext);return ADDEQ; }
"-=" { yylval.value = strdup(yytext);return SUBEQ; }
"&&" { yylval.value = strdup(yytext);return COND_AND; }
"||" { yylval.value = strdup(yytext);return COND_OR; }
"," { return COMMA; }
"{" { return OB; }
"}" { return CB; }
"[" {return OSB; }
"]" {return CSB; }
"(" {return OP; }
")" {return CP; }
";" { return SC; }
{letter}{alpha}* { yylval.value = strdup(yytext);return ID; }
{character} { yylval.value = strdup(yytext);return CHAR; }
\"{string}*\" { yylval.value = strdup(yytext);return STRING; }
{delim}						/* Ignore whitespaces tabs and newlines */
"//".*						/* Inline comments So Ignore */
\n { line_num++; }
%%
