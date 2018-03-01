import java.util.Scanner;
import java.math.BigDecimal;

class Main {
    public static void main(String args[]) {
        int ts;
        BigDecimal a, b;
        Scanner s = new Scanner(System.in);

        ts = s.nextInt();

        for(int i = 0; i < ts; i++) {
            a = s.nextBigDecimal();
            b = s.nextBigDecimal();

            a = a.add(b);
            System.out.print(a.stripTrailingZeros());
            if(a.signum() == 0 || a.scale() <= 0 || a.stripTrailingZeros().scale() <= 0) { 
                System.out.print(".0");
            }
            System.out.println();
        }
    }
}
