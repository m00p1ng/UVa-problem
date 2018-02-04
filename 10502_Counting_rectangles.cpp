#include <cstdio>

int r, c;
char board[200][200];

bool cnt_rec(int ri, int rj, int ci, int cj) {
    for(int i = ri; i <= rj; i++) {
        for(int j = ci; j <= cj; j++) {
            if(board[i][j] != '1') return false;
        }
    }
    return true;
}

int main() {
    while(scanf("%d %d", &r, &c) == 2) {
        for(int i = 0; i < r; i++) scanf("%s", board[i]);

        int cnt = 0;
        for(int ri = 0; ri < r; ri++) {
            for(int rj = ri; rj < r; rj++) {
                for(int ci = 0; ci < c; ci++) {
                    for(int cj = ci; cj < c; cj++) {
                        cnt += cnt_rec(ri, rj, ci, cj);
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
}
