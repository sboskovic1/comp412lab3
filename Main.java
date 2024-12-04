import java.util.*;

public class Main {
    public static void main(String[] args) {

        final String helpMessage = "Stefan Boskovic: COMP 412 Allocator (lab 2)\r\n" + //
                        "Command Syntax:\r\n" + //
                        "        412alloc [f] filename\r\n" + //
                        "\r\n" + //
                        "Where [f] can be:\r\n" + //
                        "        k        specifies the number of registers available to the allocator\r\n" + //
                        "        -x        prints the renamed IR to the console\r\n" + //
                        "        -h        prints this help message\r\n" + //
                        "If [f] is left blank, the allocator will default to k = 32\r\n" + //
                        "filename  is the pathname (absolute or relative) to the input file\r\n";
        int regs;
        boolean regsFound = false;
        int flag = -1;
        if (args[0].equals("-x")) {
            flag = 0;
        } else if (args[0].equals("-h")) {
           System.out.println(helpMessage);
           return;
        }
        try {
            regs = Integer.parseInt(args[0]);
            regsFound = true;
        } catch (NumberFormatException e) {
            regs = 32;
        }
 
        Parser parser = null;

        if (regsFound) {
            parser = Frontend.run("-p", args[1]);
        } else {   
            parser = Frontend.run("-p", args[0]);
        }

        Renamer renamer = new Renamer(parser.head, parser.tail, parser.operations, regs, parser.maxReg);

        renamer.Rename();
        if (flag == 0) {
            renamer.printRenamedIR();
            return;
        }
        renamer.printRenamedIR();

        DependencyGraph graph = new DependencyGraph(renamer.vr);

        graph.buildGraph(renamer.head);

        // graph.printGraph();

        graph.setPriorities();

        // graph.printGraph(true, false);

        List<String> schedule = graph.schedule();
        
        for (String s : schedule) {
            System.out.println(s);
        }

        // Allocator allocator = new Allocator(parser.head, regs, renamer.vr, renamer.maxLive, 32768);

        // allocator.allocate();

    }
}
