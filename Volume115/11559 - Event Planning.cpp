#include <cstdio>
#define INF 2000000000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, b, h, w;
    int price, minprice;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
        bool is_stay = true;
        minprice = INF;

        for(int i = 0; i < h; i++) {
            scanf("%d", &price);
            for(int j = 0; j < w; j++) {
                int temp;
                scanf("%d", &temp);
                if(temp >= n) {
                    minprice = min(minprice, price);
                }
            }
        }

        if(minprice != INF && n*minprice <= b) {
            printf("%d\n", n*minprice);
        } else puts("stay home");
    }
}

