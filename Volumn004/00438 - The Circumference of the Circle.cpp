#include <cstdio>
#include <cmath>
#define PI 3.141592653589793

int main() {
    double x1, x2, x3, y1, y2, y3;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        double a, b, c, d, e, f;
        a = x1 - x2; b = y1 - y2;
        c = x2 - x3; d = y2 - y3;
        e = x1*x1 - x2*x2 + y1*y1 - y2*y2;
        f = x2*x2 - x3*x3 + y2*y2 - y3*y3;

        double cx, cy, det;
        det = 4*(a*d - b*c);
        cx = 2*(e*d - b*f)/det;
        cy = 2*(a*f - c*e)/det;

        double r, dx, dy;
        dx = x1-cx;
        dy = y1-cy;
        r = sqrt(dx*dx + dy*dy);

        printf("%.2lf\n", PI*2.0*r);
    }
}
