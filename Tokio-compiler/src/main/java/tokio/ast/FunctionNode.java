package tokio.ast;

import java.util.List;
import java.util.stream.Collectors;

public class FunctionNode extends ASTNode {
    private String name;
    private List<VariableNode> parameters;
    private List<ASTNode> body;
    private String returnType;

    public FunctionNode(String name, List<VariableNode> parameters, List<ASTNode> body, String returnType) {
        super("Function");
        this.name = name;
        this.parameters = parameters;
        this.body = body;
        this.returnType = returnType;
        addChildren(body);
    }

    public String getName() {
        return name;
    }

    public List<VariableNode> getParameters() {
        return parameters;
    }

    public List<ASTNode> getBody() {
        return body;
    }

    public String getReturnType() {
        return returnType;
    }

    @Override
    public String toString() {
        String params = parameters.stream()
                                  .map(VariableNode::toString)
                                  .collect(Collectors.joining(", "));
        String bodyStr = body.stream()
                             .map(ASTNode::toString)
                             .collect(Collectors.joining("; "));
        return "Function " + name + "(" + params + ") { " + bodyStr + " }";
    }
}
