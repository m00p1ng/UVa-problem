#include <cstdio>

int dp[75][75] = {0};

void gen_dp() {
    for(int i = 1; i <= 70; i++) {
        dp[1][i] = dp[i][1] = 1;
    }

    for(int i = 2; i <= 70; i++) {
        for(int j = 2; j <= 70; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
}

int main() {
    gen_dp();
    int n, t, p, ts, diff;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d %d %d", &n, &t, &p);
        diff = t - n*p;
        if(diff < 0) {
            puts("0");
        } else {
            printf("%d\n", dp[diff + 1][n]);
        }
    }
}
