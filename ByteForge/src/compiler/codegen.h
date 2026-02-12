#ifndef BYTEFORGE_CODEGEN_H
#define BYTEFORGE_CODEGEN_H

#include <string>
#include <unordered_map>

#include "ast.h"

namespace bf
{
    class CodeGenerator
    {
    public:
        CodeGenerator();
        std::string generate(Program* program);

    private:
        std::string output;
        std::unordered_map<std::string, int> variables;
        int labelCounter;
        int stackOffset;

        void generateStatement(Statement* stmt);
        void generateExpression(Expression* expr);
        void emit(const std::string& instruction);
        std::string newLabel();
    };
}

#endif
