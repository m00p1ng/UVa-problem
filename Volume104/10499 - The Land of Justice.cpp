#include <cstdio>

int main() {
    long long n;
    // sphere area = 4*pi*r^2
    // new surface when cut to new piece = n*(pi*r^2)
    // profit = n/4*100 = n*25 percent

    while(scanf("%lld", &n), n > 0) {
        if(n == 1) n = 0;
        printf("%lld%%\n", 25*n);
    }
}
