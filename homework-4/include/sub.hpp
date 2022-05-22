#pragma once

#include "astnode.hpp"
#include "string.h"

class Sub : public ASTNode {
    public:
        Sub(const std::string& var, ASTNode* lhs, ASTNode* rhs);
};