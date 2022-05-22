#pragma once

#include <string.h>
#include "astnode.hpp"

class Variable : public ASTNode {
    public:
       Variable(std::string var) : ASTNode{var}{}
};