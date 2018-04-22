import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        BigInteger a, b, result;
        BigInteger k = new BigInteger("2147483647");
        Scanner s = new Scanner(System.in);
        String sa, sb;

        char c;
        while(s.hasNext()) {
            sa = s.next();
            c = s.next().charAt(0);
            sb = s.next();

            a = new BigInteger(sa);
            b = new BigInteger(sb);

            System.out.printf("%s %c %s\n", sa, c, sb);
            if(a.compareTo(k) == 1) {
                System.out.println("first number too big");
            }

            if(b.compareTo(k) == 1) {
                System.out.println("second number too big");
            }

            if(c == '+') {
                result = a.add(b);
            } else {
                result = a.multiply(b);
            }

            if(result.compareTo(k) == 1) {
                System.out.println("result too big");
            }
        }
    }
}
