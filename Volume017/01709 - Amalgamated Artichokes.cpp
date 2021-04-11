#include <cstdio>
#include <cmath>

double price(int p, int a, int b, int c, int d, int k) {
    return p*(sin(a*k + b) + cos(c*k + d) + 2);
}

int main() {
    int p, a, b, c, d, n;

    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6) {
        double max_num = -1e10;
        double max_diff = 0;

        for (int i = 1; i <= n; i++) {
            double val = price(p, a, b, c, d, i);
            double diff = max_num - val;

            if (diff > max_diff) {
                max_diff = diff;
            }
            if (val > max_num) {
                max_num = val;
            }
        }

        printf("%.6f\n", max_diff);
    }
}

