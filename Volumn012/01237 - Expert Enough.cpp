#include <cstdio>

int main() {
    int ts, c, q, val, idx;
    int cost[2][10000];
    char car[10000][30];
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d", &c);
        for(int i = 0; i < c; i++) {
            scanf("%s %d %d", car[i], &cost[0][i], &cost[1][i]);
        }

        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            idx = -1;
            scanf("%d", &val);
            for(int j = 0; j < c; j++) {
                if(val >= cost[0][j] && val <= cost[1][j]) {
                    if(idx == -1) idx = j;
                    else {
                        idx = -1;
                        break; 
                    }
                }
            }
            if(idx == -1) puts("UNDETERMINED");
            else puts(car[idx]);
        }
        if(ts) puts("");
    }
}
