#include <iostream>
#include <cassert>
#include <memory>
#include <string>

#include "../src/compiler/lexer.h"
#include "../src/compiler/parser.h"
#include "../src/compiler/codegen.h"

using namespace bf;

int main()
{
    std::string source = "let x = 2 + 3; print(x);";
    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    std::unique_ptr<Program> program = parser.parse();

    CodeGenerator generator;
    std::string assembly = generator.generate(program.get());

    assert(!assembly.empty());
    assert(assembly.find("mov rax") != std::string::npos);
    assert(assembly.find("push rax") != std::string::npos);

    std::cout << "Code generation tests passed" << std::endl;
    return 0;
}
