import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class Renamer {

    final int EOL = 1;
    final int INTO = 2;
    final int LOAD = 3;
    final int LOADI = 4;
    final int STORE = 5;
    final int ADD = 6;
    final int SUB = 7;
    final int MULT = 8;
    final int LSHIFT = 9;
    final int RSHIFT = 10;
    final int OUTPUT = 11;
    final int NOP = 12;
    final int REGISTER = 13;
    final int COMMA = 14;
    final int SCAN_ERROR = 15;
    final int PARSE_ERROR = 16;
    final int EOF = 17;

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

    IRRow head;
    IRRow tail;
    int ops;
    int maxRegs;
    int[] SRtoVR;
    int[] lu;
    int vr;
    int maxLive;
    int live;

    public Renamer(IRRow head, IRRow tail, int ops, int maxRegs, int maxReg) {
        this.head = head;
        this.tail = tail;
        this.ops = ops;
        this.maxRegs = maxRegs;
        this.SRtoVR = new int[maxReg + 1];
        this.lu = new int[maxReg + 1];
        for (int i = 0; i <= maxReg; i++) {
            this.SRtoVR[i] = -1;
            this.lu[i] = -1;
        }
        vr = 0;
    }

    public void Rename() {
        IRRow curr = tail;
        int index = ops - 1;
        while (curr != null) {
            // System.out.println("Before: " + Arrays.toString(SRtoVR) + " " + Arrays.toString(lu));
            if (curr.opcode >= LOAD && curr.opcode <= RSHIFT) {
                if (curr.opcode == STORE) {
                    use(curr.op1, index);
                    use(curr.op3, index);
                } else if (curr.opcode == LOAD) {
                    define(curr.op3, index);
                    use(curr.op1, index);
                } else if (curr.opcode == LOADI) {
                    define(curr.op3, index);
                } else if (curr.opcode >= ADD && curr.opcode <= RSHIFT) {
                    define(curr.op3, index);
                    use(curr.op1, index);
                    use(curr.op2, index);
                }
            }
            // System.out.println("After: " + Arrays.toString(SRtoVR) + " " + Arrays.toString(lu));
            curr = curr.prev;
            index--;
            maxLive = Math.max(maxLive, live);
        }
    }

    public void define(Operant op, int index) {
        live--;
        if (SRtoVR[op.SR] == -1) {
            SRtoVR[op.SR] = vr;
            vr++;
        }
        op.VR = SRtoVR[op.SR];
        op.NU = lu[op.SR];
        lu[op.SR] = -1;
        SRtoVR[op.SR] = -1;
    }

    public void use(Operant op, int index) {
        if (SRtoVR[op.SR] == -1) {
            SRtoVR[op.SR] = vr;
            vr++;
            live++;
        }
        op.VR = SRtoVR[op.SR];
        op.NU = lu[op.SR];
        lu[op.SR] = index;
    }

    public void printRenamedIR() {
        IRRow curr = head;
        while (curr != null) {
            if (curr.opcode == LOADI) {
                System.out.println(tokenMap.get(curr.opcode) + " " + curr.op1.SR + " => r" + curr.op3.VR);
            } else if (curr.opcode == STORE || curr.opcode == LOAD) {
                System.out.println(tokenMap.get(curr.opcode) + " r" + curr.op1.VR + " => r" + curr.op3.VR);
            } else if (curr.opcode == ADD || curr.opcode == SUB || curr.opcode == MULT || curr.opcode == LSHIFT || curr.opcode == RSHIFT) {
                System.out.println(tokenMap.get(curr.opcode) + " r" + curr.op1.VR + ", r" + curr.op2.VR + " => r" + curr.op3.VR);
            } else if (curr.opcode == OUTPUT) {
                System.out.println("output " + curr.op1.SR);
            } else if (curr.opcode == NOP) {
                System.out.println("nop");
            }
            curr = curr.next;
        }
    }
    
}
