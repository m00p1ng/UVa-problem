import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        BigInteger a, b;
        char c;
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            a = s.nextBigInteger();
            c = s.next().charAt(0);
            b = s.nextBigInteger();

            if(c == '/') {
                System.out.println(a.divide(b));
            } else {
                System.out.println(a.mod(b));
            }
        }
    }
}
