import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        BigInteger a, b;
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            a = s.nextBigInteger();
            b = s.nextBigInteger();
            
            System.out.println(a.multiply(b));
        }
    }
}
