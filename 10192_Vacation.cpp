#include <cstdio>
#include <cstring>

int dp[101][101];
char a[110], b[110];

int max(int a, int b) {
    return a > b ? a : b;
}

void lcs(int lena, int lenb) {
    for(int i = 1; i <= lena; i++) {
        for(int j = 1; j <= lenb; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main() {
    int cnt = 0;
    memset(dp, 0, sizeof(dp));
    while(fgets(a, 110, stdin) && !(a[0] == '#' && a[1] == '\n')) {
        fgets(b, 110, stdin);
        int lena = strlen(a)-1;
        int lenb = strlen(b)-1;
        
        lcs(lena, lenb);
        printf("Case #%d: you can visit at most %d cities.\n", ++cnt, dp[lena][lenb]);
    }
}
