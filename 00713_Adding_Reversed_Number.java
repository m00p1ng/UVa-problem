import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int testcase = s.nextInt();
        String a, b, out;
        BigInteger ba, bb;

        for(int t = 0; t < testcase; t++) {
            a = new StringBuffer(s.next()).reverse().toString();
            b = new StringBuffer(s.next()).reverse().toString();

            ba = new BigInteger(a);
            bb = new BigInteger(b);


            out = new StringBuffer(ba.add(bb).toString()).reverse().toString();
            out = out.replaceAll("^0+", "");
            System.out.println(out);
        }
    }
}
