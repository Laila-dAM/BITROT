#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& input) : input_(input), pos_(0), line_(1), column_(1) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos_ < input_.size()) {
        skipWhitespace();
        if (pos_ >= input_.size()) break;
        char c = peek();
        if (isalpha(c) || c == '_') {
            tokens.push_back(readIdentifierOrKeyword());
        } else if (isdigit(c)) {
            tokens.push_back(readNumber());
        } else if (c == '\'' || c == '"') {
            tokens.push_back(readString());
        } else {
            Token token;
            token.line = line_;
            token.column = column_;
            switch (c) {
                case '(': token.type = TokenType::LEFT_PAREN; break;
                case ')': token.type = TokenType::RIGHT_PAREN; break;
                case ',': token.type = TokenType::COMMA; break;
                case ';': token.type = TokenType::SEMICOLON; break;
                default: token.type = TokenType::UNKNOWN; break;
            }
            token.value = c;
            get();
            tokens.push_back(token);
        }
    }
    tokens.push_back({TokenType::END_OF_FILE, "", line_, column_});
    return tokens;
}

char Lexer::peek() const { return input_[pos_]; }

char Lexer::get() { char c = input_[pos_]; pos_++; column_++; return c; }

void Lexer::skipWhitespace() {
    while (pos_ < input_.size() && isspace(peek())) {
        if (peek() == '\n') { line_++; column_ = 1; } else { column_++; }
        pos_++;
    }
}

Token Lexer::readIdentifierOrKeyword() {
    size_t start = pos_;
    size_t startColumn = column_;
    while (pos_ < input_.size() && (isalnum(peek()) || peek() == '_')) get();
    std::string word = input_.substr(start, pos_ - start);
    Token token;
    token.value = word;
    token.line = line_;
    token.column = startColumn;
    if (word == "CREATE") token.type = TokenType::CREATE;
    else if (word == "TABLE") token.type = TokenType::TABLE;
    else if (word == "INSERT") token.type = TokenType::INSERT;
    else if (word == "INTO") token.type = TokenType::INTO;
    else if (word == "VALUES") token.type = TokenType::VALUES;
    else if (word == "SELECT") token.type = TokenType::SELECT;
    else if (word == "FROM") token.type = TokenType::FROM;
    else if (word == "DELETE") token.type = TokenType::DELETE;
    else if (word == "WHERE") token.type = TokenType::WHERE;
    else token.type = TokenType::IDENTIFIER;
    return token;
}

Token Lexer::readNumber() {
    size_t start = pos_;
    size_t startColumn = column_;
    bool isFloat = false;
    while (pos_ < input_.size() && (isdigit(peek()) || peek() == '.')) {
        if (peek() == '.') isFloat = true;
        get();
    }
    std::string value = input_.substr(start, pos_ - start);
    Token token;
    token.value = value;
    token.line = line_;
    token.column = startColumn;
    token.type = isFloat ? TokenType::FLOAT_LITERAL : TokenType::INT_LITERAL;
    return token;
}

Token Lexer::readString() {
    char quote = get();
    size_t startColumn = column_;
    size_t start = pos_;
    while (pos_ < input_.size() && peek() != quote) get();
    std::string value = input_.substr(start, pos_ - start);
    get();
    Token token;
    token.value = value;
    token.line = line_;
    token.column = startColumn;
    token.type = TokenType::STRING_LITERAL;
    return token;
}