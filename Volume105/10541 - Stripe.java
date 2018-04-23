import java.util.Scanner;
import java.math.BigInteger;

class Main {
    static BigInteger bino[][] = new BigInteger[210][210];

    public static void genBinomial() {
        for(int i = 0; i <= 200; i++) {
            bino[i][0] = BigInteger.ONE;
            bino[i][i] = BigInteger.ONE;
        }
        for(int i = 1; i <= 200; i++) {
            for(int j = 1; j < i; j++) {
                bino[i][j] = bino[i-1][j-1].add(bino[i-1][j]);
            }
        }
    }

    public static void main(String args[]) {
        genBinomial();
        Scanner s = new Scanner(System.in);

        int ts = s.nextInt();
        int n, k, nRemain, temp;

        for(int t = 0; t < ts; t++) {
            n = s.nextInt();
            k = s.nextInt();
            nRemain = n;

            for(int i = 0; i < k; i++) {
                temp = s.nextInt();
                nRemain -= temp;
            }
            if(nRemain+1 < k) {
                System.out.println("0");
            } else {
                System.out.println(bino[nRemain+1][k]);
            }
        }
    }
}
