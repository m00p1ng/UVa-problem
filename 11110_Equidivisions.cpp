#include <cstdio>
#include <cstring>
#include <cstdlib>

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int board[100][100];
int n;

int dfs(int num, int i, int j) {
    if(i < 0 || j < 0 || i == n || j == n) return 0;
    if(board[i][j] != num) return 0;
    board[i][j] = -1;

    int cnt = 1;
    for(int d = 0; d < 4; d++) {
        cnt += dfs(num, i+dr[d], j+dc[d]);
    }
    return cnt;
}

int main() {
    int a, b;
    char s[1000];
    while(scanf("%d%*c", &n), n) {
        memset(board, 0, sizeof board);
        for(int i = 1; i <= n-1; i++) {
            fgets(s, 1000, stdin);
            s[strlen(s)-1] = '\0';

            char *p;
            p = strtok(s, " ");

            while(p != NULL) {
                a = atoi(p);
                p = strtok(NULL, " ");
                b = atoi(p);
                p = strtok(NULL, " ");

                board[a-1][b-1] = i;
            }
        }

        bool is_valid = true;
        for(int i = 0; i < n && is_valid; i++) {
            for(int j = 0; j < n && is_valid; j++) {
                if(board[i][j] != -1) {
                    is_valid = dfs(board[i][j], i, j) == n;
                }
            }
        }
        if(is_valid) puts("good");
        else puts("wrong");
    }
}
