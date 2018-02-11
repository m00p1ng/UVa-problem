#include <cstdio>

int r, c;
char board[200][200];

int dr[] = {0,  0, 1,  1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, -1, 1,  0, -1,  1};

int dfs(int i, int j) {
    if(i < 0 || j < 0 || i >= r || j >= c) return 0;
    if(board[i][j] != '*') return 0;
    board[i][j] = '.';

    int result = 1;
    for(int d = 0; d < 8; d++) {
        result += dfs(i + dr[d], j + dc[d]);
    }
    return result;
}

int main() {
    while(scanf("%d %d", &r, &c), r || c) {
        for(int i = 0; i < r; i++) {
            scanf("%s", board[i]);
        }

        int cnt = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == '*' && dfs(i, j) == 1) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
