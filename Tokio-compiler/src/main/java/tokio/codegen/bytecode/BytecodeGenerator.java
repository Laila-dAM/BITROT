package tokio.codegen.bytecode;

import tokio.ast.*;
import java.util.*;
import java.io.*;

public class BytecodeGenerator {

    private List<Instruction> instructions;
    private Map<String, Integer> functionLabels;
    private int labelCounter;

    public BytecodeGenerator() {
        this.instructions = new ArrayList<>();
        this.functionLabels = new HashMap<>();
        this.labelCounter = 0;
    }

    public List<Instruction> generate(ASTNode node) {
        instructions.clear();
        visit(node);
        return instructions;
    }

    private void visit(ASTNode node) {
        if (node instanceof ProgramNode) {
            for (ASTNode stmt : ((ProgramNode) node).getStatements()) {
                visit(stmt);
            }
        } else if (node instanceof ExpressionNode) {
            visitExpression((ExpressionNode) node);
        } else if (node instanceof StatementNode) {
            visitStatement((StatementNode) node);
        } else if (node instanceof FunctionNode) {
            visitFunction((FunctionNode) node);
        }
    }

    private void visitExpression(ExpressionNode expr) {
        if (expr instanceof BinaryExpression) {
            BinaryExpression bin = (BinaryExpression) expr;
            visitExpression(bin.getLeft());
            visitExpression(bin.getRight());
            switch (bin.getOperator()) {
                case "+": instructions.add(new Instruction(OpCode.ADD)); break;
                case "-": instructions.add(new Instruction(OpCode.SUB)); break;
                case "*": instructions.add(new Instruction(OpCode.MUL)); break;
                case "/": instructions.add(new Instruction(OpCode.DIV)); break;
                default: throw new RuntimeException("Unsupported operator: " + bin.getOperator());
            }
        } else if (expr instanceof VariableNode) {
            instructions.add(new Instruction(OpCode.LOAD, ((VariableNode) expr).getName()));
        }
    }

    private void visitStatement(StatementNode stmt) {
        if (stmt.getExpression() != null) {
            visitExpression(stmt.getExpression());
            instructions.add(new Instruction(OpCode.POP));
        }
    }

    private void visitFunction(FunctionNode fn) {
        String label = "FUNC_" + fn.getName();
        functionLabels.put(fn.getName(), labelCounter++);
        instructions.add(new Instruction(OpCode.LABEL, label));
        for (ASTNode stmt : fn.getBody()) {
            visit(stmt);
        }
        instructions.add(new Instruction(OpCode.RET));
    }

    public void saveBytecode(List<Instruction> bytecode, String filePath) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filePath))) {
            out.writeObject(bytecode);
        }
    }
}
