#ifndef BYTEFORGE_LEXER_H
#define BYTEFORGE_LEXER_H

#include <string>
#include <vector>

namespace bf
{
    enum class TokenType
    {
        Identifier,
        Number,

        Let,
        Print,
        While,
        If,
        Else,

        Plus,
        Minus,
        Star,
        Slash,

        Equal,
        EqualEqual,
        Greater,
        Less,

        LeftParen,
        RightParen,
        LeftBrace,
        RightBrace,
        Semicolon,

        EndOfFile
    };

    struct Token
    {
        TokenType type;
        std::string lexeme;
        int line;
        int column;
    };

    class Lexer
    {
    public:
        explicit Lexer(const std::string& source);
        std::vector<Token> tokenize();

    private:
        std::string source;
        size_t position;
        int line;
        int column;

        bool isAtEnd() const;
        char peek() const;
        char advance();
        void skipWhitespace();

        Token identifier();
        Token number();
        Token symbol();
    };
}

#endif
