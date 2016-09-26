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
%token CLASS
%token CALLOUT RETURN VOID
%token BREAK CONTINUE
%token IF ELSE FOR
%token COMMA SC
%token<value> BOOLEAN CHAR STRING TYPE ID
%token<val> INTEGER
%token OB CB OSB CSB OP CP
%token COND_AND COND_OR
%token ADD SUB MUL DIV MOD
%token LT GT LE GE
%token EQUAL NOT_EQUAL
%token EQ ADDEQ SUBEQ
/* -------------	Left Precedence		------------- */
/* %define parse.error verbose */
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
	TYPE Variables {fprintf(bison_out,"%s Field Declarations\n",$1);}
	;
Variables:
	ID Variable { fprintf(bison_out,"ID=%s\n",$1); }
	| ID OSB INTEGER CSB Variable { fprintf(bison_out,"ID=%s\nSize=%d\n",$1,$3); }
	;
Variable:
	/* Empty */
	| COMMA ID Variable { fprintf(bison_out,"ID=%s\n",$2); }
	| COMMA ID OSB INTEGER CSB Variable { fprintf(bison_out,"ID=%s\nSize=%d\n",$2,$4);}
Method_declarations:
	/* Empty */
	| Method_declaration Method_declarations
	;
Method_declaration:
	TYPE ID Args_list Block {fprintf(bison_out,"%s Method Declaration\nID=%s\n",$1,$2);}
	| VOID ID Args_list Block {fprintf(bison_out,"Void Method Declaration\nID=%s\n",$2);}
	;
Args_list:
	OP CP
	| OP TYPE ID Arg CP {fprintf(bison_out,"%s Argument %s\n",$2,$3);}
	;
Arg:
	/* Empty */
	| COMMA TYPE ID Arg {fprintf(bison_out,"%s Argument %s\n",$2,$3);}
	;
Block:
	OB Var_declarations Statements CB
	;
Var_declarations:
	/* Empty */
	| Var_declaration SC Var_declarations
	;
Var_declaration:
	TYPE ID Var_names {fprintf(bison_out,"ID=%s for %s Variable Declarations\n",$2,$1);}
	;
Var_names:
	/* Empty */
	| COMMA ID Var_names {fprintf(bison_out,"ID=%s\n",$2);}
	;
Statements:
	/* Empty */
	| Statements Statement
	;
Statement:
	Location Assign_Op Expression SC
	| Method_Call SC
	| IF OP Expression CP Block {fprintf(bison_out,"IF Block Encountered\n");}
	| IF OP Expression CP Block ELSE Block  {fprintf(bison_out,"IF ELSE Block Encountered\n");}
	| FOR ID EQ Expression COMMA Expression Block  {fprintf(bison_out,"FOR Block Encountered\n");}
	| RETURN SC {fprintf(bison_out,"Return Encountered\n");}
	| RETURN Expression SC {fprintf(bison_out,"Return Encountered\n");}
	| BREAK SC {fprintf(bison_out,"Break Encountered\n");}
	| CONTINUE SC {fprintf(bison_out,"Continue Encountered\n");}
	| Block
	;
Assign_Op:
	EQ {fprintf(bison_out,"= Assignment Encountered\n");}
	| SUBEQ {fprintf(bison_out,"-= Assignment Encountered\n");}
	| ADDEQ {fprintf(bison_out,"+= Assignment Encountered\n");}
	;
Method_Call:
	ID OP Method_args CP {fprintf(bison_out,"Method call for %s Encountered\n",$1);}
	| CALLOUT OP STRING Callout_args CP {fprintf(bison_out,"CALLOUT for %s Encountered\n",$3);}
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
	| Expression ADD Expression {fprintf(bison_out,"ADDITION Expression Encountered\n");}
	| Expression SUB Expression {fprintf(bison_out,"SUBTRACTION Expression Encountered\n");}
	| Expression MUL Expression {fprintf(bison_out,"MULTIPLICATION Encountered\n");}
	| Expression DIV Expression {fprintf(bison_out,"DIVISION Encountered\n");}
	| Expression MOD Expression {fprintf(bison_out,"MOD Encountered\n");}
	| Expression LT Expression {fprintf(bison_out,"LESS THAN Encountered\n");}
	| Expression GT Expression {fprintf(bison_out,"GREATER THAN Encountered\n");}
	| Expression LE Expression {fprintf(bison_out,"LESS THAN EQUAL TO Encountered\n");}
	| Expression GE Expression {fprintf(bison_out,"GREATER THAN EQUAL TO  Encountered\n");}
	| Expression EQUAL Expression {fprintf(bison_out,"EQUALS Encountered\n");}
	| Expression NOT_EQUAL Expression {fprintf(bison_out,"NOT_EQUALS Encountered\n");}
	| Expression COND_OR Expression {fprintf(bison_out,"CONDITIONAL OR Encountered\n");}
	| Expression COND_AND Expression {fprintf(bison_out,"CONDITIONAL AND Encountered\n");}
	| SUB Expression {fprintf(bison_out,"UNARY - Encountered\n");}
	| NOT Expression {fprintf(bison_out,"NOT Encountered");}
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
	Expression
	| STRING {fprintf(bison_out,"STRING LITERAL=%s\n",$1);}
	;
Literal:
	INTEGER {fprintf(bison_out,"INT LITERAL=%d\n",$1);}
	| CHAR {fprintf(bison_out,"CHAR LITERAL=%s\n",$1);}
	| BOOLEAN {fprintf(bison_out,"BOOLEAN LITERAL=%s\n",$1);}
	;
%%
int main(int argc, char **argv) {
	bison_out = fopen("bison_output.txt","w");
	flex_out = fopen("flex_output.txt","w");
	if(argc == 1) {
		printf("No Input File Given\n");
		exit(-1);
	}
	FILE *input = fopen(argv[1], "r");
	if (input == NULL){
		printf("Can't open the given file!\n");
		exit(-1);
	}
	yyin = input;
	do{
		yyparse();
	}while (!feof(yyin));
	if(errors == 0){
		printf("Success\n");
	}
	else{
		printf("Compilation Done\n%d compilation Errors found\n",errors);
	}
}
void yyerror(const char *s){
	errors++;
	printf("%s at Line:%d\n",s,line_num);
//	exit(-1);
}
