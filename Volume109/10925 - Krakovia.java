import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n, f;
        int cnt = 0;
        BigInteger result;

        while(true) {
            if(cnt > 0) System.out.println();
            n = s.nextInt();
            f = s.nextInt();
            if(n == 0 || f == 0) break;
            
            result = BigInteger.ZERO;
            for(int i = 0; i < n; i++) {
                result = result.add(s.nextBigInteger());     
            }
            System.out.printf("Bill #%d costs %s: each friend should pay %s\n", ++cnt, result.toString(), (result.divide(BigInteger.valueOf(f)).toString()));
        }
    }
}
