import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger f(int t, int a, int b) {
        BigInteger base = BigInteger.valueOf(t);
        BigInteger up = (base.pow(a)).subtract(BigInteger.ONE);
        BigInteger down = (base.pow(b)).subtract(BigInteger.ONE);
        return up.divide(down); 
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int t, a, b;
        BigInteger ans = BigInteger.ZERO;
        while(s.hasNext()) {
            t = s.nextInt();
            a = s.nextInt();
            b = s.nextInt();

            System.out.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);

            if(t == 1) {
                System.out.println("is not an integer with less than 100 digits.");
            } else if(a == b) {
                System.out.println("1");
            } else if(a < b || a % b != 0 || t == 1 || (a-b)*Math.log10(t) > 100) {
                System.out.println("is not an integer with less than 100 digits.");
            } else {
                System.out.println(f(t, a, b));
            }
        }
    }
}
