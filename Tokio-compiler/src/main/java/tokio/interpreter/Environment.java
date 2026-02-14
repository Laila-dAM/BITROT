package tokio.interpreter;

import java.util.HashMap;
import java.util.Map;

public class Environment {
    private final Environment parent;
    private final Map<String, RuntimeValue> variables;

    public Environment() {
        this.parent = null;
        this.variables = new HashMap<>();
    }

    public Environment(Environment parent) {
        this.parent = parent;
        this.variables = new HashMap<>();
    }

    public void define(String name, RuntimeValue value) {
        variables.put(name, value);
    }

    public void assign(String name, RuntimeValue value) {
        if (variables.containsKey(name)) {
            variables.put(name, value);
        } else if (parent != null) {
            parent.assign(name, value);
        } else {
            throw new RuntimeException("Undefined variable '" + name + "'");
        }
    }

    public RuntimeValue get(String name) {
        if (variables.containsKey(name)) {
            return variables.get(name);
        } else if (parent != null) {
            return parent.get(name);
        } else {
            throw new RuntimeException("Undefined variable '" + name + "'");
        }
    }

    public boolean isDefined(String name) {
        if (variables.containsKey(name)) {
            return true;
        } else return parent != null && parent.isDefined(name);
    }
}
