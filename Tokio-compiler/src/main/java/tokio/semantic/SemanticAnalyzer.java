package tokio.semantic;

import tokio.ast.*;
import tokio.exceptions.CompilerException;

public class SemanticAnalyzer {
    private SymbolTable symbolTable;
    private TypeChecker typeChecker;

    public SemanticAnalyzer() {
        this.symbolTable = new SymbolTable();
        this.typeChecker = new TypeChecker(symbolTable);
    }

    public void analyze(ProgramNode program) throws CompilerException {
        try {
            typeChecker.check(program);
        } catch (RuntimeException e) {
            throw new CompilerException("Semantic error: " + e.getMessage());
        }
    }

    public SymbolTable getSymbolTable() {
        return symbolTable;
    }
}
