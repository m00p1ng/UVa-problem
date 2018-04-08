#include <cstdio>
#define max(a, b) (a > b ? a : b)

int n;
int dp[1001][31] = {0};
int price[1001], weight[1001];

void calc_dp() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < weight[i]; j++) dp[i][j] = dp[i-1][j];
        for(int j = weight[i]; j <= 30; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+price[i]);
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);

    int g, sum, temp;
    while(ts--) {
        sum = 0;
        scanf("%d", &n);

        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &price[i], &weight[i]);
        }
        
        calc_dp();
         
        scanf("%d", &g);
        for(int i = 0; i < g; i++) {
            scanf("%d", &temp);
            sum += dp[n][temp]; 
        }
        printf("%d\n", sum);
    }
}

