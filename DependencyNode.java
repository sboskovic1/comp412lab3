import java.util.*;

public class DependencyNode {

    public static final int DATA = 0;
    public static final int SERIALIZATION = 1;
    public static final int CONFLICT = 2;

    public IRRow operation;
    public Map<DependencyNode, EdgeData> parents;
    public Map<DependencyNode, EdgeData> children;
    public Set<Integer> readDependencies;
    public Set<Integer> writeDependencies;
    public int index;

    public DependencyNode(int index, IRRow operation) {
        parents = new HashMap<DependencyNode, EdgeData>();
        children = new HashMap<DependencyNode, EdgeData>();
        readDependencies = new HashSet<Integer>();
        writeDependencies = new HashSet<Integer>();
        this.index = index;
        this.operation = operation;

    }


}
