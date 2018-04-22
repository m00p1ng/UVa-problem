#include <cstdio>
#define ROW 9

int main() {
    int ts;
    scanf("%d", &ts);

    while(ts--) {
        int brick[9][9] = {0};

        for(int i = 0; i < ROW; i+=2) {
            for(int j = 0; j <= i; j+=2) {
                scanf("%d", &brick[i][j]);
            }
        }

        for(int row = 0; row < 7; row+=2) {
            for(int i = 0; i <= row; i+=2) {
                int diff = brick[row][i] - (brick[row+2][i] + brick[row+2][i+2]);
                brick[row+2][i+1] = diff/2;
                brick[row+1][i]   = brick[row+2][i] + brick[row+2][i+1];
                brick[row+1][i+1] = brick[row+2][i+1] + brick[row+2][i+2];
            }
        }

        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j <= i; j++) {
                printf("%d", brick[i][j]);
                if(j != i) printf(" ");
            }
            puts("");
        }
    }
}

