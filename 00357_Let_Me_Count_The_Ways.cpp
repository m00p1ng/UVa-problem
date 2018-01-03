#include <cstdio>
#define N_COIN 5
#define MAX_CHANGE 30010
long long dp[MAX_CHANGE];
const int coin[] = {1, 5, 10, 25, 50};

void cal_dp() {
    dp[0] = 1;

    for(int i = 0; i < N_COIN; i++) {
        for(int j = coin[i]; j <= MAX_CHANGE; j++) {
            dp[j] += dp[j-coin[i]];
        }
    }
}

int main() {
    int n;
    cal_dp();

    while(scanf("%d", &n) == 1) {
        if(dp[n] == 1) {
            printf("There is only 1 way to produce %d cents change.\n", n);
        } else {
            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
        }
    }
}
