package tokio.exceptions;

public class TypeException extends CompilerException {
    public TypeException(String message) {
        super(message);
    }

    public TypeException(String message, Throwable cause) {
        super(message, cause);
    }
}
