#include <cstdio>

int main() {
    int n, ts = 0;
    while(scanf("%d", &n), n) {
        printf("Case %d: %d\n", ++ts, n>>1);
    }
}
