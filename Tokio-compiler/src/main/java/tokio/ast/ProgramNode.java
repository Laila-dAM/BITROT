package tokio.ast;

import java.util.List;

public class ProgramNode extends ASTNode {
    private final List<ASTNode> statements;

    public ProgramNode(List<ASTNode> statements) {
        super("Program");
        this.statements = statements;
        addChildren(statements);
    }

    public List<ASTNode> getStatements() {
        return statements;
    }

    @Override
    public String toString() {
        return "ProgramNode{" +
                "statements=" + statements +
                '}';
    }
}
