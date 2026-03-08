#include "parser.h"

Parser::Parser(const std::vector<Token>& tokens) : tokens_(tokens), pos_(0) {}

ASTNode Parser::parse() {
    ASTNode root{"Program", "", {}};
    while (peek().type != TokenType::END_OF_FILE) {
        root.children.push_back(parseStatement());
    }
    return root;
}

ASTNode Parser::parseStatement() {
    Token token = get();
    ASTNode node;
    node.type = "Statement";
    node.value = token.value;
    return node;
}

Token Parser::peek() const {
    if (pos_ < tokens_.size()) return tokens_[pos_];
    return tokens_.back();
}

Token Parser::get() {
    if (pos_ < tokens_.size()) return tokens_[pos_++];
    return tokens_.back();
}