#include <cstdio>

int offset(int n, int k) {
    return ((n % k) + k) % k;
}

int main() {
    int ts;
    int data[10000], n, k;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d %d", &n, &k); 

        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
            data[i] %= k;
            if(data[i] < 0) data[i] += k;
        }

        bool dp[10010][110] = {0};
        dp[0][0] = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                if(dp[i][j]) {
                    dp[i+1][offset(j+data[i], k)] = true;
                    dp[i+1][offset(j-data[i], k)] = true;
                }
            }
        }

        if(dp[n][0]) puts("Divisible");
        else puts("Not divisible");
    }
}
