public class Frontend {

    static final String helpMessage = "COMP 412, Fall 2024, Front End by Stefan Boskovic (sb121)\r\n" + //
                "Command Syntax:\r\n" + //
                "        ./lab1_ref [flags] filename\r\n" + //
                "\r\n" + //
                "Required arguments:\r\n" + //
                "        filename  is the pathname (absolute or relative) to the input file\r\n" + //
                "\r\n" + //
                "At most one of the following three flags:\r\n" + //
                "        -h       prints the help message, ignoring any file passed as 'filename'\r\n" + //
                "        -s       prints tokens in token stream\r\n" + //
                "        -p       invokes parser and reports on success or failure\r\n" + //
                "        -r       prints human readable version of parser's IR\r\n" + //
                "If none is specified, the default action is '-p'.";
    public static Parser run(String token, String file) {

        if (token.equals("-h")) {
            System.out.println(helpMessage);
            return null;
        } 

        Parser parser = null;
        int flag = -1;
        switch (token) {
            case "-s":
                flag = 0;
                break;
            case "-p":
                flag = 1;
                break;
            case "-r":
                flag = 2;
                break;
            case "-x":
                flag = 3;
                break;
        }
        try {
            if (flag == -1) {
                parser = new Parser(file, 1);
            } else {
                parser = new Parser(file, flag);
            }

        } catch (RuntimeException e) {
            return null;
        }
        parser.parse();

        return parser;
    }
}