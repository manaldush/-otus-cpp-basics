#pragma once

#include <string.h>
#include "astnode.hpp"

class Add : public ASTNode {
    public:
       Add(const std::string& var, ASTNode* lhs, ASTNode* rhs);
};