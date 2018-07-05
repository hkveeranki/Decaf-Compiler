//
// Created by harry7 on 7/4/18.
//

#include "block.h"
#include "common.h"
#include "stmts.h"
#include "varDecls.h"
#include "globals.h"

Block::Block(class varDecls *vars, class Stmts *stmts) {
    this->stype = stmtType::NonReturn;
    this->decls_list = vars;
    this->stmts_list = stmts;
}

bool Block::has_return() {
    return stmts_list->has_return();
}

Value *Block::codegen(globals *currentGlobals) {
    Value *V;
    std::map<std::string, llvm::AllocaInst *> Old_vals;
    V = decls_list->codegen(Old_vals, currentGlobals);
    V = stmts_list->codegen(currentGlobals);
    /* Adjust the values back to old values */
    for (auto it = Old_vals.begin(); it != Old_vals.end(); it++) {
        currentGlobals->NamedValues[it->first] = Old_vals[it->first];
    }
    return V;
}
