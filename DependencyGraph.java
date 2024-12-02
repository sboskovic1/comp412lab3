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


    public int[] lastUse;
    public int index;
    public List<Integer> readCache;
    public List<Integer> writeCache;
    public Map<Integer, Integer> readMap;
    public Map<Integer, Integer> writeMap;

    public int readStart;
    public int writeStart;


    public DependencyGraph(int maxReg) {
        graph = new ArrayList<DependencyNode>();
        index = 0;
        readCache = new ArrayList<Integer>();
        writeCache = new ArrayList<Integer>();
        writeMap = new HashMap<Integer, Integer>(); 
        readMap = new HashMap<Integer, Integer>();
        lastUse = new int[maxReg + 1];

        readStart = -1;
        writeStart = -1;

        for (int i = 0; i < lastUse.length; i++) {
            lastUse[i] = -1;
        }
    }

    public void buildGraph(IRRow head) {
        IRRow curr = head;
        int latestWrite = -1;
        int latestRead = -1;
        int latestOutput = -1;
        while (curr != null) {
            DependencyNode node = new DependencyNode(0, curr);
            // Data edges
            if (curr.opcode >= LOAD && curr.opcode <= RSHIFT) {
                addDataEdge(curr, node);
            }
            // Serialization edges
            if (curr.opcode == STORE) {
                addSerializationEdge(curr, node);
            }
            // Conflict edges
            if (curr.opcode == LOAD || curr.opcode == OUTPUT) {
                addConflictEdge(curr, node);
            }
            // Output ordering
            if (curr.opcode == OUTPUT) {
                if (latestOutput != -1) {
                    node.parents.put(graph.get(latestOutput), new EdgeData(1));
                    graph.get(latestOutput).children.put(node, new EdgeData(1));
                }
                latestOutput = index;
            }

            // Update last read and write
            if (curr.opcode == STORE) {
                writeCache.add(index);
                latestWrite = writeCache.size() - 1;
                if (writeStart == -1) {
                    writeStart = index;
                }
            } else if (curr.opcode == LOAD || curr.opcode == OUTPUT) {
                readCache.add(index);
                latestRead = readCache.size() - 1;
                if (readStart == -1) {
                    readStart = index;
                }
            } 
            writeMap.put(index, latestWrite);
            readMap.put(index, latestRead);
            graph.add(node);
            curr = curr.next;
            index++;
        }
    }

    public void addDataEdge(IRRow curr, DependencyNode node) {
        Set<Integer> readDependencies = new HashSet<Integer>();
        Set<Integer> writeDependencies = new HashSet<Integer>();
        int latest = -1;
        if (curr.opcode != LOADI) {
            if (lastUse[curr.op1.VR] != -1) {
                node.parents.put(graph.get(lastUse[curr.op1.VR]), new EdgeData(0));
                graph.get(lastUse[curr.op1.VR]).children.put(node, new EdgeData(0));
            }
            if (curr.opcode >= ADD && curr.opcode <= RSHIFT) {
                if (lastUse[curr.op2.VR] != -1) {
                    node.parents.put(graph.get(lastUse[curr.op2.VR]), new EdgeData(0));
                    graph.get(lastUse[curr.op2.VR]).children.put(node, new EdgeData(0));
                }
                latest = Math.max(graph.get(lastUse[curr.op1.VR]).index, graph.get(lastUse[curr.op1.VR]).index);
                for (Integer i : graph.get(lastUse[curr.op1.VR]).readDependencies) {
                    if (graph.get(lastUse[curr.op2.VR]).readDependencies.contains(i)) {
                        readDependencies.add(i);
                    }
                }
                for (Integer i : graph.get(lastUse[curr.op1.VR]).writeDependencies) {
                    if (graph.get(lastUse[curr.op2.VR]).writeDependencies.contains(i)) {
                        writeDependencies.add(i);
                    }
                }
            } else {
                readDependencies.addAll(graph.get(lastUse[curr.op1.VR]).readDependencies);
                writeDependencies.addAll(graph.get(lastUse[curr.op1.VR]).writeDependencies);
                latest = graph.get(lastUse[curr.op1.VR]).index;
            }
            if (readCache.size() > 0) {
                for (int i = Math.max(readMap.get(latest), readMap.get(readStart)); i < readCache.size(); i++) {
                    if (readCache.get(i) != lastUse[curr.op1.VR] && (curr.opcode < ADD || curr.opcode > RSHIFT || readCache.get(i) != lastUse[curr.op2.VR])) {
                        readDependencies.add(readCache.get(i));
                    }
                }
            }
            if (writeCache.size() > 0) {
                for (int i = Math.max(writeMap.get(latest), readMap.get(writeStart)); i < writeCache.size(); i++) {
                    if (writeCache.get(i) != lastUse[curr.op1.VR] && (curr.opcode < ADD || curr.opcode > RSHIFT || writeCache.get(i) != lastUse[curr.op2.VR])) {
                        writeDependencies.add(writeCache.get(i));
                    }
                }
            }
            node.readDependencies = readDependencies;
            node.writeDependencies = writeDependencies;
        }
        lastUse[curr.op3.VR] = index;
    }

    public void addSerializationEdge(IRRow curr, DependencyNode node) {
        for (Integer i : node.readDependencies) {
            node.parents.put(graph.get(i), new EdgeData(1));
            graph.get(i).children.put(node, new EdgeData(1));
        }
        for (Integer i : node.writeDependencies) {
            node.parents.put(graph.get(i), new EdgeData(1));
            graph.get(i).children.put(node, new EdgeData(1));
        }
    }

    public void addConflictEdge(IRRow curr, DependencyNode node) {
        if (curr.opcode == OUTPUT) {
            node.writeDependencies.addAll(writeCache);
        }
        for (Integer i : node.writeDependencies) {
            node.parents.put(graph.get(i), new EdgeData(2));
            graph.get(i).children.put(node, new EdgeData(2));
        }
    }

    public void printGraph() {
        for (int i = 0; i < graph.size(); i++) {
            DependencyNode node = graph.get(i);
            System.out.println((i + 1) + ": " + node.operation.toILOCString());
            System.out.println("Dependencies:");
            for (DependencyNode parent : node.parents.keySet()) {
                String type = node.parents.get(parent).type == 0 ? "Data" : (node.parents.get(parent).type == 2 ? "Conflict" : "Serialization");
                int idx = graph.indexOf(parent);
                System.out.println(type + " (" + (idx + 1) + ")" + ": " + parent.operation.toILOCString());
            }
            System.out.println("");
        }
    }
    
}
