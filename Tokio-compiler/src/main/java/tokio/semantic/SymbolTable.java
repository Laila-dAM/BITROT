package tokio.semantic;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class SymbolTable {
    private Stack<Map<String, String>> scopes;

    public SymbolTable() {
        this.scopes = new Stack<>();
        this.scopes.push(new HashMap<>());
    }

    public void enterScope() {
        this.scopes.push(new HashMap<>());
    }

    public void exitScope() {
        if (!scopes.isEmpty()) {
            this.scopes.pop();
        }
    }

    public void define(String name, String type) {
        if (!scopes.isEmpty()) {
            scopes.peek().put(name, type);
        }
    }

    public boolean isDefined(String name) {
        for (int i = scopes.size() - 1; i >= 0; i--) {
            if (scopes.get(i).containsKey(name)) {
                return true;
            }
        }
        return false;
    }

    public String lookup(String name) {
        for (int i = scopes.size() - 1; i >= 0; i--) {
            if (scopes.get(i).containsKey(name)) {
                return scopes.get(i).get(name);
            }
        }
        return null;
    }
}
