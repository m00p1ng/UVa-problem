#include <cstdio>
#include <cstring>

enum {A, B, R, L};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
int mm[128];

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < 5 && j < 5;
}


void swap_char(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

bool is_valid_char(char c) {
    return c == 'A' || c == 'R' || c == 'B' || c == 'L';
}

int main() {
    char board[10][10], m;
    int x, y, ts = 0;
    bool vc;
    mm['A'] = A;
    mm['B'] = B;
    mm['L'] = L;
    mm['R'] = R;

    while(fgets(board[0], 10, stdin), strcmp(board[0], "Z\n")) {
        for(int j = 0; j < 5; j++) {
            if(board[0][j] == ' ') {
                x = 0;
                y = j;
            }
        }
        for(int i = 1; i < 5; i++) {
            fgets(board[i], 10, stdin);
            for(int j = 0; j < 5; j++) {
                if(board[i][j] == ' ') {
                    x = i;
                    y = j;
                }
            }
        }
        vc = true;
        
        int nx, ny;
        while(scanf(" %c", &m), m != '0') {
            if(!vc) continue;
            nx = x + dr[mm[m]];
            ny = y + dc[mm[m]];
            if(!is_valid(nx, ny) || !is_valid_char(m)) {
                vc = false;
                continue;
            }
            swap_char(board[x][y], board[nx][ny]);
            x = nx;
            y = ny;
        }
        scanf("%*c");

        if(ts) puts("");
        printf("Puzzle #%d:\n", ++ts);
        if(vc) {
            for(int i = 0; i < 5; i++) {
                printf("%c", board[i][0]);
                for(int j = 1; j < 5; j++) {
                    printf(" %c", board[i][j]);
                }
                puts("");
            }
        } else {
            puts("This puzzle has no final configuration.");
        }
    }
}
