import java.util.Scanner;
import java.math.BigInteger;

class Main {
    static BigInteger fibo[] = new BigInteger[5100];

    public static void genFibo() {
        fibo[1] = fibo[2] = BigInteger.ONE;    
        
        for(int i = 3; i < 5100; i++) {
            fibo[i] = fibo[i-1].add(fibo[i-2]);
        }
    }

    public static void main(String args[]) {
        genFibo();
        Scanner s = new Scanner(System.in);

        int n;

        while(s.hasNext()) {
            n = s.nextInt();
            System.out.println(fibo[n]);
        }
    }
}
