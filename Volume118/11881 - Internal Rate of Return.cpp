#include <cstdio>
#include <cmath>

int n;
double cf[20];

double f(double irr) {
    double ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += cf[i]/pow(1.0 + irr, i);
    }

    return ans;
}

double bisection() {
    int cnt = 0;
    double l = -1, h = 10000, mid, cur;

    while(cnt < 100) {
        cnt++;
        mid = (l+h)/2;
        cur = f(mid);

        if(cur < 0) {
            h = mid;
        } else {
            l = mid;
        }
    }
    return mid;
}

int main() {
    while(scanf("%d", &n), n) {
        for(int i = 0; i <= n; i++) {
            scanf("%lf", &cf[i]);
        }
        printf("%.2lf\n", bisection());
    }
}
