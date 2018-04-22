import java.util.Scanner;
import java.math.BigInteger;

class Main {
    static BigInteger fac[] = new BigInteger[400];
    public static void genFac() {
        fac[0] = fac[1] = BigInteger.ONE;
        for(int i = 2; i <= 366; i++) {
            fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
        }
    }

    public static void main(String args[]) {
        genFac();

        int n;
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            n = s.nextInt();
            String strFac = fac[n].toString();
            int len = (strFac).length();
            int freq[] = new int[10];

            for(int i = 0; i < len; i++) {
                freq[strFac.charAt(i)-'0']++;
            }

            System.out.printf("%d! --\n", n);
            for(int i = 0; i < 5; i++) {
                System.out.printf("(%d) %d ", i, freq[i]);
            }
            System.out.println();
            for(int i = 5; i < 10; i++) {
                System.out.printf("(%d) %d ", i, freq[i]);
            }
            System.out.println();
        }
    }
}
