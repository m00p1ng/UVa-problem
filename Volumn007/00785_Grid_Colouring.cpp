#include <cstdio>
#include <cstring>

char board[100][100];
bool visited[100][100] = {false};
int row = 0;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

void dfs(int i, int j, char c) {
    if(i < 0 || j < 0 || i == row || j == strlen(board[i])) return;
    if(board[i][j] != ' ') return;

    visited[i][j] = true;
    board[i][j] = c;

    for(int d = 0; d < 4; d++) {
        dfs(i + dr[d], j + dc[d], c);
    }
}

int main() {
    while(fgets(board[row], 100, stdin)) {
        board[row][strlen(board[row])-1] = '\0';
        if(board[row][0] == '_') {
            for(int m = 0; m < row; m++) {
                for(int n = 0; n < strlen(board[m]); n++) {
                    if(board[m][n] != ' ' && board[m][n] != 'X' && !visited[m][n]) {
                        char temp = board[m][n];
                        board[m][n] = ' ';
                        dfs(m, n, temp);
                    }
                }
            }

            for(int m = 0; m <= row; m++) {
                printf("%s\n", board[m]);
            }

            memset(visited, false, sizeof(visited));
            row = 0;
        } else row++;
    }
}
