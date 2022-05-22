#include "add.hpp"
#include "div.hpp"
#include "mul.hpp"
#include "sub.hpp"

Add::Add(const std::string& var, ASTNode* lhs, ASTNode* rhs) : ASTNode{var, lhs, rhs}{};

Div::Div(const std::string& var, ASTNode* lhs, ASTNode* rhs) : ASTNode{var, lhs, rhs}{};

Mul::Mul(const std::string& var, ASTNode* lhs, ASTNode* rhs) : ASTNode{var, lhs, rhs}{};

Sub::Sub(const std::string& var, ASTNode* lhs, ASTNode* rhs) : ASTNode{var, lhs, rhs}{};