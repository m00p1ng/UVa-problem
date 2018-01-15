#include <cstdio>

int main() {
    int ts;
    scanf("%d", &ts);
    int prev, next, high, low, n;
    for(int t = 1; t <= ts; t++) {
        high = low = 0;

        scanf("%d", &n);
        scanf("%d", &prev);

        for(int i = 1; i < n; i++) {
            scanf("%d", &next);
            if(next-prev > 0) high++;
            else if(next-prev < 0) low++;
            prev = next;
        }

        printf("Case %d: %d %d\n", t, high, low);
    }
}
