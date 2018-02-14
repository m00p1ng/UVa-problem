#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main() {
    double r, n;
    while(scanf("%lf %lf", &r, &n) == 2) {
        double deg = PI*2.0/n;
        double area = 0.5*n*r*r*sin(deg);
        printf("%.3lf\n", area);
    }
}
