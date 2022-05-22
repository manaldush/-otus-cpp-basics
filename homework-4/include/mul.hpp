#pragma once

#include "astnode.hpp"
#include <string.h>

class Mul : public ASTNode {
    public:
        Mul(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
};