import java.io.*;
import java.util.*;

/** 
 * The scanner should be incremental. That is, the parser calls the scanner each time it needs the next word. The scanner, when called, looks at successive characters in the input stream, finds the next word, updates its state (see note 1) and returns the word.  
 * 
 * Read the input
 * Recognize all of the words
 * Producing tokens
 * Printing error messages for lexical errors and spelling mistakes
 */
public class Scanner {

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


    public Map<String, Integer> words;
    public BufferedReader input;
    private boolean newLine;
    private int lineLength;
    private int lineIndex;
    private char[] line;
    private int lastWord;

    // public Map<Character, Integer> letters;

    public Scanner(String filepath) {
        words = new HashMap<String, Integer>();
        words.put("r", REGISTER);
        words.put("=>", INTO);
        words.put("load", LOAD);
        words.put("loadi", LOADI);
        words.put("store", STORE);
        words.put("add", ADD);
        words.put("sub", SUB);
        words.put("mult", MULT);
        words.put("lshift", LSHIFT);
        words.put("rshift", RSHIFT);
        words.put("output", OUTPUT);
        words.put("nop", NOP);
        words.put(",", COMMA);

        // letters = new HashMap<Character, Integer>();
        // letters.put('r', 0);
        // letters.put('l', 0);
        // letters.put('s', 0);
        // letters.put('m', 0);
        // letters.put('a', 0);
        // letters.put('=', 0);
        // letters.put('o', 0);
        // letters.put('n', 0);
        // letters.put(',', 0);

        newLine = true;
        lineLength = 0;
        lineIndex = 0;
        lastWord = -1;

        try {
            input = new BufferedReader(new FileReader(filepath));
        } catch (IOException e) {
            System.err.println("ERROR: File not found");
            throw new RuntimeException();
        }
    }

