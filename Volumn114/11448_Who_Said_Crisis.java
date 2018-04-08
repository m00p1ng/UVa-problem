import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int testcase = s.nextInt();

        for(int i = 0; i < testcase; i++) {
            BigInteger a = s.nextBigInteger();
            BigInteger b = s.nextBigInteger();

            System.out.println(a.subtract(b));
        }
    }
}

