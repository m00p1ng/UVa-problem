import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger fac[] = new BigInteger[1001];

    public static int digitSum(int n) {
        int sum = 0;
        String facc = fac[n].toString();

        for(int i = 0; i < facc.length(); i++) {
            sum += facc.charAt(i) - '0'; 
        }
        return sum;
    }

    public static void genFac() {
        fac[0] = fac[1] = BigInteger.ONE;
        for(int i = 2; i <= 1000; i++) {
            fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        genFac();

        while(s.hasNext()) {
            int n = s.nextInt();
            
            System.out.println(digitSum(n));
        }
    }
}
