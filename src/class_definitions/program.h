//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_PROG_H
#define DECAF_COMPILER_PROG_H
#endif

#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1

#include "assignment.h"
#include "astNode.h"
#include "binaryExpression.h"
#include "block.h"
#include "boolLiteral.h"
#include "breakStatement.h"
#include "calloutArgument.h"
#include "calloutArguments.h"
#include "calloutCall.h"
#include "charLiteral.h"

#include "continueStatement.h"
#include "enclosedExpression.h"
#include "expression.h"
#include "fieldDeclaration.h"
#include "fieldDeclarations.h"
#include "forStatement.h"
#include "ifElseStatements.h"
#include "integerLiteral.h"
#include "literal.h"
#include "location.h"
#include "methodArgument.h"
#include "methodArguments.h"
#include "methodCall.h"
#include "methodDeclaration.h"
#include "methodDeclarations.h"
#include "method.h"
#include "parameters.h"
#include "returnStatement.h"
#include "statement.h"
#include "statements.h"
#include "stringList.h"
#include "stringLiteral.h"
#include "unaryExpression.h"
#include "utilities.h"
#include "variableDeclaration.h"
#include "variableDeclarations.h"
#include "variable.h"
#include "variables.h"
#include "globals.h"

union Node {
    int number;

    char *value;

    class Program *program{};

    class fieldDeclarations *fields;

    class fieldDeclaration *field;

    class Variables *vars;

    class Variable *var;

    class methodDeclarations *methods;

    class methodDeclaration *method;

    class Block *block;

    class variableDeclarations *var_decls;

    class variableDeclaration *var_decl;

    class Statements *stmts;

    class Statement *stmt;

    class Expression *expr;

    class calloutArgument *callout_arg;

    class calloutArguments *callout_args;

    class Parameters *parameters;

    class methodArguments *method_args;

    class methodCall *method_call;

    class Location *location;

    class Assignment *assignment;

    class Literal *literal;

    class stringList *mylist;

    Node() = default;

    ~Node() = default;
};

typedef union Node YYSTYPE;


class Program : public astNode {
private:
    string name; /* name of the class */
    class methodDeclarations *methods; /* list of methods */
    class fieldDeclarations *fields; /* list of fields */
public:
    Program(string name, class fieldDeclarations *, class methodDeclarations *);

    Value *generateCode() override;

    void generateCodeDump();

    globals *currentGlobals;
};


#endif
