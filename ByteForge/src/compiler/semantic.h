#ifndef BYTEFORGE_SEMANTIC_H
#define BYTEFORGE_SEMANTIC_H

#include <unordered_map>
#include <string>

#include "ast.h"

namespace bf
{
    class SemanticAnalyzer
    {
    public:
        void analyze(Program* program);

    private:
        std::unordered_map<std::string, bool> symbols;

        void analyzeStatement(Statement* stmt);
        void analyzeExpression(Expression* expr);
    };
}

#endif
