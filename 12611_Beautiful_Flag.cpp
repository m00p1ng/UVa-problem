#include <cstdio>

int main() {
    int ts, r;
    double left, right, height;
    scanf("%d", &ts);

    for(int t = 1; t <= ts; t++) {
        scanf("%d", &r);
        left = -2.25*r;
        right = 2.75*r;
        height = 1.5*r;

        printf("Case %d:\n", t);
        printf("%.0lf %.0lf\n", left, height);
        printf("%.0lf %.0lf\n", right, height);
        printf("%.0lf %.0lf\n", right, -height);
        printf("%.0lf %.0lf\n", left, -height);
    }
}
