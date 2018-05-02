#include <cstdio>
#include <cmath>
#define EPS 1e-7

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        printf("%.0lf\n", ceil(log2(n)+EPS));
    }
}
