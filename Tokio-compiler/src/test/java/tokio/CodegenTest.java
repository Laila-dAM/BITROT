package tokio;

import org.junit.jupiter.api.Test;
import tokio.lexer.Lexer;
import tokio.parser.Parser;
import tokio.ast.ASTNode;
import tokio.codegen.c.CGenerator;
import tokio.codegen.bytecode.BytecodeGenerator;
import tokio.exceptions.LexerException;
import tokio.exceptions.ParserException;

import static org.junit.jupiter.api.Assertions.*;

public class CodegenTest {

    @Test
    public void testCCodeGeneration() throws LexerException, ParserException {
        String source = "var x = 10 + 20;";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        CGenerator cgen = new CGenerator();
        String output = cgen.generate(ast);

        assertTrue(output.contains("int x = 10 + 20;"));
        assertTrue(output.contains("int main()"));
    }

    @Test
    public void testBytecodeGeneration() throws LexerException, ParserException {
        String source = "var a = 5; var b = a + 3;";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        BytecodeGenerator bcgen = new BytecodeGenerator();
        String bytecode = bcgen.generate(ast);

        assertTrue(bytecode.contains("PUSH 5"));
        assertTrue(bytecode.contains("STORE a"));
        assertTrue(bytecode.contains("LOAD a"));
        assertTrue(bytecode.contains("PUSH 3"));
        assertTrue(bytecode.contains("ADD"));
        assertTrue(bytecode.contains("STORE b"));
    }

    @Test
    public void testComplexExpressionBytecode() throws LexerException, ParserException {
        String source = "var result = (a + b) * c;";
        Lexer lexer = new Lexer(source);
        Parser parser = new Parser(lexer.tokenize());
        ASTNode ast = parser.parse();

        BytecodeGenerator bcgen = new BytecodeGenerator();
        String bytecode = bcgen.generate(ast);

        assertTrue(bytecode.contains("LOAD a"));
        assertTrue(bytecode.contains("LOAD b"));
        assertTrue(bytecode.contains("ADD"));
        assertTrue(bytecode.contains("LOAD c"));
        assertTrue(bytecode.contains("MUL"));
        assertTrue(bytecode.contains("STORE result"));
    }
}
