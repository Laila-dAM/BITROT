package tokio.codegen.c;

import tokio.ast.*;
import java.util.List;
import java.util.stream.Collectors;

public class CGenerator {

    public String generate(ProgramNode program) {
        StringBuilder sb = new StringBuilder();
        sb.append("#include <stdio.h>\n\n");
        sb.append(generateStatements(program.getStatements()));
        return sb.toString();
    }

    private String generateStatements(List<ASTNode> statements) {
        StringBuilder sb = new StringBuilder();
        for (ASTNode node : statements) {
            sb.append(generateNode(node)).append("\n");
        }
        return sb.toString();
    }

    private String generateNode(ASTNode node) {
        if (node instanceof FunctionNode) {
            return generateFunction((FunctionNode) node);
        } else if (node instanceof VariableNode) {
            return generateVariable((VariableNode) node);
        } else if (node instanceof BinaryExpression) {
            return generateExpression((BinaryExpression) node) + ";";
        } else if (node instanceof StatementNode) {
            return generateStatements(((StatementNode) node).getStatements());
        } else if (node instanceof ExpressionNode) {
            return generateExpression((ExpressionNode) node) + ";";
        }
        return "";
    }

    private String generateFunction(FunctionNode func) {
        String retType = mapType(func.getReturnType());
        String params = func.getParameters().stream()
                .map(p -> mapType(p.getType()) + " " + p.getName())
                .collect(Collectors.joining(", "));
        String body = generateStatements(func.getBody());
        return retType + " " + func.getName() + "(" + params + ") {\n" + indent(body) + "}\n";
    }

    private String generateVariable(VariableNode var) {
        return mapType(var.getType()) + " " + var.getName() + (var.getValue() != null ? " = " + generateExpression(var.getValue()) : "") + ";";
    }

    private String generateExpression(ExpressionNode expr) {
        if (expr instanceof BinaryExpression) {
            BinaryExpression bin = (BinaryExpression) expr;
            return "(" + generateExpression(bin.getLeft()) + " " + bin.getOperator() + " " + generateExpression(bin.getRight()) + ")";
        } else if (expr instanceof VariableNode) {
            return ((VariableNode) expr).getName();
        } else if (expr instanceof FunctionNode) {
            return ((FunctionNode) expr).getName() + "()";
        }
        return expr.toString();
    }

    private String mapType(String type) {
        switch (type) {
            case "int":
                return "int";
            case "float":
                return "float";
            case "string":
                return "char*";
            case "void":
            default:
                return "void";
        }
    }

    private String indent(String code) {
        return "    " + code.replaceAll("\n", "\n    ");
    }
}
