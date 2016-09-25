%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYDEBUG 1
        extern int yylex();
        extern int yyparse();
        extern FILE *yyin;
	extern FILE *flex_out; 
        extern int line_num;
        FILE *bison_out;
	int errors=0;
        void yyerror(const char *s);
%}
/* -------------	Union 		-------------*/
%union{
	int val;
	char *value;
}

/* -------------	Tokens 		------------- */
%token CLASS TYPE
%token CALLOUT RETURN VOID
%token BREAK CONTINUE
%token IF ELSE FOR
%token ID COMMA SC
%token BOOLEAN INTEGER CHAR STRING
%token OB CB OSB CSB OP CP
%token COND_AND COND_OR
%token ADD SUB MUL DIV MOD
%token LT GT LE GE
%token EQUAL NOT_EQUAL
%token EQ ADDEQ SUBEQ
/* -------------	Left Precedence		------------- */
%define parse.error verbose
%left EQUAL NOT_EQUAL
%left COND_AND COND_OR
%left LT GT LE GE
%left ADD SUB
%left MUL DIV MOD
%left NOT
%left '-'

/* -------------	Grammer Rules		------------- */
%%
Program:
	CLASS ID OB Field_declarations Method_declarations CB {fprintf(bison_out,"Program Encountered\n");}
	;
Field_declarations:
	| Field_declarations Field_declaration SC
	;
Field_declaration:
	TYPE Variables
	;
Variables:
	ID Variable
	| ID OSB INTEGER CSB Variable
	;
Variable:
	/* Empty */
	| COMMA ID Variable
	| COMMA ID OSB INTEGER CSB Variable
Method_declarations:
	/* Empty */
	| Method_declaration Method_declarations
	;
Method_declaration:
	TYPE ID Args_list Block
	| VOID ID Args_list Block
	;
Args_list:
	OP CP
	| OP TYPE ID Arg CP
	;
Arg:
	/* Empty */
	| COMMA TYPE ID Arg
	;
Block:
	OB Var_declarations Statements CB
	;
Var_declarations:
	/* Empty */
	| Var_declaration SC Var_declarations
	;
Var_declaration:
	TYPE ID Var_names
	;
Var_names:
	/* Empty */
	| COMMA ID Var_names
	;
Statements:
	/* Empty */
	| Statements Statement
	;
Statement:
	Location Assign_Op Expression SC
	| Method_Call SC
	| IF OP Expression CP Block 
	| IF OP Expression CP Block ELSE Block
	| FOR ID EQ Expression COMMA Expression Block
	| RETURN SC
	| RETURN Expression SC
	| BREAK SC
	| CONTINUE SC
	| Block
	;
Assign_Op:
	EQ
	| SUBEQ
	| ADDEQ
	;
Method_Call:
	ID OP Method_args CP
	| CALLOUT OP STRING Callout_args CP
	;
Method_args:
	/* Empty */
	| Expression
	| Method_args COMMA Expression
	;

Location:
	ID
	| ID OSB Expression CSB
	;
Expression:
	Location
	| Method_Call
	| Literal
	| Expression ADD Expression
	| Expression SUB Expression
	| Expression MUL Expression
	| Expression DIV Expression
	| Expression MOD Expression
	| Expression LT Expression
	| Expression GT Expression
	| Expression LE Expression
	| Expression GE Expression
	| Expression EQUAL Expression
	| Expression NOT_EQUAL Expression
	| Expression COND_OR Expression
	| Expression COND_AND Expression
	| '-' Expression
	| NOT Expression
	| OP Expression CP
	;
Callout_args:
	/* Empty */
	|COMMA Callout_Args
	;
Callout_Args:
	Callout_arg
	| Callout_Args COMMA Callout_arg
	;
Callout_arg:
	Expression | STRING
	;
Literal:
	INTEGER
	| CHAR
	| BOOLEAN
	;
%%
int main(int argc, char **argv) {
	bison_out = fopen("bison_output.txt","w");
	flex_out = fopen("flex_output.txt","w");
	if(argc == 1) {
		printf("No Input File Given\n");
		exit(-1);
	}
	printf("Input file is %s\n",argv[1]);
	FILE *input = fopen(argv[1], "r");
	if (input == NULL){
		printf("Can't open the given file!\n");
		exit(-1);
	}
	yyin = input;
	do{
		yyparse();
	}while (!feof(yyin));
	printf("Success\n");
}
void yyerror(const char *s){
	printf("%s\n",s);
	exit(-1);
}
