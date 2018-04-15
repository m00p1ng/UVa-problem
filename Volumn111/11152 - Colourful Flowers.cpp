#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) == 3) {
        double s, area_t, area_r, area_R, r, R;
        s = (a+b+c)/2.0;
        area_t = sqrt(s*(s-a)*(s-b)*(s-c));

        r = area_t / s;
        area_r = PI*r*r;

        R = a*b*c / (4.0*area_t);
        area_R = PI*R*R;
        printf("%.4lf %.4lf %.4lf\n", area_R-area_t, area_t-area_r, area_r);
    }
}
