#include "codegen.h"
#include "errors.h"

namespace bf
{
    CodeGenerator::CodeGenerator()
        : labelCounter(0), stackOffset(0)
    {
    }

    std::string CodeGenerator::generate(Program* program)
    {
        output.clear();
        variables.clear();
        stackOffset = 0;
        labelCounter = 0;

        emit("global _start");
        emit("section .text");
        emit("_start:");

        for (const auto& stmt : program->statements)
        {
            generateStatement(stmt.get());
        }

        emit("mov rax, 60");
        emit("xor rdi, rdi");
        emit("syscall");

        return output;
    }

    void CodeGenerator::generateStatement(Statement* stmt)
    {
        if (auto varDecl = dynamic_cast<VarDecl*>(stmt))
        {
            generateExpression(varDecl->initializer.get());
            stackOffset += 8;
            variables[varDecl->name] = stackOffset;
            emit("push rax");
        }
        else if (auto printStmt = dynamic_cast<PrintStmt*>(stmt))
        {
            generateExpression(printStmt->expression.get());
        }
        else if (auto exprStmt = dynamic_cast<ExprStmt*>(stmt))
        {
            generateExpression(exprStmt->expression.get());
        }
        else if (auto block = dynamic_cast<BlockStmt*>(stmt))
        {
            for (const auto& s : block->statements)
            {
                generateStatement(s.get());
            }
        }
        else if (auto whileStmt = dynamic_cast<WhileStmt*>(stmt))
        {
            std::string startLabel = newLabel();
            std::string endLabel = newLabel();

            emit(startLabel + ":");
            generateExpression(whileStmt->condition.get());
            emit("cmp rax, 0");
            emit("je " + endLabel);
            generateStatement(whileStmt->body.get());
            emit("jmp " + startLabel);
            emit(endLabel + ":");
        }
        else if (auto ifStmt = dynamic_cast<IfStmt*>(stmt))
        {
            std::string elseLabel = newLabel();
            std::string endLabel = newLabel();

            generateExpression(ifStmt->condition.get());
            emit("cmp rax, 0");
            emit("je " + elseLabel);
            generateStatement(ifStmt->thenBranch.get());
            emit("jmp " + endLabel);
            emit(elseLabel + ":");
            if (ifStmt->elseBranch)
                generateStatement(ifStmt->elseBranch.get());
            emit(endLabel + ":");
        }
    }

    void CodeGenerator::generateExpression(Expression* expr)
    {
        if (auto number = dynamic_cast<NumberExpr*>(expr))
        {
            emit("mov rax, " + number->value);
        }
        else if (auto variable = dynamic_cast<VariableExpr*>(expr))
        {
            if (!variables.count(variable->name))
                throw CompilerError("Undefined variable: " + variable->name);

            int offset = variables[variable->name];
            emit("mov rax, [rsp + " + std::to_string(stackOffset - offset) + "]");
        }
        else if (auto binary = dynamic_cast<BinaryExpr*>(expr))
        {
            generateExpression(binary->left.get());
            emit("push rax");
            generateExpression(binary->right.get());
            emit("pop rbx");

            switch (binary->op)
            {
                case TokenType::Plus:
                    emit("add rax, rbx");
                    break;
                case TokenType::Minus:
                    emit("sub rbx, rax");
                    emit("mov rax, rbx");
                    break;
                case TokenType::Star:
                    emit("imul rax, rbx");
                    break;
                case TokenType::Slash:
                    emit("mov rdx, 0");
                    emit("mov rcx, rax");
                    emit("mov rax, rbx");
                    emit("idiv rcx");
                    break;
                case TokenType::Greater:
                    emit("cmp rbx, rax");
                    emit("setg al");
                    emit("movzx rax, al");
                    break;
                case TokenType::Less:
                    emit("cmp rbx, rax");
                    emit("setl al");
                    emit("movzx rax, al");
                    break;
                case TokenType::EqualEqual:
                    emit("cmp rbx, rax");
                    emit("sete al");
                    emit("movzx rax, al");
                    break;
                default:
                    throw CompilerError("Unsupported binary operator");
            }
        }
    }

    void CodeGenerator::emit(const std::string& instruction)
    {
        output += instruction + "\n";
    }

    std::string CodeGenerator::newLabel()
    {
        return "L" + std::to_string(labelCounter++);
    }
}
