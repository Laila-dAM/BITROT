package tokio.semantic;

import tokio.ast.*;

public class TypeChecker {
    private SymbolTable symbolTable;

    public TypeChecker(SymbolTable symbolTable) {
        this.symbolTable = symbolTable;
    }

    public void check(ProgramNode program) {
        for (ASTNode node : program.getStatements()) {
            checkNode(node);
        }
    }

    private String checkNode(ASTNode node) {
        if (node instanceof VariableNode) {
            VariableNode var = (VariableNode) node;
            if (!symbolTable.isDefined(var.getName())) {
                symbolTable.define(var.getName(), "Unknown");
            }
            return "Unknown";
        } else if (node instanceof BinaryExpression) {
            BinaryExpression bin = (BinaryExpression) node;
            String leftType = checkNode(bin.getLeft());
            String rightType = checkNode(bin.getRight());
            if (!leftType.equals(rightType)) {
                throw new RuntimeException("Type mismatch: " + leftType + " vs " + rightType);
            }
            return leftType;
        } else if (node instanceof FunctionNode) {
            FunctionNode func = (FunctionNode) node;
            symbolTable.enterScope();
            for (String param : func.getParameters()) {
                symbolTable.define(param, "Unknown");
            }
            for (ASTNode stmt : func.getBody()) {
                checkNode(stmt);
            }
            symbolTable.exitScope();
            symbolTable.define(func.getName(), "Function");
            return "Function";
        } else if (node instanceof StatementNode) {
            for (ASTNode child : node.getChildren()) {
                checkNode(child);
            }
            return "void";
        } else if (node instanceof ExpressionNode) {
            return "Unknown";
        }
        return "void";
    }
}
