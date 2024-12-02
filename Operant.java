public class Operant {
    public int SR;
    public int VR;
    public int PR;
    public int NU;

    public Operant(int sr) {
        SR = sr;
        VR = -1;
        PR = -1;
        NU = -1;
    }

    public Operant(int sr, int pr) {
        SR = pr;
        VR = -1;
        PR = pr;
        NU = -1;
    }

    public String toString() {

        return "[SR: " + (SR == -1 ? "-" : SR)  + 
                ", VR: " + (VR == -1 ? "-" : VR) + 
                ", PR: " + (PR == -1 ? "-" : PR) + 
                ", NU: " + (NU == -1 ? "-" : NU) + "] ";
    }
}