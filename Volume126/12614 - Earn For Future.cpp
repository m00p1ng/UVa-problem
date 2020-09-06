#include <cstdio>

int main() {
    int ts, n, max, c;
    scanf("%d", &ts);

    for (int t = 1; t <= ts; t++) {
        max = -1;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &c);

            if (c > max) {
                max = c;
            }
        }
    
        printf("Case %d: %d\n", t, max);
    }
}
