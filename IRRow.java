//import java.util.Scanner;

import java.util.HashMap;
import java.util.Map;

public class IRRow {

    static final Map<Integer, String> tokenMap = new HashMap<Integer, String>() {{
        put(1, "eol");
        put(2, "into");
        put(3, "load");
        put(4, "loadI");
        put(5, "store");
        put(6, "add");
        put(7, "sub");
        put(8, "mult");
        put(9, "lshift");
        put(10, "rshift");
        put(11, "output");
        put(12, "nop");
        put(13, "REGISTER");
        put(14, "COMMA");  
        put(15, "SCAN_ERROR");
        put(16, "PARSE_ERROR");
        put(17, "eof");
    }};
    
    public int opcode;
    public Operant op1;
    public Operant op2;
    public Operant op3;
    public IRRow next;
    public IRRow prev;

    public IRRow(int opcode, int sr1, int sr2, int sr3) {
        this.opcode = opcode;
        op1 = new Operant(sr1);
        op2 = new Operant(sr2);
        op3 = new Operant(sr3);
        next = null;
        prev = null;
    }

    public IRRow() {
        opcode = -1;
        op1 = null;
        op2 = null;
        op3 = null;
        next = null;
        prev = null;
    }

    public IRRow(int opcode) {
        this.opcode = opcode;
    }

    public IRRow(int opcode, int sr1, int sr3) {
        this.opcode = opcode;
        op1 = new Operant(-1, sr1);
        op2 = new Operant(-1, -1);
        op3 = new Operant(-1, sr3);
        next = null;
        prev = null;
    }
 
    public String toString() {
        String line = tokenMap.get(this.opcode) + " { ";
        if (op1 != null) {
            line += op1.toString();
        }
        if (op2 != null && (opcode >= 6 && opcode <= 10)) {
            line += op2.toString();
        }
        if (op3 != null) {
            line += op3.toString();
        }
        return line + "}";
    }

    public void printIR() {
        IRRow curr = this;
        while (curr != null) {
            System.out.println(curr.toString());
            curr = curr.next;
        }
    }

    public String toILOCString() {
        String line = tokenMap.get(opcode);
        if (op1 != null) {
            if (opcode == 4) {
                line += " " + op1.SR;
            } else if (opcode != 11) {
                line += " r" + op1.VR;
            }
        }
        if (op2 != null && (opcode >= 6 && opcode <= 10)) {
            line += ", r" + op2.VR;
        }
        if (op3 != null) {
            if (opcode != 11) {
                line += " => r" + op3.VR;
            } else {
                line += " " + op1.SR;
            }
        }
        return line;
    }

}