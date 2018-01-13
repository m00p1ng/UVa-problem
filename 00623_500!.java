import java.math.BigInteger;
import java.util.Scanner;


class Main {
    static BigInteger fac[] = new BigInteger[1010];

    public static void genFactorial() {
        fac[0] = fac[1] = BigInteger.ONE;    

        for(int i = 2; i <= 1000; i++) {
            fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
        }
    }

    public static void main(String args[]) {
        int n;
        genFactorial();
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            n = s.nextInt(); 

            System.out.println(n + "!");
            System.out.println(fac[n].toString());
        }
    }
}
