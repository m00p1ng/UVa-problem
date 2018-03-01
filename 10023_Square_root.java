import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger sqrt(BigInteger n) {
    final BigInteger ONE = BigInteger.ONE;
    int c;

    BigInteger n0 = ONE.shiftLeft(n.bitLength()>>1);
    BigInteger np = n;

    do {
        n0 = n0.add(n.divide(n0)).shiftRight(1);
        c = np.compareTo(n0);
        np = n0;
    }  while (c != 0);

    return n0;
}
    public static void main(String args[]) {
        int ts;
        BigInteger y;
        Scanner s = new Scanner(System.in);

        ts = s.nextInt();

        for(int i = 1; i <= ts; i++) {
            y = s.nextBigInteger();

            System.out.println(sqrt(y));
            if(i != ts) System.out.println();
        }
    }
}
