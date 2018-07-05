//
// Created by harry7 on 7/4/18.
//

#include "utilities.h"
#include "common.h"
#include "globals.h"

using namespace std;
using namespace llvm;
string replace_newline(string str) {
    size_t index = 0;
    string search = "\\n";
//  cout << "Called replace for " << str << endl;
    while (true) {
        /* Locate the substring to replace. */
        index = str.find(search, index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        //  cout << "Replaced\n";
        str.erase(index, search.length());
        str.insert(index, "\n");

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 1;
    }
    return str;
}

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, string VarName, std::string type, globals* currentGlobals) {

    /* Allocates memory for local variables  on the stack of the function */
    /* Get the builder for current context */
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *Alloca = nullptr;
    if (type == "int") {
        Alloca = TmpB.CreateAlloca(Type::getInt32Ty(currentGlobals->Context), 0, VarName);
    } else if (type == "boolean") {
        Alloca = TmpB.CreateAlloca(Type::getInt1Ty(currentGlobals->Context), 0, VarName);
    }
    return Alloca;
}