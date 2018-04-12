#include <cstdio>

int board[8];
int patt[800][8];
int cnt = 0;

int abs(int n) {
    return n > 0 ? n : -n;
}

bool find_queen(int row, int col) {
    for(int i = 0; i < col; i++) {
        if(row == board[i] || abs(board[i]-row) == abs(col-i)) {
            return true;
        }
    }
    return false;
}

void place_queen(int col) {
    if(col == 8) {
        for(int i = 0; i < 8; i++) {
            patt[cnt][i] = board[i]+1;
        }
        cnt++;
        return;
    }

    for(int i = 0; i < 8; i++) {
        bool found = find_queen(i, col);
        if(!found) {
            board[col] = i;
            place_queen(col+1);
        }
    }
}

int main() {
    int ts = 0, x[8];
    place_queen(0);

    while(scanf("%d %d %d %d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7]) == 8) {
        int max = 0;
        for(int i = 0; i < cnt && max < 8; i++) {
            int temp = 0;
            for(int j = 0; j < 8; j++) {
                if(x[j] == patt[i][j]) temp++;
            }
            if(temp > max) max = temp;
        }
        printf("Case %d: %d\n", ++ts, 8-max);
    }
}
