#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    
    int n, store, max, min;
    while(ts--) {
        max = -1;
        min = 1e6;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &store);
            max = (max < store) ? store : max;
            min = (min > store) ? store : min;
        }

        printf("%d\n", 2*(max-min));
    }
}
