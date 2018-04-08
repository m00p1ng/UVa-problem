#include <cstdio>
#include <algorithm>

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int ts;
    int dis[30000];
    scanf("%d", &ts);
    while(ts--) {
        int range;
        scanf("%d", &range);
        for(int i = 0; i < range; i++) {
            scanf("%d", &dis[i]);
        }

        std::nth_element(dis, dis + (range/2), dis + range);

        int ans = 0;
        int med = dis[range/2];

        for(int i = 0; i < range; i++) {
            ans += abs(dis[i] - med);
        }

        printf("%d\n", ans);
    }
}

