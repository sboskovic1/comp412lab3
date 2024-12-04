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

    final Map<Integer, Integer> priorities;

    public int[] lastUse;
    public int index;
    public List<Integer> readCache;
    public List<Integer> writeCache;
    public Map<Integer, Integer> readMap;
    public Map<Integer, Integer> writeMap;

    public Set<DependencyNode> leaves;
    public Set<DependencyNode> roots;

    public int readStart;
    public int writeStart;


    public DependencyGraph(int maxReg) {
        graph = new ArrayList<DependencyNode>();
        index = 0;
        readCache = new ArrayList<Integer>();
        writeCache = new ArrayList<Integer>();
        writeMap = new HashMap<Integer, Integer>();
        readMap = new HashMap<Integer, Integer>();
        roots = new HashSet<DependencyNode>();
        leaves = new HashSet<DependencyNode>();
        lastUse = new int[maxReg + 1];

        priorities = new HashMap<Integer, Integer>();
        priorities.put(NOP, 1);
        priorities.put(ADD, 1);
        priorities.put(SUB, 1);
        priorities.put(MULT, 3);
        priorities.put(LSHIFT, 1);
        priorities.put(RSHIFT, 1);
        priorities.put(LOAD, 6);
        priorities.put(LOADI, 1);
        priorities.put(STORE, 6);
        priorities.put(OUTPUT, 1);

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

        Set<DependencyNode> hasChildren = new HashSet<DependencyNode>();

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
                    node.parents.put(graph.get(latestOutput), 1);
                    graph.get(latestOutput).children.put(node, 1);
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
            if (node.parents.size() == 0) {
                roots.add(node);
            } else {
                hasChildren.addAll(node.parents.keySet());
            }

            curr = curr.next;
            index++;
        }
        leaves = new HashSet<DependencyNode>(graph);
        leaves.removeAll(hasChildren);
    }

    public void addDataEdge(IRRow curr, DependencyNode node) {
        Set<Integer> readDependencies = new HashSet<Integer>();
        Set<Integer> writeDependencies = new HashSet<Integer>();
        int latest = -1;
        if (curr.opcode != LOADI) {
            if (lastUse[curr.op1.VR] != -1) {
                node.parents.put(graph.get(lastUse[curr.op1.VR]), 0);
                graph.get(lastUse[curr.op1.VR]).children.put(node, 0);
            }
            if (curr.opcode >= ADD && curr.opcode <= RSHIFT) {
                if (lastUse[curr.op2.VR] != -1) {
                    node.parents.put(graph.get(lastUse[curr.op2.VR]), 0);
                    graph.get(lastUse[curr.op2.VR]).children.put(node, 0);
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
                    if (readCache.get(i) != lastUse[curr.op1.VR] && (curr.opcode < ADD || curr.opcode > RSHIFT || readCache.get(i) != lastUse[curr.op3.VR])) {
                        readDependencies.add(readCache.get(i));
                    }
                }
            }
            if (writeCache.size() > 0) {
                for (int i = Math.max(writeMap.get(latest), writeMap.get(writeStart)); i < writeCache.size(); i++) {
                    if (writeCache.get(i) != lastUse[curr.op1.VR] && (curr.opcode < ADD || curr.opcode > RSHIFT || writeCache.get(i) != lastUse[curr.op3.VR])) {
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
            node.parents.put(graph.get(i), 1);
            graph.get(i).children.put(node, 1);
        }
        for (Integer i : node.writeDependencies) {
            node.parents.put(graph.get(i), 1);
            graph.get(i).children.put(node, 1);
        }
    }

    public void addConflictEdge(IRRow curr, DependencyNode node) {
        if (curr.opcode == OUTPUT) {
            node.writeDependencies.addAll(writeCache);
        }
        for (Integer i : node.writeDependencies) {
            node.parents.put(graph.get(i), 2);
            graph.get(i).children.put(node, 2);
        }
    }

    public void setPriorities() {
        List<DependencyNode> stack = new ArrayList<>();
        stack.addAll(leaves);
        while (stack.size() > 0) {
            DependencyNode node = stack.remove(stack.size() - 1);
            if (leaves.contains(node)) {
                node.priority = priorities.get(node.operation.opcode);
                stack.addAll(node.parents.keySet());
            } else {
                for (DependencyNode child : node.children.keySet()) {
                    if (node.priority < child.priority + priorities.get(node.operation.opcode)) {
                        node.priority = child.priority + priorities.get(node.operation.opcode);
                    }
                }
                stack.addAll(node.parents.keySet());
            }
        }
    }

    public List<String> schedule() {
        List<DependencyNode> rootList = new ArrayList<>();
        rootList.addAll(roots);
        rootList.sort((a, b) -> a.priority - b.priority);
        NodeLinkedList ready = null;
        for (DependencyNode node : rootList) {
            ready = pushNode(new NodeLinkedList(node), ready);
        }
        Map<DependencyNode, Integer> active = new HashMap<>();
        List<String> scheduled = new ArrayList<String>();
        int cycle = 1;
        boolean f0output = false;
        boolean f0mult = false;
        boolean f0storeload = false;
        while (ready != null || active.size() != 0) {
            String line = "";
            //f0
            NodeLinkedList[] results = popNode(ready);
            NodeLinkedList node = results[0];
            ready = results[1];
            if (node == null) {
                line += "nop ";
            } else {
                switch (node.node.operation.opcode) {
                    case MULT:
                        f0mult = true;
                        break;
                    case LOAD:
                        f0storeload = true;
                        break;
                    case STORE:
                        f0storeload = true;
                        break;
                    case OUTPUT:
                        f0output = true;
                        break;
                }
                line += node.node.operation.toILOCString();
                active.put(node.node, priorities.get(node.node.operation.opcode));
            }
            //f1
            if (f0mult) {
                results = popNode0(ready);
            } else if (f0storeload) {
                results = popNode1(ready);
            } else if (f0output) {
                results = popNodeOutput(ready);
            } else {
                results = popNode(ready);
            }
            node = results[0];
            ready = results[1];
            if (f0mult) {
                if (node == null) {
                    line = "nop ; " + line;
                } else {
                    line = node.node.operation.toILOCString() + " ; " + line;
                    active.put(node.node, priorities.get(node.node.operation.opcode));
                }
            } else {
                if (node == null) {
                    line += " ; nop";
                } else {
                    line += " ; " + node.node.operation.toILOCString();
                    active.put(node.node, priorities.get(node.node.operation.opcode));
                }
            }
            line = "[ " + line + " ]";

            Set<DependencyNode> toRemove = new HashSet<>();
            for (Map.Entry<DependencyNode, Integer> entry : active.entrySet()) {
                DependencyNode key = entry.getKey();
                Integer value = entry.getValue() - 1;
                if (value == 0) {
                    toRemove.add(key);
                    for (DependencyNode child : key.children.keySet()) {
                        child.parents.remove(key);
                        if (child.parents.size() == 0) {
                            ready = pushNodeByPriority(new NodeLinkedList(child), ready);
                        }
                    }
                } else {
                    active.put(key, value);
                }
            }
            for (DependencyNode nodeToRemove : toRemove) {
                active.remove(nodeToRemove);
            }

            //output
            f0output = false;
            f0mult = false;
            f0storeload = false;
            scheduled.add(line);
            cycle++;
        }
        return scheduled;
    }

    public void printGraph(boolean priorities, boolean dependencies) {
        for (int i = 0; i < graph.size(); i++) {
            DependencyNode node = graph.get(i);
            System.out.println((i + 1) + ": " + node.operation.toILOCString());
            if (priorities) {
                System.out.println("Priority: " + node.priority);
            }
            if (dependencies) {
                System.out.println("Dependencies:");
                for (DependencyNode parent : node.parents.keySet()) {
                    String type = node.parents.get(parent) == 0 ? "Data" : (node.parents.get(parent) == 2 ? "Conflict" : "Serialization");
                    int idx = graph.indexOf(parent);
                    System.out.println(type + " (" + (idx + 1) + ")" + ": " + parent.operation.toILOCString());
                }
            }
            System.out.println("");
        }
    }

    public NodeLinkedList pushNode(NodeLinkedList node, NodeLinkedList head) {
        if (head == null) {
            head = node;
        } else {
            node.next = head;
            head.prev = node;
            head = node;
        }
        return head;
    }

    public NodeLinkedList pushNodeByPriority(NodeLinkedList node, NodeLinkedList head) {
        if (head == null) {
            head = node;
        } else {
            NodeLinkedList temp = head;
            NodeLinkedList last = null;
            while (temp != null && temp.node.priority > node.node.priority) {
                last = temp;
                temp = temp.next;
            }
            if (temp == null) {
                temp = node;
                last.next = node;
                node.prev = last;
            } else if (last == null) { // Check this
                node.next = temp;
                temp.prev = node;
                head = node;
            } else {
                node.next = temp;
                node.prev = temp.prev;
                temp.prev.next = node;
                temp.prev = node;
            }
        }
        return head;
    }

    public NodeLinkedList[] popNode(NodeLinkedList head) {
        NodeLinkedList temp = head;
        if (temp == null) {
            return new NodeLinkedList[]{null, head};
        }
        if (temp == head) {
            head = temp.next;
        } else {
            temp.prev.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            }
        }
        return new NodeLinkedList[]{temp, head};
    }

    public NodeLinkedList[] popNode0(NodeLinkedList head) {
        NodeLinkedList temp = head;
        while (temp != null && temp.node.operation.opcode == MULT) {
            temp = temp.next;
        }
        if (temp == null) {
            return new NodeLinkedList[]{null, head};
        }
        if (temp == head) {
            head = temp.next;
        } else {
            temp.prev.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            }
        }
        return new NodeLinkedList[]{temp, head};
    }

    public NodeLinkedList[] popNode1(NodeLinkedList head) {
        NodeLinkedList temp = head;
        while (temp != null && (temp.node.operation.opcode == LOAD || temp.node.operation.opcode == STORE)) {
            temp = temp.next;
        }
        if (temp == null) {
            return new NodeLinkedList[]{null, head};
        }
        if (temp == head) {
            head = temp.next;
        } else {
            temp.prev.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            }
        }
        return new NodeLinkedList[]{temp, head};
    }

    public NodeLinkedList[] popNodeOutput(NodeLinkedList head) {
        NodeLinkedList temp = head;
        while (temp != null && temp.node.operation.opcode == OUTPUT) {
            temp = temp.next;
        }
        if (temp == null) {
            return new NodeLinkedList[]{null, head};
        }
        if (temp == head) {
            head = temp.next;
        } else {
            temp.prev.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            }
        }
        return new NodeLinkedList[]{temp, head};
    }

    public void printReady(NodeLinkedList ready) {
        NodeLinkedList temp = ready;
        while (temp != null) {
            System.out.println(temp.node.operation.toILOCString());
            temp = temp.next;
        }
    }

    private class NodeLinkedList {
        public DependencyNode node;
        public NodeLinkedList next;
        public NodeLinkedList prev;

        public NodeLinkedList(DependencyNode node) {
            this.node = node;
            this.next = null;
            this.prev = null;
        }

    }
    
}