    public int nextWord() {
        switch (line[lineIndex]) {
            case 'r':
                // letters.put('r', letters.get('r') + 1);
                if (lineIndex + 1 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (Character.isDigit(line[lineIndex])) {
                    return REGISTER;
                }
                if (checkShift() == 1) {
                    return RSHIFT;
                }
                return SCAN_ERROR;
            case '=':
                // letters.put('=', letters.get('=') + 1);
                if (lineIndex + 1 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (line[lineIndex] == '>') {
                    lineIndex++;
                    return INTO;
                }
                return SCAN_ERROR;
            case 'a':
                // letters.put('a', letters.get('a') + 1);
                if (lineIndex + 2 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (line[lineIndex] == 'd') {
                    lineIndex++;
                    if (line[lineIndex] == 'd') {
                        lineIndex++;
                        return ADD;
                    }
                }
                return SCAN_ERROR;
            case ',':
                // letters.put(',', letters.get(',') + 1);
                lineIndex++;
                return COMMA;
            case 'l':
                // letters.put('l', letters.get('l') + 1);
                if (lineIndex + 3 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (line[lineIndex] == 'o') {
                    lineIndex++;
                    if (line[lineIndex] == 'a') {
                        lineIndex++;
                        if (line[lineIndex] == 'd') {
                            lineIndex++;
                            if (lineIndex < lineLength && line[lineIndex] == 'I') {
                                lineIndex++;
                                return LOADI;
                            } else {
                            return LOAD;
                            }
                        }
                    }
                } else if (checkShift() == 1) {
                    return LSHIFT;
                }
                return SCAN_ERROR;
            case 's':
                // letters.put('s', letters.get('s') + 1);
                lineIndex++;
                if (lineIndex + 2 >= lineLength) {
                    return SCAN_ERROR;
                }
                if (line[lineIndex] == 't' && lineIndex + 3 < lineLength) {
                    lineIndex++;
                    if (line[lineIndex] == 'o') {
                        lineIndex++;
                        if (line[lineIndex] == 'r') {
                            lineIndex++;
                            if (line[lineIndex] == 'e') {
                                lineIndex++;
                                return STORE;
                            }
                        }
                    }
                } else if (line[lineIndex] == 'u') {
                    lineIndex++;
                    if (line[lineIndex] == 'b') {
                        lineIndex++;
                        return SUB;
                    }
                }
                return SCAN_ERROR;
            case 'm':
                // letters.put('m', letters.get('m') + 1);
                if (lineIndex + 3 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (line[lineIndex] == 'u') {
                    lineIndex++;
                    if (line[lineIndex] == 'l') {
                        lineIndex++;
                        if (line[lineIndex] == 't') {
                            lineIndex++;
                            return MULT;
                        }
                    }
                }
                return SCAN_ERROR;
            case 'o':
                // letters.put('o', letters.get('o') + 1);
                if (lineIndex + 4 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (line[lineIndex] == 'u') {
                    lineIndex++;
                    if (line[lineIndex] == 't') {
                        lineIndex++;
                        if (line[lineIndex] == 'p') {
                            lineIndex++;
                            if (line[lineIndex] == 'u') {
                                lineIndex++;
                                if (line[lineIndex] == 't') {
                                    lineIndex++;
                                    return OUTPUT;
                                }
                            }
                        }
                    }
                }
                return SCAN_ERROR;
            case 'n':
                // letters.put('n', letters.get('n') + 1);
                if (lineIndex + 2 >= lineLength) {
                    return SCAN_ERROR;
                }
                lineIndex++;
                if (line[lineIndex] == 'o') {
                    lineIndex++;
                    if (line[lineIndex] == 'p') {
                        lineIndex++;
                        return NOP;
                    }
                }
                return SCAN_ERROR;
        }
        return SCAN_ERROR;
    }

    public int nextConstant(int lineNumber) {
        int constant = 0;
        while (lineIndex < lineLength && (line[lineIndex] == ' ' || line[lineIndex] == 9)) {
            lineIndex++;
        }
        if (lineIndex >= lineLength) {
            return SCAN_ERROR;
        }
        try {
            constant = Integer.parseInt(line[lineIndex] + "");
            lineIndex++;
            while (lineIndex < lineLength && line[lineIndex] != 9 && line[lineIndex] != ',' && line[lineIndex] != '=' && line[lineIndex] != 32) {
                if (!Character.isDigit(line[lineIndex])) {
                    if (line[lineIndex] == '/' && lineIndex + 1 < lineLength && line[lineIndex + 1] == '/') {
                        return constant * -1;
                    }
                    System.err.println("ERROR " + lineNumber + ": Expected a number but found " + line[lineIndex]);
                    return 15;
                }
                constant = constant * 10 + Integer.parseInt(line[lineIndex] + "");
                lineIndex++;
            }
        } catch (NumberFormatException e) {
            System.err.println("ERROR " + lineNumber + ": Expected a number, found " + line[lineIndex]);
            return -1;
        }
        return constant * -1;

    }

    public int nextSymbol(int lineNumber) {
        if (newLine) {
            try {
                String lineStr = input.readLine();
                if (lineStr == null) {
                    return EOF;
                } else {
                    line = lineStr.toCharArray();
                }
                lineLength = line.length;
                lineIndex = 0;
                newLine = false;
            } catch (IOException e) {
                System.err.println("ERROR " + lineNumber + ": Could not open filename");
                throw new RuntimeException();
            }
        }
        if (lineIndex >= lineLength) {
            newLine = true;
            lastWord = -1;
            return EOL;
        }
        int word = -1;
        if (lastWord == LOADI || lastWord == REGISTER || lastWord == OUTPUT) {
            word = nextConstant(lineNumber);
        } else {
            if (line[lineIndex] == ' ' || line[lineIndex] == 9) {
                while (lineIndex < lineLength && (line[lineIndex] == ' ' || line[lineIndex] == 9)) {
                    lineIndex++;
                }
                if (lineIndex >= lineLength) {
                    newLine = true;
                    lastWord = -1;
                    return EOL;
                }
            } else if (lineIndex != 0 && line[lineIndex] != ',' && lastWord != INTO && lastWord != COMMA && !((lastWord == REGISTER || lastWord < 0) && line[lineIndex] == '=') && line[lineIndex] != '/') {
                while (lineIndex < lineLength && line[lineIndex] != ' ') {
                    lineIndex++;
                }
                return SCAN_ERROR;
            }
            if (lineIndex + 1 < lineLength && line[lineIndex] == '/' && line[lineIndex + 1] == '/') {
                newLine = true;
                lastWord = -1;
                return EOL;
            }
            word = nextWord();
        }
        lastWord = word;
        if (word == SCAN_ERROR) {
            while (lineIndex < lineLength && line[lineIndex] != ' ') {
                lineIndex++;
            }
            if (lineIndex >= lineLength) {
                lastWord = EOL;
            }
        }
        return word;
    }

    private int checkShift() {
        if (lineIndex + 4 >= lineLength) {
            return SCAN_ERROR;
        }
        if (line[lineIndex] == 's') {
            lineIndex++;
            if (line[lineIndex] == 'h') {
                lineIndex++;
                if (line[lineIndex] == 'i') {
                    lineIndex++;
                    if (line[lineIndex] == 'f') {
                        lineIndex++;
                        if (line[lineIndex] == 't') {
                            lineIndex++;
                            return 1;
                        }
                    }
                }
            }
        }
        return 2;
    }

    public boolean endOfLine() {
        return (lineIndex >= lineLength) && (lastWord != EOL);
    }
}