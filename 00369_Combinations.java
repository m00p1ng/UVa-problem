import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger fac(int n) {
        BigInteger out = BigInteger.ONE;

        for(int i = 2; i <= n; i++) {
            out = out.multiply(BigInteger.valueOf(i));
        }
        return out;
    }

    public static void main(String args[]) {
        int n, m;
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            n = s.nextInt();
            m = s.nextInt();

            if(n == 0 || m == 0) break;

            BigInteger result = fac(n).divide(fac(n-m).multiply(fac(m)));
            System.out.printf("%d things taken %d at a time is %s exactly.\n", n , m, result.toString());
        }

    }
}
