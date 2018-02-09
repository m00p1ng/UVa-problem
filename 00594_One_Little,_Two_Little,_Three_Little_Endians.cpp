#include <cstdio>

int main() {
    int n, out, m;
    while(scanf("%d", &n) == 1) {
        out = 0;
        m = n;
        for(int i = 0; i < 4; i++) {
            out = 256*out + (n & 255);
            n >>= 8;
        }
        printf("%d converts to %d\n", m, out);
    }
}
