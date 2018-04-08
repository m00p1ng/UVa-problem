import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        BigInteger sum = BigInteger.ZERO;
        Scanner s = new Scanner(System.in);

        BigInteger temp;
        while(s.hasNext()) {
           temp = s.nextBigInteger(); 
           sum = sum.add(temp);
        }
        System.out.println(sum);
    }
}
