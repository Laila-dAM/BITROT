package tokio.cli;

import tokio.ast.ProgramNode;
import tokio.codegen.c.CGenerator;
import tokio.codegen.bytecode.BytecodeGenerator;
import tokio.interpreter.Interpreter;
import tokio.semantic.SemanticAnalyzer;
import tokio.semantic.SymbolTable;
import tokio.utils.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.List;

public class CompilerCLI {
    private SymbolTable symbolTable = new SymbolTable();
    private SemanticAnalyzer analyzer = new SemanticAnalyzer();
    private Interpreter interpreter = new Interpreter(symbolTable);

    public void run(String[] args) {
        if (args.length == 0 || args[0].equals(Commands.HELP)) {
            showHelp();
            return;
        }

        String command = args[0];
        try {
            switch (command) {
                case Commands.BUILD -> build(args);
                case Commands.RUN -> runProgram(args);
                case Commands.COMPILE -> compileToBytecode(args);
                case Commands.GENERATE_AST -> generateAST(args);
                default -> System.out.println("Unknown command. Use 'help' to see commands.");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private void showHelp() {
        System.out.println("Tokio Compiler CLI Commands:");
        System.out.println("help - show this help");
        System.out.println("build <file> - build C code");
        System.out.println("run <file> - run program");
        System.out.println("compile <file> - compile to bytecode");
        System.out.println("generate-ast <file> - generate AST JSON");
    }

    private void build(String[] args) throws IOException {
        if (args.length < 2) {
            System.out.println("Specify source file.");
            return;
        }
        String source = args[1];
        ProgramNode program = FileUtils.loadProgram(source);
        analyzer.analyze(program);
        CGenerator generator = new CGenerator();
        String cCode = generator.generate(program);
        FileUtils.saveToFile("dist/c/output.c", cCode);
        System.out.println("C code generated: dist/c/output.c");
    }

    private void runProgram(String[] args) throws IOException {
        if (args.length < 2) {
            System.out.println("Specify source file.");
            return;
        }
        String source = args[1];
        ProgramNode program = FileUtils.loadProgram(source);
        analyzer.analyze(program);
        interpreter.execute(program);
        System.out.println("Program executed successfully.");
    }

    private void compileToBytecode(String[] args) throws IOException {
        if (args.length < 2) {
            System.out.println("Specify source file.");
            return;
        }
        String source = args[1];
        ProgramNode program = FileUtils.loadProgram(source);
        analyzer.analyze(program);
        BytecodeGenerator generator = new BytecodeGenerator();
        List<?> bytecode = generator.generate(program);
        generator.saveBytecode((List<?>) bytecode, "dist/bytecode/output.tbc");
        System.out.println("Bytecode generated: dist/bytecode/output.tbc");
    }

    private void generateAST(String[] args) throws IOException {
        if (args.length < 2) {
            System.out.println("Specify source file.");
            return;
        }
        String source = args[1];
        ProgramNode program = FileUtils.loadProgram(source);
        FileUtils.saveToJson(program, "dist/ast/ast.json");
        System.out.println("AST JSON generated: dist/ast/ast.json");
    }
}
