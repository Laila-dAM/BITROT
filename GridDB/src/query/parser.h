#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "token.h"

struct ASTNode {
    std::string type;
    std::string value;
    std::vector<ASTNode> children;
};

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    ASTNode parse();
private:
    std::vector<Token> tokens_;
    size_t pos_;
    Token peek() const;
    Token get();
    ASTNode parseStatement();
};

#endif