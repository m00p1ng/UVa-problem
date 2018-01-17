import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger buet(int n, int a) {
        BigInteger sum = BigInteger.ZERO;

        BigInteger ba = BigInteger.valueOf(a);
        for(int i = 1; i <= n; i++) {
            sum = sum.add((BigInteger.valueOf(i)).multiply(ba.pow(i)));
        }
        return sum;
    }

    public static void main(String args[]) {
        int n, a;

        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            n = s.nextInt();
            a = s.nextInt();

            System.out.println(buet(n, a)); 
        }
    }
}
