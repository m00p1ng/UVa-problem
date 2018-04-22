#include <cstdio>
#include <cstring>
#define BLANK 0

char out[1002][1002];
int bomb[1002][1002];
int r, c, cnt, ni, nj;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_corner(int i, int j) {
    return (i == 1 || i == r) && (j == 1 || j == c);
}

bool is_border(int i, int j) {
    return i == 1 || j == 1 || i == r || j == c;
}

bool is_valid(int i, int j) {
    return i >= 1 && j >= 1 && i <= r && j <= c;
}

void place(int i, int j, int c) {
    for(int d = 0; d < 8; d++) {
        ni = i + dr[d];
        nj = j + dc[d];
        if(is_valid(ni, nj) && out[ni][nj] == BLANK) {
            out[ni][nj] = c;
            cnt--;
        }
    }
}

void first_fill() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(out[i][j] != BLANK) continue;
            if(bomb[i][j] < 3) {
                out[i][j] = '-';
                if(bomb[i][j] == 0) place(i, j, '-');
            } else if(bomb[i][j] > 8 || (is_corner(i, j) && bomb[i][j] > 3) || (is_border(i, j) && bomb[i][j] > 5)) {
                out[i][j] = 'L';
                if(bomb[i][j] == 12) place(i, j, 'L');
            } else continue;
            cnt--;
        }
    }
}

void print_board() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            printf("%c", out[i][j]);
        }
        puts("");
    }
}

int count_char(int i, int j, char c) {
    int co = out[i][j] == c;

    for(int d = 0; d < 8; d++) {
        ni = i + dr[d];
        nj = j + dc[d];
        if(is_valid(ni, nj) && out[ni][nj] == c) co++;
    }
    return co;
}

bool is_full(int i, int j) {
    int p = 9;
    if(is_corner(i, j)) p = 4;
    else if(is_border(i, j)) p = 6; 

    return p == count_char(i, j, BLANK);
}

void iterate_fill() {
    int l, d, s, p;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(is_full(i, j)) continue;
            if(cnt == 0) return;

            l = count_char(i, j, 'L');
            s = count_char(i, j, BLANK);
            if(out[i][j] == 'L') l += 3;

            if((bomb[i][j] == s+l && out[i][j] == '-') || (s == 1 && bomb[i][j] != l)) {
                place(i, j, 'L');
            } else if(bomb[i][j] == s+l+3) {
                out[i][j] = 'L';
                cnt--;
                place(i, j, 'L');
            } else if(bomb[i][j] < l+4 && out[i][j] == BLANK) {
                out[i][j] = '-';
                cnt--;
            } else if(bomb[i][j] == l) {
                place(i, j, '-');
            }
        }
    }
}

int main() {
    int ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d %d", &r, &c);
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                scanf("%d", &bomb[i][j]);
            }
        }
        memset(out, BLANK, sizeof(out));

        cnt = r*c; 
        first_fill();

        while(cnt) iterate_fill();
        print_board();
    }
}
