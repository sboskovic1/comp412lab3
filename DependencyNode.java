import java.util.*;

public class DependencyNode {

    public static final int DATA = 0;
    public static final int SERIALIZATION = 1;
    public static final int CONFLICT = 2;

    public IRRow operation;
    public Map<DependencyNode, EdgeData> parents;
    public Map<DependencyNode, EdgeData> children;


}
