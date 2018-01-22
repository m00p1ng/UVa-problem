import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger fibo[] = new BigInteger[1001];

    public static void gen_fibo() {
        fibo[0] = BigInteger.ONE;
        fibo[1] = BigInteger.valueOf(2);
        for(int i = 2; i <= 1000; i++) {
            fibo[i] = fibo[i-1].add(fibo[i-2]);
        }
    }

    public static void main(String args[]) {
        gen_fibo();
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int n = s.nextInt();

            System.out.println(fibo[n]);
        }
    }
}

