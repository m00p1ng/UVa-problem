#include <cstdio>

long long dp[101][101];

void gen_dp() {
    for(int i = 0; i <= 100; i++) {
        dp[1][i] = dp[i][0] = 1;
    }

    for(int i = 2; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j] >= 1000000) dp[i][j] -= 1000000;
        }
    }
}

int main() {
    gen_dp();
    int n, k;
    while(scanf("%d %d", &n, &k), n || k) {
        printf("%lld\n", dp[k][n]);
    }
}
