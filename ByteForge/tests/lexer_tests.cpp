#include <iostream>
#include <vector>
#include <cassert>

#include "../src/compiler/lexer.h"

using namespace bf;

int main()
{
    std::string source = "let x = 10; print(x); while (x > 0) { x = x - 1; }";
    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    assert(!tokens.empty());
    assert(tokens[0].type == TokenType::Let);
    assert(tokens[1].type == TokenType::Identifier);
    assert(tokens[2].type == TokenType::Equal);
    assert(tokens[3].type == TokenType::Number);
    assert(tokens[4].type == TokenType::Semicolon);

    bool foundWhile = false;
    bool foundPrint = false;

    for (const auto& token : tokens)
    {
        if (token.type == TokenType::While)
            foundWhile = true;
        if (token.type == TokenType::Print)
            foundPrint = true;
    }

    assert(foundWhile);
    assert(foundPrint);

    std::cout << "Lexer tests passed" << std::endl;
    return 0;
}
