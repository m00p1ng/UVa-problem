import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        int n, d;

        Scanner s = new Scanner(System.in);
        BigInteger result;

        while(s.hasNext()) {
            n = s.nextInt();
            d = s.nextInt();
            if(n == 0 && d == 0) break;
            result = BigInteger.ONE;

            for(int i = 0; i < d; i++) {
                result = result.multiply(BigInteger.valueOf(n));
            }
            System.out.println(result);
        }
    }
}
