#include "lexer.h"
#include <cctype>
#include <stdexcept>

namespace bf
{
    Lexer::Lexer(const std::string& source)
        : source(source), position(0), line(1), column(1)
    {
    }

    std::vector<Token> Lexer::tokenize()
    {
        std::vector<Token> tokens;

        while (!isAtEnd())
        {
            skipWhitespace();

            if (isAtEnd())
                break;

            char c = peek();

            if (std::isalpha(c) || c == '_')
            {
                tokens.push_back(identifier());
            }
            else if (std::isdigit(c))
            {
                tokens.push_back(number());
            }
            else
            {
                tokens.push_back(symbol());
            }
        }

        tokens.push_back(Token{TokenType::EndOfFile, "", line, column});
        return tokens;
    }

    bool Lexer::isAtEnd() const
    {
        return position >= source.size();
    }

    char Lexer::peek() const
    {
        return source[position];
    }

    char Lexer::advance()
    {
        char c = source[position++];
        if (c == '\n')
        {
            line++;
            column = 1;
        }
        else
        {
            column++;
        }
        return c;
    }

    void Lexer::skipWhitespace()
    {
        while (!isAtEnd())
        {
            char c = peek();
            if (c == ' ' || c == '\r' || c == '\t')
            {
                advance();
            }
            else if (c == '\n')
            {
                advance();
            }
            else
            {
                break;
            }
        }
    }

    Token Lexer::identifier()
    {
        int startCol = column;
        std::string value;

        while (!isAtEnd() && (std::isalnum(peek()) || peek() == '_'))
        {
            value += advance();
        }

        TokenType type = TokenType::Identifier;

        if (value == "let") type = TokenType::Let;
        else if (value == "print") type = TokenType::Print;
        else if (value == "while") type = TokenType::While;
        else if (value == "if") type = TokenType::If;
        else if (value == "else") type = TokenType::Else;

        return Token{type, value, line, startCol};
    }

    Token Lexer::number()
    {
        int startCol = column;
        std::string value;

        while (!isAtEnd() && std::isdigit(peek()))
        {
            value += advance();
        }

        return Token{TokenType::Number, value, line, startCol};
    }

    Token Lexer::symbol()
    {
        int startCol = column;
        char c = advance();

        switch (c)
        {
            case '+': return Token{TokenType::Plus, "+", line, startCol};
            case '-': return Token{TokenType::Minus, "-", line, startCol};
            case '*': return Token{TokenType::Star, "*", line, startCol};
            case '/': return Token{TokenType::Slash, "/", line, startCol};
            case '=':
                if (!isAtEnd() && peek() == '=')
                {
                    advance();
                    return Token{TokenType::EqualEqual, "==", line, startCol};
                }
                return Token{TokenType::Equal, "=", line, startCol};
            case '>': return Token{TokenType::Greater, ">", line, startCol};
            case '<': return Token{TokenType::Less, "<", line, startCol};
            case '(': return Token{TokenType::LeftParen, "(", line, startCol};
            case ')': return Token{TokenType::RightParen, ")", line, startCol};
            case '{': return Token{TokenType::LeftBrace, "{", line, startCol};
            case '}': return Token{TokenType::RightBrace, "}", line, startCol};
            case ';': return Token{TokenType::Semicolon, ";", line, startCol};
            default:
                throw std::runtime_error("Unexpected character: " + std::string(1, c));
        }
    }
}
