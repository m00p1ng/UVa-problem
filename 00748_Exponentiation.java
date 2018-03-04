import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            String out[] = s.next().split("\\.");
            BigInteger a = new BigInteger(out[0]+out[1]);
            int p = s.nextInt();
            int len = out[1].length();

            int cnt = 0;
            int idx = len-1;
            while(out[1].charAt(idx) == '0') {
                cnt++;
                idx--;
            }

            int dot = len*p;

            a = a.pow(p);
            BigInteger m = BigInteger.TEN.pow(dot);
            BigInteger front = a.divide(m);
            BigInteger back = a.mod(m);

            int lenBack = back.toString().length();

            if(front.compareTo(BigInteger.ZERO) != 0) {
                System.out.print(front);
            }
            System.out.print(".");

            int diff = dot - lenBack;
            
            for(int i = 0; i < diff; i++) {
                System.out.print("0");
            }

            if(cnt != 0) {
                System.out.println(back.toString().substring(0, dot-(cnt*p)-diff));
            } else {
                System.out.println(back);
            }
        }
    }
}

