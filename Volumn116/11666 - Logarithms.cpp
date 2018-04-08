#include <cstdio>
#include <cmath>

int main() {
    int n, l;
    double x1, x2, ln_n;
    while(scanf("%d", &n), n) {
        ln_n = log(n);
        l = ceil(ln_n);
        x1 = 1 - exp(ln_n - l);
        x2 = 1 - exp(ln_n - l + 1);

        if(fabs(x2) < 1) {
            x1 = x2;
            l = l - 1;
        }
        printf("%d %.8lf\n", l, x1);
    }
}
