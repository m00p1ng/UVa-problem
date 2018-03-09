import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger fibo[] = new BigInteger[501];

    public static void gen_fibo() {
        fibo[0] = BigInteger.ONE;
        fibo[1] = BigInteger.ONE;

        for(int i = 2; i < 500; i++) {
            fibo[i] = fibo[i-1].add(fibo[i-2]);
        }
    }

    public static int numberFib(BigInteger a, BigInteger b) {
        int count = 0;

        if(a.compareTo(BigInteger.ZERO) == 0 && b.compareTo(BigInteger.ONE) == 0) return 1;

        int idx = 1;
        while(a.compareTo(fibo[idx]) == 1) idx++;
        while(b.compareTo(fibo[idx]) != -1) {
            idx++;
            count++;
        }

        return count;
    }

    public static void main(String args[]) {
        gen_fibo();
        Scanner s = new Scanner(System.in);
        BigInteger a, b;

        while(s.hasNext()) {
            a = s.nextBigInteger();
            b = s.nextBigInteger();

            if(a.compareTo(BigInteger.ZERO) == 0 && b.compareTo(BigInteger.ZERO) == 0) break;

            System.out.println(numberFib(a, b));
        }
    }
}

