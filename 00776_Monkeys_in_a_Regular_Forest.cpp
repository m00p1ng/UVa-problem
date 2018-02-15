#include <cstdio>
#include <cstring>
#include <cmath>

char board[1000][1000];
int out[1000][1000];
int row, col;

int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int max(int a, int b) {
    return a > b ? a : b;
}

void dfs(int i, int j, char c, int idx) {
    if(i < 0 || j < 0 || i == row || j == col) return;
    if(board[i][j] != c) return;

    board[i][j] = '.';
    out[i][j] = idx;

    for(int d = 0; d < 8; d++) {
        dfs(i+dr[d], j+dc[d], c, idx);
    }
}

void init_input(char *s) {
    int len = strlen(s);
    while(s[0] != '%') {
        s[strlen(s)-1] = '\0';
        col = 0;
        for(int i = 0; i < len; i+=2, col++) {
            board[row][col] = s[i]; 
        }
        row++;
        if(fgets(s, 10000, stdin) == NULL) break;
    }
}

void manage_output() {
    int offset[1000] = {0};
    for(int j = 0; j < col; j++) {
        for(int i = 0; i < row; i++) {
            offset[j] = max(offset[j], out[i][j]);
        }
        offset[j] = floor(log10(offset[j]))+1;
    }
    offset[0]--;

    char format[] = "%0d";

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            format[1] = 1+offset[j]+'0';
            printf(format, out[i][j]);
        }
        puts("");
    }
    puts("%");
}

int main() {
    row = col = 0;
    char s[10000];
    fgets(s, 10000, stdin);

    while(1) {
        init_input(s);

        int idx = 1;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] != '.') {
                    dfs(i, j, board[i][j], idx++); 
                }
            }
        }

        manage_output();
        row = col = 0;
        if(fgets(s, 10000, stdin) == NULL) break;
    }
}
