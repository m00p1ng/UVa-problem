import java.math.BigInteger;
import java.util.Scanner;

class Main {
    static BigInteger fibo[] = new BigInteger[5010];

    public static void genFibo() {
        fibo[0] = BigInteger.ZERO;
        fibo[1] = BigInteger.ONE;

        for(int i = 2; i <= 5000; i++) {
            fibo[i] = fibo[i-1].add(fibo[i-2]);
        }
    }

    public static void main(String args[]) {
        genFibo();
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int n = s.nextInt();
            System.out.printf("The Fibonacci number for %d is %s\n", n, fibo[n].toString());
        }
    }
}
