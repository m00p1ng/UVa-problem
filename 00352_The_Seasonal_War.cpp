#include <cstdio>

int n;
char board[100][100];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 ,-1};

void dfs(int i, int j) {
    if(i < 0 || j < 0 || i == n || j == n) return;
    if(board[i][j] != '1') return;

    board[i][j] = '0';

    for(int d = 0; d < 8; d++) {
        dfs(i+dr[d], j+dc[d]);
    }
}

int main() {
    int cnt;
    int rnd = 0;
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }

        cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '1') {
                    dfs(i, j);            
                    cnt++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++rnd, cnt);
    }
}
