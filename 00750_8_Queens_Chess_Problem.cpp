#include <cstdio>
#define MAX_Q 8

int sr, sc;
int board[MAX_Q];
int cnt;

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

void print_board() {
    printf("%2d     ", ++cnt);
    for(int i = 0; i < MAX_Q; i++) {
        printf(" %d", board[i]+1);
    }
    puts("");
}

void place_queen(int col) {
    if(col == MAX_Q && board[sc] == sr) {
        print_board();
    }

    for(int i = 0; i < MAX_Q; i++) {
        bool found = find_queen(i, col);
        if(!found) {
            board[col] = i;
            place_queen(col+1);
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &sr, &sc);
        sr--;
        sc--;

        for(int i = 0; i < MAX_Q; i++) board[i] = -1;
        cnt = 0;

        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");
        place_queen(0);
        if(ts) puts("");
    }
}
