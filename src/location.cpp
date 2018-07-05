//
// Created by harry7 on 7/4/18.
//

#include "location.h"
#include "utilities.h"
#include "globals.h"

Location::Location(string var, string location_type, class Expression *expr) {
    this->var = var;
    this->location_type = location_type;
    this->expr = expr;
    this->etype = exprType::location;
}

Location::Location(string var, string location_type) {
    this->var = var;
    this->location_type = location_type;
    this->etype = exprType::location;
}

string Location::getVar() {
    return var;
}

bool Location::is_array() {
    return location_type.compare("Array") == 0;
}

class Expression *Location::getExpr() {
    return expr;
}


Value *Location::generateCode(globals *currentGlobals) {
    Value *V = currentGlobals->NamedValues[var];
    if (V == 0) {
        V = currentGlobals->TheModule->getNamedGlobal(var);
    }
    if (V == 0) {
        currentGlobals->errors++;
        return reportError("Unknown Variable name " + var);
    }
    if (this->location_type != "Array") {
        return V;
    }
    if (this->expr != nullptr) {
        Value *index = expr->generateCode(currentGlobals);
        if (expr->getEtype() == exprType::location) {
            index = currentGlobals->Builder->CreateLoad(index);
        }
        if (index == 0) {
            currentGlobals->errors++;
            return reportError("Invalid array index");
        }
        vector<Value *> array_index;
        array_index.push_back(currentGlobals->Builder->getInt32(0));
        array_index.push_back(index);
        V = currentGlobals->Builder->CreateGEP(V, array_index, var + "_Index");
        return V;
    }
}
