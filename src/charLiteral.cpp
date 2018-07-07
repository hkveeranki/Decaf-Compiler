/**
 * Implementation of the \ref  charLiteral class
 */

#include "charLiteral.h"

/**
 * Constructor for the class
 * @param val value of the character literal given as string
 */
charLiteral::charLiteral(std::string val) {
    this->value = val[0];
    this->ltype = literalType::Char;
}
