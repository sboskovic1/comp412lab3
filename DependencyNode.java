import java.util.*;

public class DependencyNode {

    public static final int DATA = 0;
    public static final int SERIALIZATION = 1;
    public static final int CONFLICT = 2;

    public IRRow operation;
    public Map<DependencyNode, Integer> parents;
    public Map<DependencyNode, Integer> children;
    public Set<Integer> readDependencies;
    public Set<Integer> writeDependencies;
    public int index;

    public int priority;

    public DependencyNode(int index, IRRow operation) {
        parents = new HashMap<DependencyNode, Integer>();
        children = new HashMap<DependencyNode, Integer>();
        readDependencies = new HashSet<Integer>();
        writeDependencies = new HashSet<Integer>();
        this.index = index;
        this.operation = operation;
        this.priority = -1;

    }


}
