#include <cstdio>

int main() {
    int ts, k;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%*d %d", &k);
        printf("%d\n", k^(k>>1));
    }
}
