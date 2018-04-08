#include <cstdio>
#include <cstring>

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int ts, n;
    scanf("%d", &ts);
    char pick[20][20], bomb[20][20];
    int board[20][20];
    char outboard[20][20];
    while(ts--) {
        scanf("%d", &n);
        memset(board, 0, sizeof(board));
        memset(outboard, '\0', sizeof(outboard));
        for(int i = 0; i < n; i++) scanf("%s", bomb[i]);
        for(int i = 0; i < n; i++) scanf("%s", pick[i]);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(bomb[i][j] == '*') {
                    for(int d = 0; d < 8; d++) board[i+1+dr[d]][j+1+dc[d]]++;
                }
            }
        }

        bool is_bomb = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(pick[i][j] == '.') outboard[i][j] = '.';
                else {
                    if(bomb[i][j] == '*') is_bomb = true;
                    outboard[i][j] = '0' + board[i+1][j+1];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(is_bomb && bomb[i][j] == '*') printf("*");
                else printf("%c", outboard[i][j]);
            }
            puts("");
        }
        if(ts) puts("");
    }
}
