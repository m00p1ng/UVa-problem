#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    int ts;
    char s[1000];
    int dp[200][200];
    bool bomb[200][200];

    scanf("%d", &ts);
    while(ts--) {
        int r, c;
        scanf("%d %d\n", &r, &c);

        memset(dp, 0, sizeof(dp));
        memset(bomb, false, sizeof(bomb));

        for(int i = 1; i <= r; i++) {
            fgets(s, 1000, stdin);

            char *p;
            p = strtok(s, " ");
            p = strtok(NULL, " ");

            while(p != NULL) {
                bomb[i][atoi(p)] = true;
                p = strtok(NULL, " ");
            }
        }

        dp[1][1] = 1;
        for(int i = 2; i <= r && !bomb[i][1]; i++) dp[i][1] = 1;
        for(int j = 2; j <= c && !bomb[1][j]; j++) dp[1][j] = 1;

        for(int i = 2; i <= r; i++) {
            for(int j = 2; j <= c; j++) {
                if(!bomb[i][j]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        printf("%d\n", dp[r][c]);
        if(ts) puts("");
    }
}

