import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        int t, a, b;
        Scanner s = new Scanner(System.in);
 
        BigInteger base, up, down;
        BigInteger sum = BigInteger.ZERO;
        BigInteger ONE = BigInteger.ONE;
        while(s.hasNext()) {
            t = s.nextInt();
            a = s.nextInt();
            b = s.nextInt();

            System.out.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
            if(t == 1) {
                System.out.println("is not an integer with less than 100 digits.");
            } else if(a == b) {
                System.out.println("1");
            } else if(a % b == 0) {
                base = BigInteger.valueOf(t);
                up = (base.pow(a)).subtract(ONE); 
                down = (base.pow(b)).subtract(ONE);
                sum = up.divide(down);
                if((sum.toString()).length() <= 100) {
                    System.out.println(sum);
                } else {
                    System.out.println("is not an integer with less than 100 digits.");
                }
            } 
        }
    }
}
