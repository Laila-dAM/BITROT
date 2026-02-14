package tokio.interpreter;

import tokio.ast.*;
import tokio.semantic.SymbolTable;
import java.util.List;

public class Interpreter {
    private Environment globalEnv;
    private SymbolTable symbolTable;

    public Interpreter(SymbolTable symbolTable) {
        this.symbolTable = symbolTable;
        this.globalEnv = new Environment(null);
    }

    public void execute(ProgramNode program) {
        for (ASTNode node : program.getStatements()) {
            eval(node, globalEnv);
        }
    }

    private RuntimeValue eval(ASTNode node, Environment env) {
        if (node instanceof ExpressionNode) {
            return evalExpression((ExpressionNode) node, env);
        } else if (node instanceof FunctionNode) {
            FunctionNode func = (FunctionNode) node;
            env.define(func.getName(), new RuntimeValue(func));
            return new RuntimeValue(null);
        } else if (node instanceof StatementNode) {
            return evalStatement((StatementNode) node, env);
        }
        return new RuntimeValue(null);
    }

    private RuntimeValue evalStatement(StatementNode stmt, Environment env) {
        List<ASTNode> children = stmt.getChildren();
        RuntimeValue last = new RuntimeValue(null);
        for (ASTNode child : children) {
            last = eval(child, env);
        }
        return last;
    }

    private RuntimeValue evalExpression(ExpressionNode expr, Environment env) {
        if (expr instanceof VariableNode) {
            VariableNode var = (VariableNode) expr;
            return env.get(var.getName());
        } else if (expr instanceof BinaryExpression) {
            BinaryExpression bin = (BinaryExpression) expr;
            RuntimeValue left = evalExpression(bin.getLeft(), env);
            RuntimeValue right = evalExpression(bin.getRight(), env);
            double l = Double.parseDouble(left.getValue().toString());
            double r = Double.parseDouble(right.getValue().toString());
            switch (bin.getOperator()) {
                case "+": return new RuntimeValue(l + r);
                case "-": return new RuntimeValue(l - r);
                case "*": return new RuntimeValue(l * r);
                case "/": return new RuntimeValue(l / r);
                default: throw new RuntimeException("Unknown operator: " + bin.getOperator());
            }
        }
        return new RuntimeValue(null);
    }
}
