package tokio.ast;

public class BinaryExpression extends ExpressionNode {
    private ExpressionNode left;
    private ExpressionNode right;
    private String operator;

    public BinaryExpression(ExpressionNode left, ExpressionNode right, String operator) {
        super("BinaryExpression");
        this.left = left;
        this.right = right;
        this.operator = operator;
    }

    public ExpressionNode getLeft() {
        return left;
    }

    public ExpressionNode getRight() {
        return right;
    }

    public String getOperator() {
        return operator;
    }

    @Override
    public String toString() {
        return "(" + left.toString() + " " + operator + " " + right.toString() + ")";
    }
}
