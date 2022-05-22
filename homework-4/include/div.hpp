#pragma once

#include "astnode.hpp"
#include <string.h>

class Div : public ASTNode {
    public:
        Div(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
};