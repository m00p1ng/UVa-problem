#include <cstdio>
#include <cstring>

char board[30][30];
int row, col;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1,0, 1, -1, 0,  1, -1};

int dfs(int x, int y) {
    if(x < 0 || y < 0 || x == row || y == col) return 0;
    if(board[x][y] == '0') return 0;

    board[x][y] = '0';
    int ans = 1;
    for(int i = 0; i < 8; i++) {
        ans += dfs(x + dx[i], y + dy[i]);
    }
    return ans;
}

int main() {
    int testcase;
    int max;
    scanf("%d\n\n", &testcase);
    while(testcase--) {
        row = 0;
        max = 0;
        while(fgets(board[row], 30, stdin) && strcmp(board[row], "\n")) {
            row++;
        }

        col = strlen(board[0]) - 1;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == '1') {
                    int cnt = dfs(i, j);
                    if(max < cnt) max = cnt;
                }
            }
        }

        printf("%d\n", max);
        if(testcase) puts("");
    }
}

