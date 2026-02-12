#include <iostream>
#include <memory>
#include <string>

#include "compiler/lexer.h"
#include "compiler/parser.h"
#include "compiler/semantic.h"
#include "compiler/codegen.h"
#include "utils/file_utils.h"
#include "compiler/errors.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: byteforge <source_file.bf>" << std::endl;
        return 1;
    }

    std::string inputPath = argv[1];
    std::string source;

    try
    {
        source = bf::readFile(inputPath);
    }
    catch (const std::exception& e)
    {
        std::cerr << "File error: " << e.what() << std::endl;
        return 1;
    }

    try
    {
        bf::Lexer lexer(source);
        auto tokens = lexer.tokenize();

        bf::Parser parser(tokens);
        auto ast = parser.parse();

        bf::SemanticAnalyzer semantic;
        semantic.analyze(ast.get());

        bf::CodeGenerator codegen;
        std::string assembly = codegen.generate(ast.get());

        std::string outputAsm = "build/bin/output.asm";
        bf::writeFile(outputAsm, assembly);

        std::cout << "Compilation successful." << std::endl;
        std::cout << "Assembly written to: " << outputAsm << std::endl;
    }
    catch (const bf::CompilerError& e)
    {
        std::cerr << "Compilation error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
