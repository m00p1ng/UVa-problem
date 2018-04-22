import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        int n;
        BigInteger a, b;
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            n = s.nextInt();
            if(n == 0) break;

            a = s.nextBigInteger();
            b = s.nextBigInteger();

            a = new BigInteger(a.toString(), n);
            b = new BigInteger(b.toString(), n);

            System.out.println((a.mod(b)).toString(n));
        }
    }
}
