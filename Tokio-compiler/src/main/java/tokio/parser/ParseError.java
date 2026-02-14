package tokio.parser;

public class ParseError extends Exception {
    public ParseError(String message) {
        super(message);
    }
}
