package tokio.ast;

public class VariableNode extends ExpressionNode {
    private String name;
    private String type;
    private ExpressionNode value;

    public VariableNode(String name, String type) {
        super("Variable");
        this.name = name;
        this.type = type;
    }

    public VariableNode(String name, String type, ExpressionNode value) {
        super("Variable");
        this.name = name;
        this.type = type;
        this.value = value;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public ExpressionNode getValue() {
        return value;
    }

    public void setValue(ExpressionNode value) {
        this.value = value;
    }

    @Override
    public String toString() {
        if (value != null) {
            return type + " " + name + " = " + value.toString();
        } else {
            return type + " " + name;
        }
    }
}
