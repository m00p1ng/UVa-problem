#include <cstdio>
#include <cmath>

int main() {
    int a, b;
    int sa, sb;
    while(scanf("%d %d", &a, &b), a || b) {
        sa = (int)ceil(sqrt(a));
        sb = (int)floor(sqrt(b));
        printf("%d\n", sb-sa+1);
    }
}
