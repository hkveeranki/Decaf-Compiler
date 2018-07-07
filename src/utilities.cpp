/**
 * Implementation of \ref utility functions
 */

#include "utilities.h"

using namespace std;
using namespace llvm;

/**
 * Replace newline characters in a string
 * @param str string to be modified
 * @return modified string in which new line characters are removed
 */
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
/**
 * Report error to the stderr
 * @param error_str name of the error to be reported
 */
llvm::Value *reportError(string error_str) {
    cerr << error_str << endl;
    return nullptr;
}