/**
 * Class to deal with list of strings in the parser
 */

#ifndef DECAF_COMPILER_STRINGLIST_H
#define DECAF_COMPILER_STRINGLIST_H

#include <string>
#include <vector>

class stringList {
private:
    /* list of of strings */
    std::vector<std::string> list;
public:
    stringList() = default;

    void push_back(std::string);

    std::vector<std::string> getList();
};

#endif
