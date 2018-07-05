//
// Created by harry7 on 7/4/18.
//

#include "charLiteral.h"

charLiteral::charLiteral(std::string val) {
    this->value = val[0];
    this->ltype = literalType::Char;
}
