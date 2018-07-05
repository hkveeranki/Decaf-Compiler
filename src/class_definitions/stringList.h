//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_STRINGLIST_H
#define DECAF_COMPILER_STRINGLIST_H

#include <string>
#include <vector>

class stringList {
private:
    std::vector<std::string> list; /* class to store vector of strings */
public:
    stringList() = default;

    void push_back(std::string);

    std::vector<std::string> getList();
};

#endif
