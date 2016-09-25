%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bison_parser.tab.h"
	static void comment(void);
	FILE* flex_out;
	int line_num = 0;
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
"class" { fprintf(flex_out, "CLASS\n"); return CLASS;}
"void" { return VOID; }
"callout" { fprintf(flex_out, "CALLOUT\n"); return CALLOUT; }
"int" { fprintf(flex_out, "INT_DECLARATION\n"); return TYPE; }
"boolean" { fprintf(flex_out, "BOOLEAN_DECLARATION\n");return TYPE; }
"break" { fprintf(flex_out, "BREAK\n");return BREAK; }
"continue" { fprintf(flex_out, "CONTINUE\n"); return CONTINUE; }
"return" { return RETURN; }
"for" { return FOR; }
"if" { return IF; }
"else" { return ELSE; }
"true"|"false" { fprintf(flex_out, "BOOLEAN:%s\n",yytext);yylval = strdup(yytext);return BOOLEAN; }
"0x"{hex_digit}+|{digit}+ { fprintf(flex_out, "INT:%s\n",yytext);yylval = strdup(yytext);return INTEGER; }
"+" { fprintf(flex_out, "ARITH_OP:%s\n",yytext);return ADD; }
"-" { fprintf(flex_out, "ARITH_OP:%s\n",yytext);return SUB; }
"/" { fprintf(flex_out, "ARITH_OP:%s\n",yytext);return DIV; }
"*" { fprintf(flex_out, "ARITH_OP:%s\n",yytext);return MUL; }
"%" { fprintf(flex_out, "ARITH_OP:%s\n",yytext);return MOD; }
"<" { fprintf(flex_out, "REL_OP:%s\n",yytext);return LT; }
">" { fprintf(flex_out, "REL_OP:%s\n",yytext);return GT; }
"<=" { fprintf(flex_out, "REL_OP:%s\n",yytext); return LE; }
">=" { fprintf(flex_out, "REL_OP:%s\n",yytext);return GE; }
"==" { fprintf(flex_out, "EQ_OP:%s\n",yytext);return EQUAL; }
"!=" { fprintf(flex_out, "EQ_OP:%s\n",yytext);return NOT_EQUAL; }
"=" { fprintf(flex_out, "ASSIGN_OP:%s\n",yytext);return EQ; }
"+=" { fprintf(flex_out, "ASSIGN_OP:%s\n",yytext);return ADDEQ; }
"-=" { fprintf(flex_out, "ASSIGN_OP:%s\n",yytext);return SUBEQ; }
"&&" { fprintf(flex_out, "COND_OP:%s\n",yytext);return COND_AND; }
"||" { fprintf(flex_out, "COND_OP:%s\n",yytext);return COND_OR; }
"," { return COMMA; }
"{" { /* fprintf(flex_out, "Returning OB\n"); */return OB; }
"}" { /* fprintf(flex_out, "Returning CB\n"); */return CB; }
"[" {/*  fprintf(flex_out, "Returning OSB\n");*/return OSB; }
"]" { /* fprintf(flex_out, "Returning CSB\n");*/return CSB; }
"(" { /* fprintf(flex_out, "Returning OP\n"); */return OP; }
")" { /* fprintf(flex_out, "Returning CP\n"); */return CP; }
";" { return SC; }
{letter}{alpha}* { fprintf(flex_out, "ID:%s\n",yytext);return ID; }
{character} { fprintf(flex_out, "CHAR:%s\n",yytext);return CHAR; }
\"{string}*\" { fprintf(flex_out, "STRING:%s\n",yytext);return STRING; }
{delim}						/* Ignore whitespaces tabs and newlines */
"//".*						/* Inline comments So Ignore */
\n { line_num++; }
%%
static void comment(void)
{
	int c;
	while ((c = input()) != 0)
		if (c == '*')
		{
			while ((c = input()) == '*')
				;

			if (c == '/')
				return;

			if (c == 0)
				break;
		}
}
