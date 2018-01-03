#include <cstdio>
#define MAX_CHANGE 7489
#define N_COIN 5

const int coin[] = {1, 5, 10, 25, 50};
int dp[7500];

void calc_dp() {
    dp[0] = 1;

    for(int i = 0; i < N_COIN; i++) {
        for(int j = coin[i]; j <= MAX_CHANGE; j++) {
            dp[j] += dp[j-coin[i]];
        }
    }
}

int main() {
    calc_dp();
    int n;

    while(scanf("%d", &n) == 1) {
        printf("%d\n", dp[n]);
    }
}
