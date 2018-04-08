import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        BigInteger sum, n;
        BigInteger ONE = BigInteger.ONE;
        BigInteger TWO = new BigInteger("2");
        while(s.hasNext()) {
            n = s.nextBigInteger();
            sum = (n.multiply(n.subtract(ONE))).add(TWO);
            if(n.equals(BigInteger.ZERO)) sum = BigInteger.ONE;
            System.out.println(sum);
        }
    }
}
