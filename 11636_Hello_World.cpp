#include <cstdio>
#include <cmath>

int main() {
    int n, ts = 0;
    while(scanf("%d", &n), n > 0) {
        printf("Case %d: %d\n", ++ts, (int)ceil(log2(n)));
    }
}
