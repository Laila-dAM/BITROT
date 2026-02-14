package tokio.ast;

import java.util.ArrayList;
import java.util.List;

public abstract class ASTNode {
    private final String type;
    private final List<ASTNode> children = new ArrayList<>();

    protected ASTNode(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public List<ASTNode> getChildren() {
        return children;
    }

    public void addChild(ASTNode child) {
        children.add(child);
    }

    public void addChildren(List<ASTNode> nodes) {
        children.addAll(nodes);
    }

    public abstract String toString();
}
