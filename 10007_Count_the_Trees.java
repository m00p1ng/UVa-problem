import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger catalan[] = new BigInteger[301];

    public static void genCatalan() {
        catalan[0] = BigInteger.ONE;
        catalan[1] = BigInteger.ONE;
        for(int n = 2; n <= 300; n++) {
            catalan[n] = BigInteger.ZERO;
            for(int i = 0; i < n; i++) {
                catalan[n] = catalan[n].add(catalan[i].multiply(catalan[n-i-1]));
            }
        }
        permutation();
    }

    public static void permutation() {
        BigInteger fac = BigInteger.ONE;
        for(int i = 2; i <= 300; i++) {
            fac = fac.multiply(BigInteger.valueOf(i));
            catalan[i] = catalan[i].multiply(fac);
        }
    }

    public static void main(String args[]) {
        genCatalan();
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int n = s.nextInt();
            if(n == 0) break;
            System.out.println(catalan[n]);
        }
    }
}

