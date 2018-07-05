//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_PROG_H
#define DECAF_COMPILER_PROG_H

#include "assignment.h"
#include "astNode.h"
#include "binExpr.h"
#include "block.h"
#include "boolLiteral.h"
#include "breakStmt.h"
#include "calloutArg.h"
#include "calloutArgs.h"
#include "calloutCall.h"
#include "charLiteral.h"
#include "common.h"
#include "continueStmt.h"
#include "enclExpr.h"
#include "expr.h"
#include "fieldDecl.h"
#include "fieldDecls.h"
#include "forStmt.h"
#include "ifElseStmt.h"
#include "intLiteral.h"
#include "literal.h"
#include "location.h"
#include "methodArg.h"
#include "methodArgs.h"
#include "methodCall.h"
#include "methodDecl.h"
#include "methodDecls.h"
#include "method.h"
#include "params.h"
#include "returnStmt.h"
#include "stmt.h"
#include "stmts.h"
#include "stringList.h"
#include "stringLiteral.h"
#include "unExpr.h"
#include "utilities.h"
#include "varDecl.h"
#include "varDecls.h"
#include "var.h"
#include "vars.h"
#include "globals.h"

union Node {
    int number;
    char *value;

    class Prog *prog;

    class fieldDecls *fields;

    class fieldDecl *field;

    class Vars *vars;

    class Var *var;

    class methodDecls *methods;

    class methodDecl *method;

    class Block *block;

    class varDecls *var_decls;

    class varDecl *var_decl;

    class Stmts *stmts;

    class Stmt *stmt;

    class Expr *expr;

    class calloutArg *callout_arg;

    class calloutArgs *callout_args;

    class Params *parameters;

    class methodArgs *method_args;

    class methodArg *method_arg;

    class methodCall *method_call;

    class Location *location;

    class Assignment *assignment;

    class Literal *literal;

    class stringList *mylist;

    Node() {
        number = 0;
        value = nullptr;
        fields = nullptr;
        field = nullptr;
        methods = nullptr;
        method = nullptr;
        var_decls = nullptr;
        stmts = nullptr;
        callout_args = nullptr;
        method_args = nullptr;
    }

    ~Node() {};
};

typedef union Node YYSTYPE;

#define YYSTYPE_IS_DECLARED 1


class Prog : public astNode {
private:
    string name; /* name of the class */
    class methodDecls *methods; /* list of methods */
    class fieldDecls *fields; /* list of fields */
public:
    Prog(string name, class fieldDecls *, class methodDecls *);

    Value *codegen();

    void generateCode();

    globals *currentGlobals;
};


#endif //DECAF_COMPILER_PROG_H
