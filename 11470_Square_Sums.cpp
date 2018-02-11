#include <cstdio>

int main() {
    int n, ts = 0;
    int board[10][10];

    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        printf("Case %d:", ++ts);
        for(int k = 0; k < n>>1; k++) {
            int sum = 0;
            for(int i = k; i < n-k; i++) {
                sum += board[i][k] + board[i][n-k-1];
                sum += board[k][i] + board[n-k-1][i];
            }
            sum -= (board[k][k] + board[n-1-k][n-1-k]);
            sum -= (board[n-1-k][k] + board[k][n-1-k]);
            printf(" %d", sum);
        }
        if(n&1) printf(" %d", board[n>>1][n>>1]);
        puts("");
    }
}
