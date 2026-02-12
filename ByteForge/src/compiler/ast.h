#ifndef BYTEFORGE_AST_H
#define BYTEFORGE_AST_H

#include <memory>
#include <string>
#include <vector>

#include "lexer.h"

namespace bf
{
    struct Expression
    {
        virtual ~Expression();
    };

    struct Statement
    {
        virtual ~Statement();
    };

    struct Program
    {
        Program();
        std::vector<std::unique_ptr<Statement>> statements;
    };

    struct NumberExpr : public Expression
    {
        std::string value;
        explicit NumberExpr(const std::string& value);
    };

    struct VariableExpr : public Expression
    {
        std::string name;
        explicit VariableExpr(const std::string& name);
    };

    struct BinaryExpr : public Expression
    {
        std::unique_ptr<Expression> left;
        TokenType op;
        std::unique_ptr<Expression> right;

        BinaryExpr(std::unique_ptr<Expression> left, TokenType op, std::unique_ptr<Expression> right);
    };

    struct VarDecl : public Statement
    {
        std::string name;
        std::unique_ptr<Expression> initializer;

        VarDecl(const std::string& name, std::unique_ptr<Expression> initializer);
    };

    struct PrintStmt : public Statement
    {
        std::unique_ptr<Expression> expression;

        explicit PrintStmt(std::unique_ptr<Expression> expression);
    };

    struct ExprStmt : public Statement
    {
        std::unique_ptr<Expression> expression;

        explicit ExprStmt(std::unique_ptr<Expression> expression);
    };

    struct BlockStmt : public Statement
    {
        BlockStmt();
        std::vector<std::unique_ptr<Statement>> statements;
    };

    struct WhileStmt : public Statement
    {
        std::unique_ptr<Expression> condition;
        std::unique_ptr<BlockStmt> body;

        WhileStmt(std::unique_ptr<Expression> condition, std::unique_ptr<BlockStmt> body);
    };

    struct IfStmt : public Statement
    {
        std::unique_ptr<Expression> condition;
        std::unique_ptr<BlockStmt> thenBranch;
        std::unique_ptr<BlockStmt> elseBranch;

        IfStmt(std::unique_ptr<Expression> condition,
               std::unique_ptr<BlockStmt> thenBranch,
               std::unique_ptr<BlockStmt> elseBranch);
    };
}

#endif
