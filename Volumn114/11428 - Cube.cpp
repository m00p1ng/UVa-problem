#include <cstdio>

double abs(double n) {
    return  n > 0 ? n : -n;
}

double f(double x, int y, int n) {
    return x*x*x - y - n;
}

double fdiff(double x) {
    return 3*x*x;
}

double newton(int n, int y) {
    int r = 1;
    double p0, p;
    p0 = y;

    while(r <= 22) {
        p = p0 - f(p0, y, n)/fdiff(p0);

        if(abs(p - p0) < 1) {
            return p;
        }

        r++;
        p0 = p;
    }
    return p;
}

void find_ans(int n) {
    int x, y_cube;
    bool found = false;

    for(int y = 1; y <= 60; y++) {
        y_cube = y*y*y;
        x = newton(n, y_cube);
        if(x*x*x - y_cube == n) {
            printf("%d %d\n", x, y);
            found = true;
            break;
        }
    }
    if(!found) puts("No solution");
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
        find_ans(n);
    }
}
