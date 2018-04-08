#include <cstdio>

double abs(double a) {
    return a > 0 ? a : -a;
}

int main() {
    int h, m;
    double dh, dm, diff;

    while(scanf("%d:%d", &h, &m), h || m) {
        dm = 6*m;
        dh = 30.0*h + m/2.0;
        if(dh >= 360) dh -= 360;

        diff = abs(dh-dm);
        if(diff > 180) diff = 360 - diff;
        printf("%.3lf\n", diff);
    }
}

