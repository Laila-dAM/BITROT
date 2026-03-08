#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    CREATE,
    TABLE,
    INSERT,
    INTO,
    VALUES,
    SELECT,
    FROM,
    DELETE,
    WHERE,
    IDENTIFIER,
    INT_LITERAL,
    FLOAT_LITERAL,
    STRING_LITERAL,
    BOOL_LITERAL,
    COMMA,
    SEMICOLON,
    LEFT_PAREN,
    RIGHT_PAREN,
    OPERATOR,
    END_OF_FILE,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
    size_t line;
    size_t column;
};

#endif