//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_COMMON_H
#define DECAF_COMPILER_COMMON_H

#include <iostream>
#include <string>
#include <llvm/IR/Value.h>

using namespace std;


class reportError {
    /* Class for error handling */
public:
    static llvm::Value *ErrorV(string str) {
        cerr << str << endl;
        return 0;
    }
};

#endif //DECAF_COMPILER_COMMON_H

