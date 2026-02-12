#include "ast.h"

namespace bf
{
    Program::Program() = default;

    Expression::~Expression() = default;
    Statement::~Statement() = default;

    NumberExpr::NumberExpr(const std::string& value)
        : value(value)
    {
    }

    VariableExpr::VariableExpr(const std::string& name)
        : name(name)
    {
    }

    BinaryExpr::BinaryExpr(std::unique_ptr<Expression> left, TokenType op, std::unique_ptr<Expression> right)
        : left(std::move(left)), op(op), right(std::move(right))
    {
    }

    VarDecl::VarDecl(const std::string& name, std::unique_ptr<Expression> initializer)
        : name(name), initializer(std::move(initializer))
    {
    }

    PrintStmt::PrintStmt(std::unique_ptr<Expression> expression)
        : expression(std::move(expression))
    {
    }

    ExprStmt::ExprStmt(std::unique_ptr<Expression> expression)
        : expression(std::move(expression))
    {
    }

    BlockStmt::BlockStmt() = default;

    WhileStmt::WhileStmt(std::unique_ptr<Expression> condition, std::unique_ptr<BlockStmt> body)
        : condition(std::move(condition)), body(std::move(body))
    {
    }

    IfStmt::IfStmt(std::unique_ptr<Expression> condition,
                   std::unique_ptr<BlockStmt> thenBranch,
                   std::unique_ptr<BlockStmt> elseBranch)
        : condition(std::move(condition)),
          thenBranch(std::move(thenBranch)),
          elseBranch(std::move(elseBranch))
    {
    }
}
