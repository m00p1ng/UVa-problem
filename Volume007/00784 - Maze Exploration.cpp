#include <cstdio>
#include <cstring>

char board[31][81];
int row, col;

int dx[] = {0, 0, 1, -1,};
int dy[] = {-1,1, 0,  0,};

void fillboard(int x, int y) {
    if(x < 0 || y < 0 || x == row || y == col) return;
    if(board[x][y] != ' ') return;

    board[x][y] = '#';
    for(int i = 0; i < 4; i++) {
        fillboard(x + dx[i], y + dy[i]);
    }
}

int main() {
    int testcase;
    scanf("%d\n", &testcase);
    while(testcase--) {
        int px, py;
        row = col = 0;

        while(fgets(board[row], 100, stdin)) {
            int len = strlen(board[row]) - 1;
            if(board[row][0] == '_') break;

            for(int i = 0; i < len; i++) {
                if(board[row][i] == '*') {
                    px = row;
                    py = i;
                    board[row][i] = ' ';
                }
            }
            row++;
        }

        fillboard(px, py);

        for(int i = 0; i <= row; i++) {
            printf("%s", board[i]);
        }
    }
}

