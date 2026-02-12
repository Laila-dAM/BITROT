#include "parser.h"
#include "errors.h"

namespace bf
{
    Parser::Parser(const std::vector<Token>& tokens)
        : tokens(tokens), current(0)
    {
    }

    std::unique_ptr<Program> Parser::parse()
    {
        auto program = std::make_unique<Program>();

        while (!isAtEnd())
        {
            program->statements.push_back(statement());
        }

        return program;
    }

    std::unique_ptr<Statement> Parser::statement()
    {
        if (match(TokenType::Let)) return variableDeclaration();
        if (match(TokenType::Print)) return printStatement();
        if (match(TokenType::While)) return whileStatement();
        if (match(TokenType::If)) return ifStatement();

        return expressionStatement();
    }

    std::unique_ptr<Statement> Parser::variableDeclaration()
    {
        Token name = consume(TokenType::Identifier, "Expected variable name");
        consume(TokenType::Equal, "Expected '=' after variable name");
        auto value = expression();
        consume(TokenType::Semicolon, "Expected ';' after declaration");

        return std::make_unique<VarDecl>(name.lexeme, std::move(value));
    }

    std::unique_ptr<Statement> Parser::printStatement()
    {
        consume(TokenType::LeftParen, "Expected '(' after print");
        auto value = expression();
        consume(TokenType::RightParen, "Expected ')'");
        consume(TokenType::Semicolon, "Expected ';' after print");

        return std::make_unique<PrintStmt>(std::move(value));
    }

    std::unique_ptr<Statement> Parser::whileStatement()
    {
        consume(TokenType::LeftParen, "Expected '(' after while");
        auto condition = expression();
        consume(TokenType::RightParen, "Expected ')'");
        auto body = block();

        return std::make_unique<WhileStmt>(std::move(condition), std::move(body));
    }

    std::unique_ptr<Statement> Parser::ifStatement()
    {
        consume(TokenType::LeftParen, "Expected '(' after if");
        auto condition = expression();
        consume(TokenType::RightParen, "Expected ')'");
        auto thenBranch = block();

        std::unique_ptr<BlockStmt> elseBranch = nullptr;

        if (match(TokenType::Else))
        {
            elseBranch = block();
        }

        return std::make_unique<IfStmt>(std::move(condition), std::move(thenBranch), std::move(elseBranch));
    }

    std::unique_ptr<BlockStmt> Parser::block()
    {
        consume(TokenType::LeftBrace, "Expected '{'");
        auto blockStmt = std::make_unique<BlockStmt>();

        while (!check(TokenType::RightBrace) && !isAtEnd())
        {
            blockStmt->statements.push_back(statement());
        }

        consume(TokenType::RightBrace, "Expected '}'");
        return blockStmt;
    }

    std::unique_ptr<Statement> Parser::expressionStatement()
    {
        auto expr = expression();
        consume(TokenType::Semicolon, "Expected ';' after expression");
        return std::make_unique<ExprStmt>(std::move(expr));
    }

    std::unique_ptr<Expression> Parser::expression()
    {
        return equality();
    }

    std::unique_ptr<Expression> Parser::equality()
    {
        auto expr = comparison();

        while (match(TokenType::EqualEqual))
        {
            Token op = previous();
            auto right = comparison();
            expr = std::make_unique<BinaryExpr>(std::move(expr), op.type, std::move(right));
        }

        return expr;
    }

    std::unique_ptr<Expression> Parser::comparison()
    {
        auto expr = term();

        while (match(TokenType::Greater) || match(TokenType::Less))
        {
            Token op = previous();
            auto right = term();
            expr = std::make_unique<BinaryExpr>(std::move(expr), op.type, std::move(right));
        }

        return expr;
    }

    std::unique_ptr<Expression> Parser::term()
    {
        auto expr = factor();

        while (match(TokenType::Plus) || match(TokenType::Minus))
        {
            Token op = previous();
            auto right = factor();
            expr = std::make_unique<BinaryExpr>(std::move(expr), op.type, std::move(right));
        }

        return expr;
    }

    std::unique_ptr<Expression> Parser::factor()
    {
        auto expr = primary();

        while (match(TokenType::Star) || match(TokenType::Slash))
        {
            Token op = previous();
            auto right = primary();
            expr = std::make_unique<BinaryExpr>(std::move(expr), op.type, std::move(right));
        }

        return expr;
    }

    std::unique_ptr<Expression> Parser::primary()
    {
        if (match(TokenType::Number))
        {
            return std::make_unique<NumberExpr>(previous().lexeme);
        }

        if (match(TokenType::Identifier))
        {
            return std::make_unique<VariableExpr>(previous().lexeme);
        }

        if (match(TokenType::LeftParen))
        {
            auto expr = expression();
            consume(TokenType::RightParen, "Expected ')'");
            return expr;
        }

        throw CompilerError("Unexpected token");
    }

    bool Parser::match(TokenType type)
    {
        if (check(type))
        {
            advance();
            return true;
        }
        return false;
    }

    bool Parser::check(TokenType type) const
    {
        if (isAtEnd()) return false;
        return peek().type == type;
    }

    const Token& Parser::advance()
    {
        if (!isAtEnd()) current++;
        return previous();
    }

    bool Parser::isAtEnd() const
    {
        return peek().type == TokenType::EndOfFile;
    }

    const Token& Parser::peek() const
    {
        return tokens[current];
    }

    const Token& Parser::previous() const
    {
        return tokens[current - 1];
    }

    Token Parser::consume(TokenType type, const std::string& message)
    {
        if (check(type)) return advance();
        throw CompilerError(message);
    }
}
