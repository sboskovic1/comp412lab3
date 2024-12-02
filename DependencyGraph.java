import java.util.*;

public class DependencyGraph {

    public List<DependencyNode> graph;

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

    public DependencyGraph() {
        graph = new ArrayList<DependencyNode>();
    }

    public void buildGraph(IRRow head, int maxReg) {
        IRRow curr = head;
        int[] lastUse = new int[maxReg + 1];
        for (int i = 0; i < lastUse.length; i++) {
            lastUse[i] = -1;
        }
        int index = 0;

        while (curr != null) {
            DependencyNode node = new DependencyNode();
            // Data edges
            if (curr.opcode >= ADD && curr.opcode <= RSHIFT) {
                if (lastUse[curr.op1.VR] != -1) {
                    node.parents.put(graph.get(lastUse[curr.op1.VR]), new EdgeData(0));
                    graph.get(lastUse[curr.op1.VR]).children.put(node, new EdgeData(0));
                }
                if (lastUse[curr.op2.VR] != -1) {
                    node.parents.put(graph.get(lastUse[curr.op2.VR]), new EdgeData(0));
                    graph.get(lastUse[curr.op2.VR]).children.put(node, new EdgeData(0));
                }
                lastUse[curr.op3.VR] = index;
            } else if (curr.opcode == LOADI) {

            } else if (curr.opcode == LOAD) {

            } else if (curr.opcode == STORE) {

            } else if (curr.opcode == OUTPUT) {

            } else if (curr.opcode == NOP) {

            }

            // Serialization edges

            // Conflict edges

            graph.add(node);
            index++;
        }
    }

    public void printGraph() {
        for (DependencyNode node : graph) {
            System.out.println(node.operation.toString());
            System.out.println("Dependencies:");
            for (DependencyNode parent : node.parents.keySet()) {
                String type = node.parents.get(parent).type == 0 ? "Data" : (node.parents.get(parent).type == 2 ? "Conflict" : "Serialization");
                System.out.println(type + ": " + parent.operation.toString());
            }
        }
    }
    
}
