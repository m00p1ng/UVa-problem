#include <cstdio>

int main() {
    int ts;
    int number[200000];
    scanf("%d", &ts);
    while(ts--) {
        int range;
        scanf("%d", &range);
        int h = -1000000, diff = -1000000;
        for(int i = 0; i < range; i++) {
            scanf("%d", &number[i]);
        }
        for(int i = 0; i < range - 1; i++) {
            if(number[i] > h) h = number[i];
            if(h - number[i+1] > diff) {
                diff = h - number[i+1]; 
            }
        }
        printf("%d\n", diff);
    }
}

