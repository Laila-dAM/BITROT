#include "semantic.h"
#include "errors.h"

namespace bf
{
    void SemanticAnalyzer::analyze(Program* program)
    {
        for (const auto& stmt : program->statements)
        {
            analyzeStatement(stmt.get());
        }
    }

    void SemanticAnalyzer::analyzeStatement(Statement* stmt)
    {
        if (auto varDecl = dynamic_cast<VarDecl*>(stmt))
        {
            analyzeExpression(varDecl->initializer.get());
            if (symbols.count(varDecl->name))
                throw CompilerError("Variable already declared: " + varDecl->name);
            symbols[varDecl->name] = true;
        }
        else if (auto printStmt = dynamic_cast<PrintStmt*>(stmt))
        {
            analyzeExpression(printStmt->expression.get());
        }
        else if (auto exprStmt = dynamic_cast<ExprStmt*>(stmt))
        {
            analyzeExpression(exprStmt->expression.get());
        }
        else if (auto block = dynamic_cast<BlockStmt*>(stmt))
        {
            for (const auto& s : block->statements)
            {
                analyzeStatement(s.get());
            }
        }
        else if (auto whileStmt = dynamic_cast<WhileStmt*>(stmt))
        {
            analyzeExpression(whileStmt->condition.get());
            analyzeStatement(whileStmt->body.get());
        }
        else if (auto ifStmt = dynamic_cast<IfStmt*>(stmt))
        {
            analyzeExpression(ifStmt->condition.get());
            analyzeStatement(ifStmt->thenBranch.get());
            if (ifStmt->elseBranch)
                analyzeStatement(ifStmt->elseBranch.get());
        }
    }

    void SemanticAnalyzer::analyzeExpression(Expression* expr)
    {
        if (auto binary = dynamic_cast<BinaryExpr*>(expr))
        {
            analyzeExpression(binary->left.get());
            analyzeExpression(binary->right.get());
        }
        else if (auto variable = dynamic_cast<VariableExpr*>(expr))
        {
            if (!symbols.count(variable->name))
                throw CompilerError("Undeclared variable: " + variable->name);
        }
        else if (dynamic_cast<NumberExpr*>(expr))
        {
            return;
        }
    }
}
