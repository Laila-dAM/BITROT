package tokio.parser;

import tokio.lexer.Token;
import tokio.lexer.TokenType;
import tokio.ast.*;
import java.util.List;
import java.util.ArrayList;

public class Parser {
    private final List<Token> tokens;
    private int current = 0;

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
    }

    public ProgramNode parse() throws ParseError {
        List<ASTNode> statements = new ArrayList<>();
        while (!isAtEnd()) {
            statements.add(declaration());
        }
        return new ProgramNode(statements);
    }

    private ASTNode declaration() throws ParseError {
        if (match(TokenType.FUNCTION)) return functionDeclaration();
        return statement();
    }

    private FunctionNode functionDeclaration() throws ParseError {
        Token name = consume(TokenType.IDENTIFIER, "Expected function name");

        // Parâmetros
        consume(TokenType.LEFT_PAREN, "Expected '(' after function name");
        List<VariableNode> parameters = new ArrayList<>();
        if (!check(TokenType.RIGHT_PAREN)) {
            do {
                Token param = consume(TokenType.IDENTIFIER, "Expected parameter name");
                parameters.add(new VariableNode(param.getLexeme(), "var"));
            } while (match(TokenType.COMMA));
        }
        consume(TokenType.RIGHT_PAREN, "Expected ')' after parameters");

        // Corpo
        consume(TokenType.LEFT_BRACE, "Expected '{' before function body");
        List<ASTNode> body = new ArrayList<>();
        while (!check(TokenType.RIGHT_BRACE) && !isAtEnd()) {
            body.add(statement());
        }
        consume(TokenType.RIGHT_BRACE, "Expected '}' after function body");

        return new FunctionNode(name.getLexeme(), parameters, body, "void");
    }

    private ASTNode statement() throws ParseError {
        if (match(TokenType.IF)) return ifStatement();
        if (match(TokenType.WHILE)) return whileStatement();
        if (match(TokenType.RETURN)) return returnStatement();
        return expressionStatement();
    }

    private ASTNode ifStatement() throws ParseError {
        consume(TokenType.LEFT_PAREN, "Expected '(' after 'if'");
        ASTNode condition = expression();
        consume(TokenType.RIGHT_PAREN, "Expected ')' after condition");
        ASTNode thenBranch = statement();
        ASTNode elseBranch = null;
        if (match(TokenType.ELSE)) {
            elseBranch = statement();
        }
        return new IfStatementNode(condition, thenBranch, elseBranch);
    }

    private ASTNode whileStatement() throws ParseError {
        consume(TokenType.LEFT_PAREN, "Expected '(' after 'while'");
        ASTNode condition = expression();
        consume(TokenType.RIGHT_PAREN, "Expected ')' after condition");
        ASTNode body = statement();
        return new WhileStatementNode(condition, body);
    }

    private ASTNode returnStatement() throws ParseError {
        ASTNode value = null;
        if (!check(TokenType.SEMICOLON)) {
            value = expression();
        }
        consume(TokenType.SEMICOLON, "Expected ';' after return value");
        return new ReturnStatementNode(value);
    }

    private ASTNode expressionStatement() throws ParseError {
        ASTNode expr = expression();
        consume(TokenType.SEMICOLON, "Expected ';' after expression");
        return new ExpressionStatementNode(expr);
    }

    private ASTNode expression() throws ParseError {
        return assignment();
    }

    private ASTNode assignment() throws ParseError {
        ASTNode expr = equality();
        if (match(TokenType.EQUAL)) {
            Token equals = previous();
            ASTNode value = assignment();
            if (expr instanceof VariableNode) {
                VariableNode var = (VariableNode) expr;
                return new BinaryExpression(new VariableNode(var.getName(), var.getType()), value, "=");
            }
            throw error(equals, "Invalid assignment target");
        }
        return expr;
    }

    private ASTNode equality() throws ParseError {
        ASTNode expr = comparison();
        while (match(TokenType.BANG_EQUAL, TokenType.EQUAL_EQUAL)) {
            Token op = previous();
            ASTNode right = comparison();
            expr = new BinaryExpression(expr, right, op.getLexeme());
        }
        return expr;
    }

    private ASTNode comparison() throws ParseError {
        ASTNode expr = term();
        while (match(TokenType.GREATER, TokenType.GREATER_EQUAL, TokenType.LESS, TokenType.LESS_EQUAL)) {
            Token op = previous();
            ASTNode right = term();
            expr = new BinaryExpression(expr, right, op.getLexeme());
        }
        return expr;
    }

    private ASTNode term() throws ParseError {
        ASTNode expr = factor();
        while (match(TokenType.PLUS, TokenType.MINUS)) {
            Token op = previous();
            ASTNode right = factor();
            expr = new BinaryExpression(expr, right, op.getLexeme());
        }
        return expr;
    }

    private ASTNode factor() throws ParseError {
        ASTNode expr = unary();
        while (match(TokenType.STAR, TokenType.SLASH)) {
            Token op = previous();
            ASTNode right = unary();
            expr = new BinaryExpression(expr, right, op.getLexeme());
        }
        return expr;
    }

    private ASTNode unary() throws ParseError {
        if (match(TokenType.BANG, TokenType.MINUS)) {
            Token op = previous();
            ASTNode right = unary();
            return new UnaryExpressionNode(right, op.getLexeme());
        }
        return primary();
    }

    private ASTNode primary() throws ParseError {
        if (match(TokenType.FALSE)) return new VariableNode("false", "bool");
        if (match(TokenType.TRUE)) return new VariableNode("true", "bool");
        if (match(TokenType.NUMBER)) return new VariableNode(previous().getLexeme(), "number");
        if (match(TokenType.STRING)) return new VariableNode(previous().getLexeme(), "string");
        if (match(TokenType.IDENTIFIER)) return new VariableNode(previous().getLexeme(), "var");
        if (match(TokenType.LEFT_PAREN)) {
            ASTNode expr = expression();
            consume(TokenType.RIGHT_PAREN, "Expected ')' after expression");
            return expr;
        }
        throw error(peek(), "Expected expression");
    }

    private boolean match(TokenType... types) {
        for (TokenType t : types) {
            if (check(t)) {
                advance();
                return true;
            }
        }
        return false;
    }

    private boolean check(TokenType t) {
        if (isAtEnd()) return false;
        return peek().getType() == t;
    }

    private Token advance() {
        if (!isAtEnd()) current++;
        return previous();
    }

    private boolean isAtEnd() {
        return peek().getType() == TokenType.EOF;
    }

    private Token peek() {
        return tokens.get(current);
    }

    private Token previous() {
        return tokens.get(current - 1);
    }

    private Token consume(TokenType t, String msg) throws ParseError {
        if (check(t)) return advance();
        throw error(peek(), msg);
    }

    private ParseError error(Token token, String msg) {
        return new ParseError(msg + " at token '" + token.getLexeme() + "'");
    }
}
