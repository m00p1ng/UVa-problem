#include <cstdio>

int dp[10001] = {0};

int min(int a, int b) {
    return a < b ? a : b;
}

void init_dp() {
    int offset;

    for(int i = 1; i < 100; i++) {
        offset = i*i;

        for(int j = 0; j <= 2*i; j++) {
            dp[offset+j] = dp[j];
            for(int k = 1; k < i; k++) {
                dp[offset+j] = min(dp[offset+j], dp[offset+j-k*k]);
            }
            dp[offset+j] += 1;
        }
    }
    dp[10000] = 1;
}

int main() {
    init_dp();
    int ts, n;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}

