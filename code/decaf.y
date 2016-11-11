%{
#include "ClassDefs.h"
#include <bits/stdc++.h>

  extern "C" int yylex();
  extern "C" int yyparse();
  extern "C" FILE *yyin;
  extern "C" int line_num;
  extern union Node yylval;
  extern "C" int errors;
  void yyerror(const char *s);
  class Prog* start = NULL;
  int errors=0;
%}

/* -------------	Tokens 		------------- */
%start Program

%token CLASS
%token CALLOUT RETURN
%token BREAK CONTINUE
%token IF ELSE FOR
%token COMMA SC
%token <value> BOOLEAN CHAR STRING TYPE ID VOID
%token <number> INTEGER
%token OB CB OSB CSB OP CP
%token <value> COND_AND COND_OR NOT
%token <value> ADD SUB MUL DIV MOD
%token <value> LT GT LE GE
%token <value> EQUAL NOT_EQUAL
%token <value> EQ ADDEQ SUBEQ
/* -------------	Left Precedence		------------- */
/* %define parse.error verbose */
%left EQUAL NOT_EQUAL
%left COND_AND COND_OR
%left LT GT LE GE
%left ADD SUB
%left MUL DIV MOD
%nonassoc NOT

/* -------------	Non-Terminal Types		------------- */
%type <prog> Program
%type <fields> Field_declarations
%type <field> Field_declaration
%type <vars> Variables
%type <var> Variable
%type <methods> Method_declarations
%type <method> Method_declaration
%type <method_args> Method_Args
%type <method_args> Method_Arg
%type <block> Block
%type <var_decls> Var_declarations
%type <var_decl> Var_declaration
%type <stmts> Statements
%type <stmt> Statement
%type <assignment> Assignment
%type <parameters> Params
%type <method_call> Method_Call
%type <location> Location
%type <expr> Expression
%type <callout_args> Callout_Args
%type <callout_arg> Callout_Arg
%type <literal> Literal;
%type <mylist> Var_names
/* -------------	Grammer Rules		------------- */
%%
Program:
	CLASS ID OB Field_declarations Method_declarations CB {
    $$ = new Prog(string($2),$4,$5);
    start = $$;
  }
	;
Field_declarations:
  {
    $$ = new fieldDecls();
  }
	| Field_declarations Field_declaration SC {$$->push_back($2);}
	;
Field_declaration:
	TYPE Variables {$$ = new fieldDecl(string($1),$2);}
	;
Variables:
	Variable {$$ = new Vars();$$->push_back($1);}
	| Variables COMMA  Variable { $$->push_back($3); }
	;
Variable:
	ID { $$ = new Var(string("Normal"),string($1));}
	| ID OSB INTEGER CSB { $$ = new Var(string("Array"),string($1),$3);}
  ;
Method_declarations:
	{
    $$ = new methodDecls();
  }
	| Method_declaration Method_declarations {$2->push_back($1);$$ = $2;}
	;
Method_declaration:
	TYPE ID Method_Args Block {$$ = new methodDecl(string($1),$2,$3,$4);}
	| VOID ID Method_Args Block {$$ = new methodDecl(string($1),$2,$3,$4);}
	;
Method_Args:
	OP CP {$$ = new methodArgs();}
	| OP TYPE ID Method_Arg CP {
    methodArg* arg = new methodArg(string($2),string($3));
    $4->push_back(arg);
    $$ = $4;
  }
	;
Method_Arg:
	/* Empty */
  {
    $$ = new methodArgs();
  }
	| COMMA TYPE ID Method_Arg {
    methodArg* arg = new methodArg(string($2),string($3));
    $4->push_back(arg);
    $$ = $4;
  }
	;
Block:
	OB Var_declarations Statements CB {
    $$ = new Block($2,$3);
  }
	;
Var_declarations:
	/* Empty */
  {
    $$ = new varDecls();
  }
	| Var_declaration SC Var_declarations {$3->push_back($1);$$ = $3;}
	;
Var_declaration:
	TYPE ID Var_names {
    $3->push_back($2);
    $$ = new varDecl(string($1),$3);
  }
	;
Var_names:
	/* Empty */
  {
        $$ = new stringList();
  }
	| COMMA ID Var_names {$3->push_back(string($2));$$ = $3;}
	;
Statements:
	/* Empty */
  {
    $$ = new Stmts();
  }
	| Statements Statement {$$->push_back($2);}
	;
Statement:
	Assignment {$$ = $1;}
	| Method_Call SC {$$ = $1;}
	| IF OP Expression CP Block {$$ = new ifElseStmt($3,$5,NULL);}
	| IF OP Expression CP Block ELSE Block  {$$ = new ifElseStmt($3,$5,$7);}
	| FOR ID EQ Expression COMMA Expression Block  {
    $$ = new forStmt(string($2),$4,$6,$7);
  }
	| RETURN SC {$$ = new returnStmt(NULL);}
	| RETURN Expression SC {$$ = new returnStmt($2);}
	| BREAK SC {$$ = new breakStmt();}
	| CONTINUE SC {$$ = new continueStmt();}
	| Block {$$ = $1;}
	;
Assignment:
	Location EQ Expression SC {$$ = new Assignment($1,string($2),$3);}
	| Location SUBEQ Expression SC  {$$ = new Assignment($1,string($2),$3);}
	| Location ADDEQ Expression SC {$$ = new Assignment($1,string($2),$3);}
	;
Method_Call:
	ID OP Params CP {$$ = new Method(string($1),$3);}
	| CALLOUT OP STRING Callout_Args CP {$$ = new calloutCall(string($3),$4);}
	;
Params:
	Expression {$$ = new Params();$$->push_back($1);}
	| Params COMMA Expression {$$->push_back($3);}
	;

Location:
	ID {$$ = new Location(string($1),string("Normal"));}
	| ID OSB Expression CSB {$$ = new Location(string($1),string("Array"),$3);}
	;
Expression:
	Location {$$ = $1;}
	| Method_Call {$$ = $1;}
	| Literal {$$ = $1;}
	| Expression ADD Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression SUB Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression MUL Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression DIV Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression MOD Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression LT Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression GT Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression LE Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression GE Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression EQUAL Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression NOT_EQUAL Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression COND_OR Expression {$$ = new binExpr($1,string($2),$3);}
	| Expression COND_AND Expression {$$ = new binExpr($1,string($2),$3);}
	| SUB Expression {$$ = new unExpr(string($1),$2);}
	| NOT Expression {$$ = new unExpr(string($1),$2);}
	| OP Expression CP {$$ = new EnclExpr($2);}
	;

Callout_Args:
  {$$ = new calloutArgs();}
	| Callout_Args COMMA Callout_Arg {$$->push_back($3);}
	;
Callout_Arg:
	Expression {$$ = new calloutArg($1);}
	| STRING {$$ = new calloutArg(string($1));}
	;
Literal:
	INTEGER {$$ = new intLiteral($1);}
	| CHAR {$$ = new charLiteral(string($1));}
	| BOOLEAN {$$ = new boolLiteral(string($1));}
	;
%%
int main(int argc, char **argv) {
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
	do {
		yyparse();
	} while (!feof(yyin));
	printf("Semantical Analysis Success\n");
	if(start){
    start->traverse(); /* Traversals */
    /* Do the code generation part */
		start->codegen();
    if(errors == 0){
      /* Print the code */
      start->generateCode();
    }
    else{
      cout << errors << " Errors found\n";
    }
	}
}
void yyerror(const char *s){
	errors++;
	printf("Error:%s at %d\n",s,line_num);
  exit(-1);
}
