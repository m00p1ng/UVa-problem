#include <cstdio>

int n;
char board[200][200];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

void dfs(int i, int j) {
    if(i < 0 || j < 0 || i == n || j == n) return;
    if(board[i][j] == '.') return;

    board[i][j] = '.';

    for(int d = 0; d < 4; d++) {
        dfs(i+dr[d], j+dc[d]);
    }
}

int main() {
    int ts;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'x') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n", t, cnt);
    }
}
