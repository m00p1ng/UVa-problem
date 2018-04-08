#include <cstdio>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int w, h, n;
    int x1, y1, x2, y2;
    while(scanf("%d %d %d", &w, &h, &n), w || h || n) {
        bool board[501][501] = {false};

        for(int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if(x1 > x2) swap(&x1, &x2);
            if(y1 > y2) swap(&y1, &y2);

            for(int m = x1; m <= x2; m++) {
                for(int n = y1; n <= y2; n++) {
                    board[m][n] = true;
                }
            }
        }

        int count = 0;
        for(int m = 1; m <= w; m++) {
            for(int n = 1; n <= h; n++) {
                if(!board[m][n]) count++; 
            }
        }
        
        if(count == 0) puts("There is no empty spots."); 
        else if(count == 1) puts("There is one empty spot."); 
        else printf("There are %d empty spots.\n", count); 
    }
}

