#include <cstdio>
#define N_COIN 11
#define MAX_VAL 30000

const int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[MAX_VAL+1] = {0};

void calc_dp() {
    dp[0] = 1;
    for(int i = 0; i < N_COIN; i++) {
        for(int j = coin[i]; j <= MAX_VAL; j++) {
            dp[j] += dp[j-coin[i]];
        }
    }
}

int main() {
    calc_dp();
    int a, b;
    while(scanf("%d.%d", &a, &b), a != 0 || b != 0) {
        int cost = a*100 + b;
        
        printf("%6.2lf %16lld\n", a+(double)b/100.0, dp[cost]);
    }
}
