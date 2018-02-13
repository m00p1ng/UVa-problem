#include <cstdio>
#include <cmath>

int main() {
    int n, y, ts;
    scanf("%d", &ts);
    while(ts--) {
        scanf("%d", &n);
        int p = floor(-n*log10(2));
        printf("2^-%d = %.3lfE-%d\n", n, pow(10, -n*log10(2)-p), -p);
    }
}
