package tokio.lexer;

import java.util.Map;
import java.util.HashMap;

public enum TokenType {
    // Symbols
    PLUS, MINUS, STAR, SLASH,
    LPAREN, RPAREN, LBRACE, RBRACE,
    SEMICOLON, EQUAL, EQEQ, BANG, BANGEQ,
    LT, LTEQ, GT, GTEQ, COMMA,

    // Literals
    NUMBER, STRING, IDENTIFIER,

    // Keywords
    IF, ELSE, WHILE, FOR, FUNCTION, RETURN, VAR, TRUE, FALSE,

    // End of file
    EOF;

    // Keywords lookup map
    public static final Map<String, TokenType> KEYWORDS = new HashMap<>();

    static {
        KEYWORDS.put("if", IF);
        KEYWORDS.put("else", ELSE);
        KEYWORDS.put("while", WHILE);
        KEYWORDS.put("for", FOR);
        KEYWORDS.put("function", FUNCTION);
        KEYWORDS.put("return", RETURN);
        KEYWORDS.put("var", VAR);
        KEYWORDS.put("true", TRUE);
        KEYWORDS.put("false", FALSE);
    }
}
