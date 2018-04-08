#include <cstdio>
#define MAX_COIN 100
#define MAX_VAL 125250

int n;
int bag[MAX_COIN+10];
int dp[MAX_COIN+10][MAX_VAL+10] = {0};

int max(int a, int b) {
    return a > b ? a : b;
}

void calc_dp(int sum) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(dp[i-1][j-bag[i]] <= sum && bag[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-bag[i]] + bag[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d", &n);

        int sum = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &bag[i]);
            sum += bag[i];
        }
        calc_dp(sum/2);

        printf("%d\n", sum-2*dp[n][sum/2]);
    }
}
