import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger catalan[] = new BigInteger[1001];

    public static void genCatalan() {
        catalan[0] = BigInteger.ONE;
        catalan[1] = BigInteger.ONE;
        for(int n = 2; n <= 1000; n++) {
            catalan[n] = BigInteger.ZERO;
            for(int i = 0; i < n; i++) {
                catalan[n] = catalan[n].add(catalan[i].multiply(catalan[n-i-1]));
            }
        }
    }

    public static void main(String args[]) {
        genCatalan();
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            int n = s.nextInt();
            System.out.println(catalan[n]);
        }
    }
}

