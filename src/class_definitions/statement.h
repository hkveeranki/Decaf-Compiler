/**
 * Abstract class to deal with all types of statements in the code
 */

#ifndef DECAF_COMPILER_STATEMENT_H
#define DECAF_COMPILER_STATEMENT_H


#include "astNode.h"
#include "constructs.h"


class Statement : public astNode {
protected:
    bool mhas_return;
    bool mhas_break ;
    bool mhas_continue;
public:
    Statement() {  mhas_return=false; mhas_break=false; mhas_continue=false; }

    Value *generateCode(Constructs *compilerConstructs) override {}

    virtual bool has_return(){
        return mhas_return;
    };
    virtual bool has_break(){
        return mhas_break;
    };
    virtual bool has_continue(){
        return mhas_continue;
    };

};

#endif
