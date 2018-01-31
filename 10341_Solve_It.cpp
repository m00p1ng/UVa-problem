#include <cstdio>
#include <cmath>
#define eps 1e-6
#define INF 1e6

int p, q, r, s, t, u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bin_search() {
    int rnd = 30;
    double mid, fm;
    double s = 0, e = 1;
    
    while(rnd--) {
        mid = (s+e)/2;
        fm = f(mid);
        if(fabs(fm) < eps) return mid;

        if(fm > 0) s = mid;
        else e = mid;
    }
    return INF;
}

int main() {
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
        double ans;
        double f0 = f(0), f1 = f(1);

        if((f0 > 0 && f1 > 0) || (f0 < 0 && f1 < 0)) ans = INF;
        else ans = bin_search();

        if(ans != INF) printf("%.4lf\n", ans);
        else puts("No solution");
    }
}
