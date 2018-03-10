#include <cstdio>
#include <cstring>

int abs(int a) {
    return a > 0 ? a : -a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int score[8][8];
int maxScore;
int row[8];

bool canPlace(int r, int c) {
    for(int prev = 0; prev < c; prev++) {
        if(row[prev] == r || abs(row[prev]-r) == abs(prev-c)) {
            return false;
        }
    }
    return true;
}

void searchQueen(int c) {
    if(c == 8) {
        int total = 0;
        for(int i = 0; i < 8; i++) {
            total += score[row[i]][i];
        }
        maxScore = max(total, maxScore);
        return;
    }

    for(int r = 0; r < 8; r++) {
        if(canPlace(r, c)) {
            row[c] = r;
            searchQueen(c+1);
        }
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                scanf("%d", &score[i][j]);
            }
        }

        maxScore = 0;
        memset(row, 0, sizeof(row));
        searchQueen(0);
        printf("%5d\n", maxScore);
    }
}

