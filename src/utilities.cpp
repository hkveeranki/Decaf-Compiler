//
// Created by harry7 on 7/4/18.
//

#include "utilities.h"
#include "globals.h"

using namespace std;
using namespace llvm;

string replace_newline(string str) {
    size_t index = 0;
    string search = "\\n";
    while (true) {
        /* Locate the substring to replace. */
        index = str.find(search, index);
        if (index == std::string::npos) break;
        /* Make the replacement. */
        str.erase(index, search.length());
        str.insert(index, "\n");
        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 1;
    }
    return str;
}

llvm::Value *reportError(string str) {
    cerr << str << endl;
    return nullptr;
}