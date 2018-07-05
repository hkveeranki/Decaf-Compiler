//
// Created by harry7 on 7/4/18.
//

#include "block.h"

#include "statements.h"
#include "variableDeclarations.h"
#include "globals.h"

Block::Block(class variableDeclarations *vars, class Statements *stmts) {
    this->stype = stmtType::NonReturn;
    this->decls_list = vars;
    this->stmts_list = stmts;
}

bool Block::has_return() {
    return stmts_list->has_return();
}

Value *Block::generateCode(globals *currentGlobals) {
    Value *V;
    std::map<std::string, llvm::AllocaInst *> Old_vals;
    V = decls_list->generateCode(Old_vals, currentGlobals);
    V = stmts_list->generateCode(currentGlobals);
    /* Adjust the values back to old values */
    for (auto it = Old_vals.begin(); it != Old_vals.end(); it++) {
        currentGlobals->NamedValues[it->first] = Old_vals[it->first];
    }
    return V;
}
