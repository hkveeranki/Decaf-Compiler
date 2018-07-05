//
// Created by harry7 on 7/4/18.
//

#include <string>
#include <vector>
#include "stringList.h"


void stringList::push_back(std::string var) {
    list.push_back(var);
}

std::vector<std::string> stringList::getList() {
    return this->list;
}
