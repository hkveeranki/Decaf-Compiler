//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODCALL_H
#define DECAF_COMPILER_METHODCALL_H

#include <string>
#include "stmt.h"
#include "expr.h"
#include "globals.h"

class methodCall : public Stmt, public Expr {
protected:
    std::string method_name;
public:
    virtual Value *codegen(globals *currentGlobals) {}
};


#endif //DECAF_COMPILER_METHODCALL_H
