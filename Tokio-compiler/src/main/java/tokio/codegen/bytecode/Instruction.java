package tokio.codegen.bytecode;

import java.io.Serializable;
import java.util.Objects;

public class Instruction implements Serializable {
    private OpCode opcode;
    private Object operand;

    public Instruction(OpCode opcode) { this.opcode = opcode; }
    public Instruction(OpCode opcode, Object operand) { this.opcode = opcode; this.operand = operand; }

    public OpCode getOpcode() { return opcode; }
    public Object getOperand() { return operand; }

    @Override
    public String toString() { return operand != null ? opcode.name() + " " + operand.toString() : opcode.name(); }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Instruction)) return false;
        Instruction that = (Instruction) o;
        return opcode == that.opcode && Objects.equals(operand, that.operand);
    }

    @Override
    public int hashCode() { return Objects.hash(opcode, operand); }
}
