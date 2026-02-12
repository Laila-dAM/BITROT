#ifndef BYTEFORGE_PARSER_H
#define BYTEFORGE_PARSER_H

#include <vector>
#include <memory>
#include <string>

#include "lexer.h"
#include "ast.h"

namespace bf
{
    class Parser
    {
    public:
        explicit Parser(const std::vector<Token>& tokens);
        std::unique_ptr<Program> parse();

    private:
        const std::vector<Token>& tokens;
        size_t current;

        std::unique_ptr<Statement> statement();
        std::unique_ptr<Statement> variableDeclaration();
        std::unique_ptr<Statement> printStatement();
        std::unique_ptr<Statement> whileStatement();
        std::unique_ptr<Statement> ifStatement();
        std::unique_ptr<BlockStmt> block();
        std::unique_ptr<Statement> expressionStatement();

        std::unique_ptr<Expression> expression();
        std::unique_ptr<Expression> equality();
        std::unique_ptr<Expression> comparison();
        std::unique_ptr<Expression> term();
        std::unique_ptr<Expression> factor();
        std::unique_ptr<Expression> primary();

        bool match(TokenType type);
        bool check(TokenType type) const;
        const Token& advance();
        bool isAtEnd() const;
        const Token& peek() const;
        const Token& previous() const;
        Token consume(TokenType type, const std::string& message);
    };
}

#endif
