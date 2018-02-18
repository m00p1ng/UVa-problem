#include <cstdio>
#include <cmath>

int main() {
    double l, w;
    double vmax, vmin;
    while(scanf("%lf %lf", &l, &w) == 2) {
        vmax = (l+w - sqrt((l+w)*(l+w) - 3*l*w))/6.0;
        vmin = fmin(l, w)/2.0 + 1e-7;
        printf("%.3lf 0.000 %.3lf\n", vmax, vmin);
    }
}
