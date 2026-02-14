package tokio.exceptions;

public class RuntimeExceptionCompiler extends CompilerException {
    public RuntimeExceptionCompiler(String message) {
        super(message);
    }

    public RuntimeExceptionCompiler(String message, Throwable cause) {
        super(message, cause);
    }
}
