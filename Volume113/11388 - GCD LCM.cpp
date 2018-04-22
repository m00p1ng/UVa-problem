#include <cstdio>

int main() {
    int ts, g, l;
    scanf("%d", &ts);

    while(ts--) {
        scanf("%d %d", &g, &l);
        if(l % g != 0) puts("-1");
        else printf("%d %d\n", g, l);
    }
}
