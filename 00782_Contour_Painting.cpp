#include <cstdio>
#include <cstring>

char board[100][100];
bool visited[100][100];
int row, si, sj;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

bool in_board(int i, int j) {
    return i >= 0 && j >= 0 && i < row && j < 82;
}

void print_board() {
    for(int m = 0; m <= row; m++) {
        printf("%s\n", board[m]);
    }
}

void get_space() {
    for(int i = 0; i < row; i++) {
        int k = 0;
        for(int j = 82; j >= 0; j--) {
            if(board[i][j] == 'X' || board[i][j] == '#') {
                k = j;
                board[i][j+1] = '\0';
                break;
            }
        }
        if(k == 0) board[i][0] = '\0';
        for(int j = 0; j < k; j++) {
            if(board[i][j] != 'X' && board[i][j] != '#') {
                board[i][j] = ' ';
            }
        }
    }
}

void dfs(int i, int j) {
    visited[i][j] = true;

    for(int d = 0; d < 4; d++) {
        int di = i+dr[d];
        int dj = j+dc[d];
        if(in_board(di, dj) && !visited[di][dj] && board[di][dj] != '#') {
            if(board[di][dj] == 'X') {
                board[i][j] = '#';
            } else {
                dfs(di, dj);
            }
        }
    }
}

void find_star() {
    for(int i = 0; i < strlen(board[row]); i++) {
        if(board[row][i] == '*') {
            si = row;
            sj = i;
            board[row][i] = ' ';
        }
    }
}

int main() {
    scanf("%*d%*c");
    while(fgets(board[row], 100, stdin)) {
        board[row][strlen(board[row])-1] = '\0';
        if(board[row][0] == '_') {
            memset(visited, false, sizeof(visited));
            dfs(si, sj);

            get_space();
            print_board();
            memset(board, 0, sizeof(board));
            row = 0;
        } else {
            find_star();
            row++;
        }
    }
}
