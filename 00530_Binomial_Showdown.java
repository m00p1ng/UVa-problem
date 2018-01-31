import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger fac[] = new BigInteger[10000];

    public static void genFac() {
        fac[0] = fac[1] = BigInteger.ONE;
        for(int i = 2; i < 10000; i++) {
            fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
        }
    }
    
    public static BigInteger binomial(int n, int k) {
        BigInteger result = BigInteger.ONE;

        if(k > (n/2)) k = n-k;

        if(n >= 10000 || k >= 10000) {
            for(int i = 0; i < k; i++) {
                result = result.multiply(BigInteger.valueOf(n));
                n--;
            }
            return result.divide(fac[k]);
        }

        return fac[n].divide(fac[k].multiply(fac[n-k]));
    }

    public static void main(String args[]) {
        genFac();
        int n, k;
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            n = s.nextInt();
            k = s.nextInt();
            if(n == 0 && k == 0) break;
            System.out.println(binomial(n, k));
        }
    }
}
