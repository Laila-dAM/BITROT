#include <iostream>
#include <cassert>
#include <memory>

#include "../src/compiler/lexer.h"
#include "../src/compiler/parser.h"
#include "../src/compiler/ast.h"

using namespace bf;

int main()
{
    std::string source = "let x = 5; print(x);";
    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    std::unique_ptr<Program> program = parser.parse();

    assert(program != nullptr);
    assert(program->statements.size() == 2);

    auto* varDecl = dynamic_cast<VarDecl*>(program->statements[0].get());
    assert(varDecl != nullptr);
    assert(varDecl->name == "x");

    auto* printStmt = dynamic_cast<PrintStmt*>(program->statements[1].get());
    assert(printStmt != nullptr);

    std::cout << "Parser tests passed" << std::endl;
    return 0;
}
