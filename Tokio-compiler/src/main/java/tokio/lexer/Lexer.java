package tokio.lexer;

import java.util.ArrayList;
import java.util.List;
import tokio.exceptions.LexerException;

public class Lexer {
    private final String source;
    private final List<Token> tokens;
    private int pos;
    private int line;
    private int column;

    public Lexer(String source) {
        this.source = source;
        this.tokens = new ArrayList<>();
        this.pos = 0;
        this.line = 1;
        this.column = 1;
    }

    public List<Token> tokenize() throws LexerException {
        while (!isAtEnd()) {
            char current = peek();
            switch (current) {
                case ' ':
                case '\r':
                case '\t':
                    advance();
                    break;
                case '\n':
                    advance();
                    line++;
                    column = 1;
                    break;
                case '+':
                    addToken(TokenType.PLUS);
                    advance();
                    break;
                case '-':
                    addToken(TokenType.MINUS);
                    advance();
                    break;
                case '*':
                    addToken(TokenType.STAR);
                    advance();
                    break;
                case '/':
                    addToken(TokenType.SLASH);
                    advance();
                    break;
                case '(':
                    addToken(TokenType.LPAREN);
                    advance();
                    break;
                case ')':
                    addToken(TokenType.RPAREN);
                    advance();
                    break;
                case '{':
                    addToken(TokenType.LBRACE);
                    advance();
                    break;
                case '}':
                    addToken(TokenType.RBRACE);
                    advance();
                    break;
                case ';':
                    addToken(TokenType.SEMICOLON);
                    advance();
                    break;
                case '=':
                    if (match('=')) {
                        addToken(TokenType.EQEQ);
                    } else {
                        addToken(TokenType.EQUAL);
                    }
                    break;
                case '!':
                    if (match('=')) {
                        addToken(TokenType.BANGEQ);
                    } else {
                        addToken(TokenType.BANG);
                    }
                    break;
                case '<':
                    addToken(match('=') ? TokenType.LTEQ : TokenType.LT);
                    break;
                case '>':
                    addToken(match('=') ? TokenType.GTEQ : TokenType.GT);
                    break;
                case '"':
                    string();
                    break;
                default:
                    if (isDigit(current)) {
                        number();
                    } else if (isAlpha(current)) {
                        identifier();
                    } else {
                        throw new LexerException("Unexpected character: " + current + " at line " + line + ", column " + column);
                    }
            }
        }
        addToken(TokenType.EOF);
        return tokens;
    }

    private void addToken(TokenType type) {
        tokens.add(new Token(type, null, line, column));
    }

    private void addToken(TokenType type, String lexeme) {
        tokens.add(new Token(type, lexeme, line, column));
    }

    private char advance() {
        pos++;
        column++;
        return source.charAt(pos - 1);
    }

    private boolean match(char expected) {
        if (isAtEnd()) return false;
        if (source.charAt(pos) != expected) return false;
        advance();
        return true;
    }

    private char peek() {
        if (isAtEnd()) return '\0';
        return source.charAt(pos);
    }

    private boolean isAtEnd() {
        return pos >= source.length();
    }

    private void string() throws LexerException {
        int start = pos + 1;
        while (!isAtEnd() && peek() != '"') {
            if (peek() == '\n') {
                line++;
                column = 1;
            }
            advance();
        }
        if (isAtEnd()) {
            throw new LexerException("Unterminated string at line " + line + ", column " + column);
        }
        advance();
        String value = source.substring(start, pos - 1);
        addToken(TokenType.STRING, value);
    }

    private void number() {
        int start = pos;
        while (!isAtEnd() && isDigit(peek())) advance();
        if (!isAtEnd() && peek() == '.') {
            advance();
            while (!isAtEnd() && isDigit(peek())) advance();
        }
        String value = source.substring(start, pos);
        addToken(TokenType.NUMBER, value);
    }

    private void identifier() {
        int start = pos;
        while (!isAtEnd() && isAlphaNumeric(peek())) advance();
        String value = source.substring(start, pos);
        TokenType type = TokenType.KEYWORDS.getOrDefault(value, TokenType.IDENTIFIER);
        addToken(type, value);
    }

    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    private boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }

    private boolean isAlphaNumeric(char c) {
        return isAlpha(c) || isDigit(c);
    }
}
