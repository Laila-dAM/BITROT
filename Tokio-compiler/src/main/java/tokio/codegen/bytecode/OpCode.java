package tokio.codegen.bytecode;

public enum OpCode {
    NOP, LOAD_CONST, LOAD_VAR, STORE_VAR, ADD, SUB, MUL, DIV, MOD, NEG,
    JMP, JMP_IF_TRUE, JMP_IF_FALSE, CALL, RET, PRINT, HALT, POP, LABEL
}
