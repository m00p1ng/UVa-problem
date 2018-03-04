import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        BigInteger dp[][] = new BigInteger[205][205];

        dp[0][0] = dp[1][0] = dp[1][1] = BigInteger.ONE;
        System.out.println("1");
        System.out.println("1 1");

        for(int n = 2; n < 205; n++) {
            System.out.print("1");
            dp[n][0] = dp[n][n] = BigInteger.ONE;
            for(int k = 1; k < n; k++) {
                dp[n][k] = dp[n-1][k-1].add(dp[n-1][k]); 
                System.out.print(" " + dp[n][k]); 
            }
            System.out.println(" 1");
        }
    }
}
