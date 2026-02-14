package tokio.interpreter;

public class RuntimeValue {
    private final Object value;

    public RuntimeValue(Object value) {
        this.value = value;
    }

    public boolean isNumber() {
        return value instanceof Number;
    }

    public boolean isString() {
        return value instanceof String;
    }

    public boolean isNull() {
        return value == null;
    }

    public double asDouble() {
        if (isNumber()) {
            return ((Number) value).doubleValue();
        }
        throw new RuntimeException("Value is not a number");
    }

    public String asString() {
        if (isString()) {
            return (String) value;
        }
        throw new RuntimeException("Value is not a string");
    }

    public Object getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value == null ? "null" : value.toString();
    }
}
