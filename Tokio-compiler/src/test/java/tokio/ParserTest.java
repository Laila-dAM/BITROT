package tokio;

import org.junit.jupiter.api.Test;
import tokio.lexer.Lexer;
import tokio.parser.Parser;
import tokio.ast.ASTNode;
import tokio.exceptions.LexerException;
import tokio.exceptions.ParserException;

import static org.junit.jupiter.api.Assertions.*;

public class ParserTest {

    @Test
    public void testSimpleAssignment() throws LexerException, ParserException {
        String source = "var x = 10;";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        assertEquals("ProgramNode", ast.getClass().getSimpleName());
        assertEquals(1, ast.getChildren().size());
        assertEquals("VariableNode", ast.getChildren().get(0).getClass().getSimpleName());
    }

    @Test
    public void testExpressionParsing() throws LexerException, ParserException {
        String source = "var result = a + b * c;";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        ASTNode varNode = ast.getChildren().get(0);
        assertEquals("VariableNode", varNode.getClass().getSimpleName());
        ASTNode expr = varNode.getChildren().get(1);
        assertEquals("BinaryExpression", expr.getClass().getSimpleName());
        assertEquals("+", expr.getValue());
    }

    @Test
    public void testFunctionDeclaration() throws LexerException, ParserException {
        String source = "func add(a, b) { return a + b; }";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        ASTNode funcNode = ast.getChildren().get(0);
        assertEquals("FunctionNode", funcNode.getClass().getSimpleName());
        assertEquals(2, funcNode.getChildren().size());
    }

    @Test
    public void testNestedExpressions() throws LexerException, ParserException {
        String source = "var x = (a + b) * (c - d);";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        ASTNode varNode = ast.getChildren().get(0);
        ASTNode expr = varNode.getChildren().get(1);
        assertEquals("BinaryExpression", expr.getClass().getSimpleName());
        assertEquals("*", expr.getValue());
        assertEquals("BinaryExpression", expr.getChildren().get(0).getClass().getSimpleName());
        assertEquals("BinaryExpression", expr.getChildren().get(1).getClass().getSimpleName());
    }

    @Test
    public void testIfElseParsing() throws LexerException, ParserException {
        String source = "if (x > 0) { y = 1; } else { y = 2; }";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        ASTNode ifNode = ast.getChildren().get(0);
        assertEquals("StatementNode", ifNode.getClass().getSimpleName());
        assertEquals(2, ifNode.getChildren().size());
    }
}
