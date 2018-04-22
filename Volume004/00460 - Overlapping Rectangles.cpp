#include <cstdio>

enum {x1, y1, x2, y2};

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int testcase;
    int sq1[4], sq2[4];
    scanf("%d", &testcase);
    while(testcase--) {
        for(int i = 0; i < 4; i++) scanf("%d", &sq1[i]);
        for(int i = 0; i < 4; i++) scanf("%d", &sq2[i]);

        int xmin = max(sq1[x1], sq2[x1]);
        int xmax = min(sq1[x2], sq2[x2]);
        int ymin = max(sq1[y1], sq2[y1]);
        int ymax = min(sq1[y2], sq2[y2]);

        if(xmax > xmin && ymax > ymin) printf("%d %d %d %d\n", xmin, ymin, xmax, ymax);
        else puts("No Overlap");
        if(testcase) puts("");
    }
}

