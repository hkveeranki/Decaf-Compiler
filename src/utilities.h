//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_UTILITIES_H
#define DECAF_COMPILER_UTILITIES_H

#include <bits/stdc++.h>

using namespace std;

string getOperation(string opr) {
    if (opr.compare("+") == 0) {
        return string("Addition");
    } else if (opr.compare("-") == 0) {
        return string("Subtraction");
    } else if (opr.compare("*") == 0) {
        return string("Multiplication");
    } else if (opr.compare("/") == 0) {
        return string("Division");
    } else if (opr.compare("%") == 0) {
        return string("Modulus");
    } else if (opr.compare("<") == 0) {
        return string("Less_than");
    } else if (opr.compare(">") == 0) {
        return string("Greater_than");
    } else if (opr.compare("<=") == 0) {
        return string("Less_than_Equal_to");
    } else if (opr.compare(">=") == 0) {
        return string("Greater_than_Equal_to");
    } else if (opr.compare("==") == 0) {
        return string("Compare_equal");
    } else if (opr.compare("&&") == 0) {
        return string("Conditional_and");
    } else if (opr.compare("||") == 0) {
        return string("Conditional_or");
    } else if (opr.compare("=") == 0) {
        return string("Equal_assign");
    } else if (opr.compare("-=") == 0) {
        return string("Subequal_assign");
    } else if (opr.compare("=") == 0) {
        return string("Addequal_assign");
    }
}

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

void printTabs(int tabs_needed, ofstream& out) {
    const int tab_width = 4;
    for (int i = 0; i < tabs_needed; i++) {
        for (int j = 0; j < tab_width; j++)
            out << " ";
    }
}

#endif //DECAF_COMPILER_UTILITIES_H
