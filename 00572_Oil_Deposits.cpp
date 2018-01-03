#include <cstdio>

int sr, sc;
char board[110][110];

int dr[] = {-1, -1, 0, 1, 1, 1, 0 ,-1};
int dc[] = {0, 1, 1, 1, 0 , -1, -1, -1};

void dfs(int i, int j) {
    if(i < 0 || j < 0 || i == sr || j == sc) return;
    if(board[i][j] != '@') return;

    board[i][j] = '*';

    for(int d = 0; d < 8; d++) {
        dfs(dr[d]+i, dc[d]+j);
    }
}

int main() {
    while(scanf("%d %d", &sr, &sc), sr != 0 || sc != 0) {
        for(int i = 0; i < sr; i++) {
            scanf("%s", board[i]);
        }
        
        int cnt = 0;
        for(int i = 0; i < sr; i++) {
            for(int j = 0; j < sc; j++) {
                if(board[i][j] == '@') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }
}
