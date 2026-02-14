package tokio;

import org.junit.jupiter.api.Test;
import tokio.lexer.Lexer;
import tokio.lexer.Token;
import tokio.lexer.TokenType;
import tokio.exceptions.LexerException;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class LexerTest {

    @Test
    public void testSimpleTokens() throws LexerException {
        String source = "var x = 10 + 20;";
        Lexer lexer = new Lexer(source);
        List<Token> tokens = lexer.tokenize();

        assertEquals(TokenType.VAR, tokens.get(0).getType());
        assertEquals("x", tokens.get(1).getValue());
        assertEquals(TokenType.ASSIGN, tokens.get(2).getType());
        assertEquals("10", tokens.get(3).getValue());
        assertEquals(TokenType.PLUS, tokens.get(4).getType());
        assertEquals("20", tokens.get(5).getValue());
        assertEquals(TokenType.SEMICOLON, tokens.get(6).getType());
    }

    @Test
    public void testIdentifiersAndNumbers() throws LexerException {
        String source = "var name = 42; var age = 30;";
        Lexer lexer = new Lexer(source);
        List<Token> tokens = lexer.tokenize();

        assertEquals("name", tokens.get(1).getValue());
        assertEquals("42", tokens.get(3).getValue());
        assertEquals("age", tokens.get(7).getValue());
        assertEquals("30", tokens.get(9).getValue());
    }

    @Test
    public void testOperators() throws LexerException {
        String source = "x = a + b - c * d / e % f;";
        Lexer lexer = new Lexer(source);
        List<Token> tokens = lexer.tokenize();

        assertEquals(TokenType.IDENTIFIER, tokens.get(0).getType());
        assertEquals(TokenType.ASSIGN, tokens.get(1).getType());
        assertEquals(TokenType.IDENTIFIER, tokens.get(2).getType());
        assertEquals(TokenType.PLUS, tokens.get(3).getType());
        assertEquals(TokenType.IDENTIFIER, tokens.get(4).getType());
        assertEquals(TokenType.MINUS, tokens.get(5).getType());
        assertEquals(TokenType.IDENTIFIER, tokens.get(6).getType());
        assertEquals(TokenType.MULTIPLY, tokens.get(7).getType());
        assertEquals(TokenType.IDENTIFIER, tokens.get(8).getType());
        assertEquals(TokenType.DIVIDE, tokens.get(9).getType());
        assertEquals(TokenType.IDENTIFIER, tokens.get(10).getType());
        assertEquals(TokenType.MODULO, tokens.get(11).getType());
        assertEquals(TokenType.IDENTIFIER, tokens.get(12).getType());
        assertEquals(TokenType.SEMICOLON, tokens.get(13).getType());
    }

    @Test
    public void testBooleanLiterals() throws LexerException {
        String source = "var t = true; var f = false;";
        Lexer lexer = new Lexer(source);
        List<Token> tokens = lexer.tokenize();

        assertEquals(TokenType.BOOLEAN, tokens.get(3).getType());
        assertEquals("true", tokens.get(3).getValue());
        assertEquals(TokenType.BOOLEAN, tokens.get(9).getType());
        assertEquals("false", tokens.get(9).getValue());
    }

    @Test
    public void testStringLiteral() throws LexerException {
        String source = "var s = \"Hello, World!\";";
        Lexer lexer = new Lexer(source);
        List<Token> tokens = lexer.tokenize();

        assertEquals(TokenType.STRING, tokens.get(3).getType());
        assertEquals("Hello, World!", tokens.get(3).getValue());
    }

    @Test
    public void testComplexExpression() throws LexerException {
        String source = "var result = (a + b) * c / d - e;";
        Lexer lexer = new Lexer(source);
        List<Token> tokens = lexer.tokenize();

        assertEquals(TokenType.LPAREN, tokens.get(3).getType());
        assertEquals(TokenType.RPAREN, tokens.get(7).getType());
        assertEquals(TokenType.MULTIPLY, tokens.get(8).getType());
        assertEquals(TokenType.DIVIDE, tokens.get(10).getType());
        assertEquals(TokenType.MINUS, tokens.get(12).getType());
    }
}
