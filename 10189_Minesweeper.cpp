#include <cstdio>
#include <cstring>

int main() {
    int m, n;
    char board[200][200];
    int bomb[200][200];
    int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int rnd = 0;

    while(scanf("%d %d", &m, &n), m || n) {
        memset(bomb, 0, sizeof(bomb));
        for(int i = 0; i < m; i++) {
            scanf("%s", board[i]);
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i-1][j-1] == '*') {
                    for(int d = 0; d < 8; d++) {
                        bomb[dr[d]+i][dc[d]+j]++;
                    }
                }
            }
        }

        if(rnd != 0) puts("");
        printf("Field #%d:\n", ++rnd);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '*') printf("*");
                else printf("%d", bomb[i+1][j+1]);
            }
            puts("");
        }
    }
}
