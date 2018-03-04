import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        int ts;
        BigInteger a, b, c;
        Scanner s = new Scanner(System.in);

        ts = s.nextInt();

        for(int i = 0; i < ts; i++) {
            a = s.nextBigInteger(); 
            s.next();
            b = s.nextBigInteger(); 
            c = a.gcd(b);
            System.out.println(a.divide(c) + " / " + b.divide(c));
        }
    }
}
