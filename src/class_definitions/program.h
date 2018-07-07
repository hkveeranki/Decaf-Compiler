

/** \mainpage Decaf Compiler
*   \brief Simple Compiler written for Decaf programming language.
 *  \section design_process Design Process
 *   - Designed with visitor design pattern and built using flex, bison and llvm framework in cpp.
 *   - Visitor design pattern is used.
 *   - This is built as a part of course work for compilers course at IIIT Hyderabad, as a course project. So, the design
 *     and implementation are more focused towards learning the principles behind compiler design than practical
 *     implications and other production level issues.
*   \section contributing Contributing
 *   - Contributions are welcome, be it bug fixes or feature additions.
 *   - If you find a bug please raise a bug at [Issue tracker](https://github.com/harry-7/Decaf-Compiler/issues).
 *   - If you feel like you can improve the compiler by adding new features, please make a pull request
 *   [here](https://github.com/harry-7/Decaf-Compiler/)
*   \section  redistribution Licence and Distributing
 *   This project is open source and distributed under [MIT licence](https://en.wikipedia.org/wiki/MIT_License). Please
 *   check the [Licence](https://github.com/harry-7/Decaf-Compiler/blob/master/LICENCE) file for more info on
 *   how this can be redistributed.
*   \author Hemanth Kumar Veeranki <hems.india1997@gmail.com>
*/

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
#include "functionCall.h"
#include "methodDeclaration.h"
#include "methodDeclarations.h"
#include "methodCall.h"
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
#include "constructs.h"

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

    class functionCall *function_call;

    class Location *location;

    class Assignment *assignment;

    class Literal *literal;

    class stringList *mylist;

    Node() = default;

    ~Node() = default;
};

typedef union Node YYSTYPE;

/**
 * \class Program
 * Class to deal with the entire decaf program
 */
class Program : public astNode {
private:
    /* name of the class */
    string name;

    /* list of methods */
    class methodDeclarations *methods;

    /* list of fields */
    class fieldDeclarations *fields;

public:
    Program(string name, class fieldDeclarations *, class methodDeclarations *);

    Value *generateCode();

    void generateCodeDump();

    Constructs *compilerConstructs;
};


#endif
