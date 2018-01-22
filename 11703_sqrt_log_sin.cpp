#include <cstdio>
#include <cmath>

int dp[(int)(1e6+10)];

void gen_dp() {
    dp[0] = 1;

    for(int i = 1; i <= 1e6; i++) {
        dp[i] = dp[(int)(i-sqrt(i))] + dp[(int)log(i)] + dp[(int)(i*sin(i)*sin(i))];
        if(dp[i] >= 1e6) {
            dp[i] = dp[i] % (int)1e6;
        }
    }
}

int main() {
    gen_dp();

    int n;
    while(scanf("%d", &n), n != -1) {
        printf("%d\n", dp[n]);
    }
}
