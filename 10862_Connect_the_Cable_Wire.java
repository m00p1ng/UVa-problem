import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger wire[] = new BigInteger[2001];

    public static void gen_wire() {
        BigInteger fibo[] = new BigInteger[3];
        wire[0] = fibo[0] = BigInteger.ZERO;
        wire[1] = fibo[1] = BigInteger.ONE;

        for(int i = 2; i <= 2000; i++) {
            fibo[2] = fibo[0].add(fibo[1]);
            fibo[0] = fibo[1];
            fibo[1] = fibo[2];

            fibo[2] = fibo[0].add(fibo[1]);
            fibo[0] = fibo[1];
            fibo[1] = fibo[2];

            wire[i] = fibo[0].add(fibo[1]);
        }
    }

    public static void main(String args[]) {
        gen_wire();
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int n = s.nextInt();
            if(n == 0) break;

            System.out.println(wire[n]);
        }
    }
}

