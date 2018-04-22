#include <cstdio>
#include <cstring>

int dp[1010][1010];
char a[1010], b[1010];

int max(int a, int b) {
    return a > b ? a : b;
}

int calc_dp() {
    int la = strlen(a)-1;
    int lb = strlen(b)-1;
    for(int i = 1; i <= la; i++) {
        for(int j = 1; j <= lb; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[la][lb];
}

void init_dp() {
    for(int i = 0; i <= 1000; i++) dp[0][i] = dp[i][0] = 0;
}

int main() {
    init_dp();
    while(fgets(a, 1010, stdin)) {
        fgets(b, 1010, stdin);
        printf("%d\n", calc_dp()); 
    }
}
