#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

class Lexer {
public:
    Lexer(const std::string& input);
    std::vector<Token> tokenize();
private:
    std::string input_;
    size_t pos_;
    size_t line_;
    size_t column_;
    char peek() const;
    char get();
    void skipWhitespace();
    Token readIdentifierOrKeyword();
    Token readNumber();
    Token readString();
};

#endif